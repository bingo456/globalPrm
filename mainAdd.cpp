#include "gdal.h"
#include "gdal_priv.h"
#include "GdalProjection.h"
#include "file.h"
#define SIZE 1024
#define CHUNK_HEIGH 3600
int main(int argc,char* argv[])
{
    GDALAllRegister();
  //  const char* inputfile = "/media/新加卷/global/DEM_global.dat";
//    const char* outputImg = "/media/新加卷/global/NDVI_global.tif";
//    const char* filePath = "/media/新加卷/global/NDVI/";
    const char* inputfile = argv[1];
    const char* outputImg = argv[2];
    const char* filePath = argv[3];
    File getfile;
    vector<string> fileListName = getfile.GetFiles(filePath,".tif");
    vector<string> fileList;
    for(int n = 0; n < fileListName.size(); n++)
    {
        fileList.push_back(filePath+fileListName[n]);
    }

    GDALDataset *poDatasetBand1;
    poDatasetBand1 = (GDALDataset *) GDALOpen(fileList[0].c_str(), GA_ReadOnly );
    if(( poDatasetBand1 == NULL ))
    {
        printf("文件打开失败");
    }
    //投影信息
    char projectionRaw[SIZE];
    memset(projectionRaw, '\0', SIZE*sizeof(char));
    strcpy(projectionRaw, poDatasetBand1->GetProjectionRef());
    //输入图像原始尺寸
    int nXSizeRaw=poDatasetBand1->GetRasterXSize();
    int nYSizeRaw=poDatasetBand1->GetRasterYSize();
    GDALClose(poDatasetBand1);
    GDALDataset* poDatasetBand =  (GDALDataset *) GDALOpen(inputfile,GA_ReadOnly);
    double adfGeoTransform[6];
    poDatasetBand->GetGeoTransform(adfGeoTransform);
    char projection[1024];
    memset(projection, '\0', 1024*sizeof(char));
    strcpy(projection, poDatasetBand->GetProjectionRef());
//    adfGeoTransform[1] = 0.01;
//    adfGeoTransform[5] = -0.01;
    int nXSize = 7200;
    int nYSize   = 3600;

    GDALDataset *poOutDataset = (GDALDataset *) GDALOpen(outputImg,GA_Update);;

    //poOutDataset = poDriver->Create(outputImg,nXSize,nYSize,1,GDT_Int16,papszMetadata);
    GDALRasterBand* pRasterOut = poOutDataset->GetRasterBand(1);

    int offx = 0;
    int offy = 0;
    int pafsizeX = nXSize;
    int pafsizeY = CHUNK_HEIGH;
    int num = (nYSize -1)/CHUNK_HEIGH +1;
    for(int k = 0; k < num; k++)
    {
        offy = k*CHUNK_HEIGH;
        if(k == (num-1))
        {
            pafsizeY = (nYSize -1)%CHUNK_HEIGH +1;
        }

        short* Data = new short[pafsizeX*pafsizeY];
        pRasterOut->RasterIO(GF_Read,offx,offy,pafsizeX,pafsizeY,Data,pafsizeX,pafsizeY,GDT_Int16,0,0);
        double* lon = new double[pafsizeX*pafsizeY];
        double* lat = new double[pafsizeX*pafsizeY];
        GdalOpr* gdal = new GdalOpr();
        for(int i = 0; i < pafsizeY; i++)
        {
            for(int j = 0; j < pafsizeX; j++)
            {
                lat[i*pafsizeX+j] = gdal->GetLatOfPoint(adfGeoTransform,j,offy+i);
                lon[i*pafsizeX+j] = gdal->GetLonOfPoint(adfGeoTransform,j,offy+i);
                //Data[pafsizeX*i+j] = 0;
            }
        }
        GdalProjection change;
        vector<double*> dataLat = change.ArrayToArray(projection,projectionRaw,lon,lat,pafsizeX*pafsizeY);
        for(int n = 0; n < fileList.size(); n++)
        {
            cout<<n<<"/"<<fileList.size()<<endl;
            GDALDataset *poDatasetBand2;
            poDatasetBand2 = (GDALDataset *) GDALOpen(fileList[n].c_str(), GA_ReadOnly );
            if(( poDatasetBand2 == NULL ))
            {
                printf("文件打开失败");
                continue;
            }
            //6个坐标参数
            double oriadfGeoTransform[6];
            poDatasetBand2->GetGeoTransform(oriadfGeoTransform);
            oriadfGeoTransform[5] = -926.625433;
            GDALRasterBand* pRasterData = poDatasetBand2->GetRasterBand(1);
            short* dataBase = new short[1200*1200];
            pRasterData->RasterIO(GF_Read,0,0,nXSizeRaw,nYSizeRaw,dataBase,nXSizeRaw,nYSizeRaw,GDT_Int16,0,0);

            for(int i = 0; i< pafsizeY; i ++)
            {
                for(int j =0; j < pafsizeX; j ++)
                {
                    double lon1 = dataLat[0][i*pafsizeX+j];
                    double lat1 = dataLat[1][i*pafsizeX+j];
                    int x = gdal->GetPointXOfLonLat(oriadfGeoTransform,lon1,lat1);
                    int y = gdal->GetPointYOfLonLat(oriadfGeoTransform,lon1,lat1);
                    if( Data[pafsizeX*i+j] != 0 )
                    {
                        continue;
                    }
                    if( (x >= 0) && (y >= 0)&& (x < nXSizeRaw) && (y < nYSizeRaw) )
                    {
                        if( dataBase[y*nXSizeRaw+x] != 0)
                        {
                            Data[i*pafsizeX+j] = dataBase[y*nXSizeRaw+x];
                        }

                    }
                }
            }

            delete[] dataBase;
            GDALClose(poDatasetBand2);
        }
        pRasterOut->RasterIO(GF_Write,offx,offy,pafsizeX,pafsizeY,Data,pafsizeX,pafsizeY,GDT_Int16,0,0);
        delete[] Data;
        delete[] lat;
        delete[] lon;
        delete gdal;
    }

    poOutDataset->SetProjection(projection);
    poOutDataset->SetGeoTransform(adfGeoTransform);
    GDALClose(poOutDataset);

    return 0;
}

