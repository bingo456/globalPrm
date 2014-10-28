#include <exception>
#include "GdalOpr.h"
//#include "gdal.h"
//#include "gdal_priv.h"
//#include "ogr_spatialref.h"

using namespace std;
/**
*@brief 构造函数加载驱动
*/
GdalOpr::GdalOpr(void)
{
    GDALAllRegister();
    CPLSetConfigOption("GDAL_FILENAME_IS_UTF8","NO");
}

GdalOpr::~GdalOpr(void)
{
}
//********************************************************************************//
//                        图像基本操作                                            //
//            功能包括：打开（只读，写入）；获得波段数，长宽；创建；删除          //
//********************************************************************************//
/**
*@brief获得原始图像的数据集（只读）
*@param inpath [in] 输入路径
*@return
*/
GDALDataset *GdalOpr::OpenDatasetR(const char *inpath)
{
    GDALDataset *poDataset;
    poDataset = (GDALDataset *)GDALOpen(inpath,GA_ReadOnly);
    if (poDataset == NULL)
    {
        cout<<"Open failed"<<inpath<<endl;
        exit(0);

    }
    else
    {
        return poDataset;

    }
}
/**
*@brief获得原始图像的数据集（可以写入）
*@param inpath [in] 输入路径
*@return
*/
GDALDataset *GdalOpr::OpenDatasetW(const char *inpath)
{
    GDALDataset *poDataset;
    poDataset = (GDALDataset *)GDALOpen(inpath,GA_Update);
    if (poDataset == NULL)
    {
        cout<<"Open failed:"<<inpath<<endl;
        exit(0);

    }
    else
    {
        return poDataset;

    }

}
/**
*@brief 获得波段数
*@param poDataset [in] gdal数据集
*@return 波段大小
*/
int GdalOpr::GetBandCount(GDALDataset *poDataset)
{
    if (poDataset != NULL)
    {
        return poDataset->GetRasterCount();

    }
    return 0;
}
/**
*@brief 获得栅格数据宽
*@param poDataset [in] gdal数据集
*@return
*/
int GdalOpr::GetWidth(GDALDataset *poDataset)
{
    if (poDataset != NULL)
    {
        return poDataset->GetRasterXSize();
    }
    return 0;
}
/**
*@brief 获得栅格数据高
*@param poDataset [in] gdal数据集
*@return
*/
int GdalOpr::GetHeight(GDALDataset *poDataset)
{
    if (poDataset != NULL)
    {
        return poDataset->GetRasterYSize();
    }
    return 0;
}
/**
*@brief 读取图像数据集(byte)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@return width(int)
*/
bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,byte_t *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,0,0,x,y,datas,x,y,GDT_Byte,0,0);
    if (datas != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(unsigned short)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@return width(int)
*/
bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,0,0,x,y,datas,x,y,GDT_UInt16,0,0);
    if (datas != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(short)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@return width(int)
*/
bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,short *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,0,0,x,y,datas,x,y,GDT_Int16,0,0);
    if (datas != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(unsigned int)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@return width(int)
*/
bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,0,0,x,y,datas,x,y,GDT_UInt32,0,0);
    if (datas != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(int)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@return width(int)
*/
bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,int *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,0,0,x,y,datas,x,y,GDT_Int32,0,0);
    if (datas != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(float)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@return width(int)
*/

bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,float *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,0,0,x,y,datas,x,y,GDT_Float32,0,0);
    if (datas != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }


}
/**
*@brief 读取图像数据集(double)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@return width(int)
*/
bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,double *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,0,0,x,y,datas,x,y,GDT_Float64,0,0);
    if (datas != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }


}
/**
*@brief 写入图像数据集(byte)
*@param poDataset [in] gdal数据集
*@param nb [in] 波段
*@param datas [in] 写入数据
*@return width(int)
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,byte_t *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,0,0,x,y,datas,x,y,GDT_Byte,0,0);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }
}
/**
*@brief 写入图像数据集(unsigned short)
*@param poDataset [in] gdal数据集
*@param nb [in] 波段
*@param datas [in] 写入数据
*@return width(int)
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,0,0,x,y,datas,x,y,GDT_UInt16,0,0);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(short)
*@param poDataset [in] gdal数据集
*@param nb [in] 波段
*@param datas [in] 写入数据
*@return width(int)
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,short *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,0,0,x,y,datas,x,y,GDT_Int16,0,0);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(unsigned int)
*@param poDataset [in] gdal数据集
*@param nb [in] 波段
*@param datas [in] 写入数据
*@return width(int)
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,0,0,x,y,datas,x,y,GDT_UInt32,0,0);
        GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(int)
*@param poDataset [in] gdal数据集
*@param nb [in] 波段
*@param datas [in] 写入数据
*@return width(int)
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,int *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,0,0,x,y,datas,x,y,GDT_Int32,0,0);
        GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(float)
*@param poDataset [in] gdal数据集
*@param nb [in] 波段
*@param datas [in] 写入数据
*@return width(int)
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,float *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,0,0,x,y,datas,x,y,GDT_Float32,0,0);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(double)
*@param poDataset [in] gdal数据集
*@param nb [in] 波段
*@param datas [in] 写入数据
*@return width(int)
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,double *datas)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,0,0,x,y,datas,x,y,GDT_Float64,0,0);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief gdal关闭dataset
*@param poDataset [in] gdal数据集
*@return 无返回值
*/
void GdalOpr::DatasetClose(GDALDataset *poDataset)
{
    if (poDataset != NULL)
    {
        GDALClose((GDALDatasetH)poDataset);
    }
}
/**
*@brief 创建tif图像
*@param outpath [in] tif文件路径
*@param eType [in] gdal数据类型
*@param wkt [in] wkt字符串
*@param adfGeoTransform [in] 坐标转换信息
*@param xSize [in] x轴数据大小
*@param ySize [in] y轴数据大小
*@param eType [in] gdal数据类型
*@param bandCount [in] 波段数
*@return true创建tiff成功；false创建tiff失败
*/
bool GdalOpr::CreateTiff(const char *outpath,GDALDataType eType,const char *wkt,double *adfGeoTransform,int xSize,int ySize,int bandCount)
{
    const char *pszFormat = "GTiff";
    GDALDriver *poDriver;
    poDriver = GetGDALDriverManager()->GetDriverByName(pszFormat);
    if (poDriver == NULL)
    {
        exit(1);
    }

    GDALDataset *poDstDS;
    char **papszOptions = NULL;
    poDstDS = poDriver->Create(outpath,xSize,ySize,bandCount,eType,papszOptions);
    if (poDstDS == NULL)
    {
        return false;
    }
    poDstDS->SetProjection(wkt);
    poDstDS->SetGeoTransform(adfGeoTransform);
    GDALClose(poDstDS);
    return true;

}
/**
*@brief 创建tif图像（没有投影，坐标转换系数0,1,0,0,0,1）
*@param outpath [in] tif文件路径
*@param eType [in] gdal数据类型
*@param xSize [in] x轴数据大小
*@param ySize [in] y轴数据大小
*@param eType [in] gdal数据类型
*@param bandCount [in] 波段数
*@return true创建tiff成功；false创建tiff失败
*/
bool GdalOpr::CreateTiff(const char *outpath,GDALDataType eType,int xSize,int ySize,int bandCount)
{
    const char *pszFormat = "GTiff";
    GDALDriver *poDriver;
    poDriver = GetGDALDriverManager()->GetDriverByName(pszFormat);
    if (poDriver == NULL)
    {
        exit(1);
    }
    GDALDataset *poDstDS;
    char **papszOptions = NULL;
    poDstDS = poDriver->Create(outpath,xSize,ySize,bandCount,eType,papszOptions);
    if (poDstDS == NULL)
    {
        return false;
    }
    else
    {
        GDALClose(poDstDS);
    }
    return true;
}
/**
*@brief 删除tif图像
*@param outpath [in] tif文件路径
*@return true删除tiff成功；false删除tiff失败
*/
bool GdalOpr::DeleteTiff(const char *outpath)
{
    const char *pszFormat = "Giff";
    GDALDriver *poDriver;
    poDriver = GetGDALDriverManager()->GetDriverByName(pszFormat);
    if (poDriver == NULL)
    {
        return false;
    }
    poDriver->Delete(outpath);
    return true;
}

//********************************************************************************//
//                        图像裁剪                                                //
//            支持的格式（byte;short;int;float;double）                           //
//********************************************************************************//
/**
*@brief 获得裁剪图片的宽
*@param adfGeoTransform [in] 坐标转换信息
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@return width(int)
*/
int GdalOpr::GetNewWidth(double *adfGeoTransform,double *xyPeak)
{
    double xl = (adfGeoTransform[5] * (xyPeak[0] - adfGeoTransform[0]) - adfGeoTransform[2] * (xyPeak[1] - adfGeoTransform[3])) / (adfGeoTransform[1] * adfGeoTransform[5] - adfGeoTransform[4] * adfGeoTransform[2]);
    double xr = (adfGeoTransform[5] * (xyPeak[2] - adfGeoTransform[0]) - adfGeoTransform[2] * (xyPeak[3] - adfGeoTransform[3])) / (adfGeoTransform[1] * adfGeoTransform[5] - adfGeoTransform[4] * adfGeoTransform[2]);
    return abs(xr - xl);
}
/**
*@brief 获得裁剪图片的高
*@param adfGeoTransform [in] 坐标转换信息
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@return width(int)
*/
int GdalOpr::GetNewHeight(double *adfGeoTransform,double *xyPeak)
{
    double yl = (adfGeoTransform[4] * (xyPeak[0] - adfGeoTransform[0]) - adfGeoTransform[1] * (xyPeak[1] - adfGeoTransform[3])) / (adfGeoTransform[4] * adfGeoTransform[2] - adfGeoTransform[1] * adfGeoTransform[5]);
    double yr = (adfGeoTransform[4] * (xyPeak[2] - adfGeoTransform[0]) - adfGeoTransform[1] * (xyPeak[3] - adfGeoTransform[3])) / (adfGeoTransform[4] * adfGeoTransform[2] - adfGeoTransform[1] * adfGeoTransform[5]);
    return abs(yr - yl);
}
/**
*@brief 获得裁剪图像数据集(byte)
*@param poDataset [in] gdal数据集
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@param band [in] 波段数
*@param typeParam [in] 类型重载变量
*@return width(int)
*/
byte_t *GdalOpr::GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,byte_t typeParam)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    poDataset->GetGeoTransform(adfGeoTransform);
    byte_t *oldatas = (byte_t *)CPLMalloc(sizeof(byte_t) * x *y);
    GDALRasterBand *grb = poDataset->GetRasterBand(band);
    grb->RasterIO(GF_Read,0,0,x,y,oldatas,x,y,GDT_Byte,0,0);

    int nx = GetNewWidth(adfGeoTransform,xyPeak);
    int ny = GetNewHeight(adfGeoTransform,xyPeak);
    byte_t *newdatas = (byte_t *)CPLMalloc(sizeof(byte_t) * nx * ny);
    int temp = 0;
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            double xp = adfGeoTransform[0] + i * adfGeoTransform[1] + j * adfGeoTransform[2];
            double yp = adfGeoTransform[3] + i * adfGeoTransform[4] + j * adfGeoTransform[5];

            if ((xp <= xyPeak[2] && xp >= xyPeak[0]) && (yp <= xyPeak[1] && yp >= xyPeak[3]))
            {
                //li.Add(redou[j * x + i]);
                newdatas[temp] = oldatas[j * x + i];

            }
        }
    }
    CPLFree(adfGeoTransform);
    CPLFree(oldatas);
    return newdatas;
}
/**
*@brief 获得裁剪图像数据集(short)
*@param poDataset [in] gdal数据集
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@param band [in] 波段数
*@param typeParam [in] 类型重载变量
*@return width(int)
*/
short *GdalOpr::GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,short typeParam)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    poDataset->GetGeoTransform(adfGeoTransform);
    short *oldatas = (short *)CPLMalloc(sizeof(short) * x *y);
    GDALRasterBand *grb = poDataset->GetRasterBand(band);
    grb->RasterIO(GF_Read,0,0,x,y,oldatas,x,y,GDT_Int16,0,0);

    int nx = GetNewWidth(adfGeoTransform,xyPeak);
    int ny = GetNewHeight(adfGeoTransform,xyPeak);
    short *newdatas = (short *)CPLMalloc(sizeof(short) * nx * ny);
    int temp = 0;
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            double xp = adfGeoTransform[0] + i * adfGeoTransform[1] + j * adfGeoTransform[2];
            double yp = adfGeoTransform[3] + i * adfGeoTransform[4] + j * adfGeoTransform[5];

            if ((xp <= xyPeak[2] && xp >= xyPeak[0]) && (yp <= xyPeak[1] && yp >= xyPeak[3]))
            {
                //li.Add(redou[j * x + i]);
                newdatas[temp] = oldatas[j * x + i];

            }
        }
    }
    CPLFree(adfGeoTransform);
    CPLFree(oldatas);
    return newdatas;
}
/**
*@brief 获得裁剪图像数据集(int)
*@param poDataset [in] gdal数据集
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@param band [in] 波段数
*@param typeParam [in] 类型重载变量
*@return width(int)
*/
int *GdalOpr::GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,int typeParam)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    poDataset->GetGeoTransform(adfGeoTransform);
    int *oldatas = (int *)CPLMalloc(sizeof(int) * x *y);
    GDALRasterBand *grb = poDataset->GetRasterBand(band);
    grb->RasterIO(GF_Read,0,0,x,y,oldatas,x,y,GDT_Int32,0,0);

    int nx = GetNewWidth(adfGeoTransform,xyPeak);
    int ny = GetNewHeight(adfGeoTransform,xyPeak);
    int *newdatas = (int *)CPLMalloc(sizeof(int) * nx * ny);
    int temp = 0;
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            double xp = adfGeoTransform[0] + i * adfGeoTransform[1] + j * adfGeoTransform[2];
            double yp = adfGeoTransform[3] + i * adfGeoTransform[4] + j * adfGeoTransform[5];

            if ((xp <= xyPeak[2] && xp >= xyPeak[0]) && (yp <= xyPeak[1] && yp >= xyPeak[3]))
            {
                //li.Add(redou[j * x + i]);
                newdatas[temp] = oldatas[j * x + i];

            }
        }
    }
    CPLFree(adfGeoTransform);
    CPLFree(oldatas);
    return newdatas;
}
/**
*@brief 获得裁剪图像数据集(float)
*@param poDataset [in] gdal数据集
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@param band [in] 波段数
*@param typeParam [in] 类型重载变量
*@return width(int)
*/
float *GdalOpr::GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,float typeParam)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    poDataset->GetGeoTransform(adfGeoTransform);
    float *oldatas = (float *)CPLMalloc(sizeof(float) * x *y);
    GDALRasterBand *grb = poDataset->GetRasterBand(band);
    grb->RasterIO(GF_Read,0,0,x,y,oldatas,x,y,GDT_Float32,0,0);

    int nx = GetNewWidth(adfGeoTransform,xyPeak);
    int ny = GetNewHeight(adfGeoTransform,xyPeak);
    float *newdatas = (float *)CPLMalloc(sizeof(float) * nx * ny);
    int temp = 0;
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            double xp = adfGeoTransform[0] + i * adfGeoTransform[1] + j * adfGeoTransform[2];
            double yp = adfGeoTransform[3] + i * adfGeoTransform[4] + j * adfGeoTransform[5];

            if ((xp <= xyPeak[2] && xp >= xyPeak[0]) && (yp <= xyPeak[1] && yp >= xyPeak[3]))
            {
                //li.Add(redou[j * x + i]);
                newdatas[temp] = oldatas[j * x + i];

            }
        }
    }
    CPLFree(adfGeoTransform);
    CPLFree(oldatas);
    return newdatas;
}
/**
*@brief 获得裁剪图像数据集(double)
*@param poDataset [in] gdal数据集
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@param band [in] 波段数
*@return width(int)
*/
double *GdalOpr::GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,double typeParam)
{
    int x = GetWidth(poDataset);
    int y = GetHeight(poDataset);
    double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    poDataset->GetGeoTransform(adfGeoTransform);
    double *oldatas = (double *)CPLMalloc(sizeof(double) * x *y);
    GDALRasterBand *grb = poDataset->GetRasterBand(band);
    grb->RasterIO(GF_Read,0,0,x,y,oldatas,x,y,GDT_Float64,0,0);

    int nx = GetNewWidth(adfGeoTransform,xyPeak);
    int ny = GetNewHeight(adfGeoTransform,xyPeak);
    double *newdatas = (double *)CPLMalloc(sizeof(double) * nx * ny);
    int temp = 0;
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            double xp = adfGeoTransform[0] + i * adfGeoTransform[1] + j * adfGeoTransform[2];
            double yp = adfGeoTransform[3] + i * adfGeoTransform[4] + j * adfGeoTransform[5];

            if ((xp <= xyPeak[2] && xp >= xyPeak[0]) && (yp <= xyPeak[1] && yp >= xyPeak[3]))
            {
                //li.Add(redou[j * x + i]);
                newdatas[temp] = oldatas[j * x + i];

            }
        }
    }
    CPLFree(adfGeoTransform);
    CPLFree(oldatas);
    return newdatas;
}
//********************************************************************************//
//                        获得某一点经纬度                                        //
//                        经纬度与图像点间的转换                                 //
//********************************************************************************//
/**
*@brief 获得经度坐标值
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
double GdalOpr::GetLonOfPoint(double *adfGeoTransform,int xPoint,int yPoint)
{
    if (adfGeoTransform != NULL)
    {
        return adfGeoTransform[0] + xPoint * adfGeoTransform[1] + yPoint * adfGeoTransform[2];
    }
    return 0.0;
}
/**
*@brief 获得经度坐标值
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
double GdalOpr::GetLatOfPoint(double *adfGeoTransform,int xPoint,int yPoint)
{
    if (adfGeoTransform != NULL)
    {
        return adfGeoTransform[3] + xPoint * adfGeoTransform[4] + yPoint * adfGeoTransform[5];
    }
    return 0.0;
}

/**
*@brief 获得X坐标值
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
int GdalOpr::GetPointXOfLonLat( double *adfGeoTransform, double lon, double lat )
{
    if (adfGeoTransform != NULL)
    {
        if (!adfGeoTransform[5])
        {
            return (int)((lat -adfGeoTransform[3])/adfGeoTransform[4]);

        }
        else
        {
            double date_up = lon -adfGeoTransform[0] - (lat -adfGeoTransform[3])*adfGeoTransform[2]/adfGeoTransform[5];
            double date_down = adfGeoTransform[1] - adfGeoTransform[2]*adfGeoTransform[4]/adfGeoTransform[5];
            return (int)(date_up/date_down);
        }
    }
    return 0;

}
/**
*@brief 获得Y坐标值
*@param adfGeoTransform [in] 坐标转换信息
*@param lat [in] 纬度
*@param lon [in] 经度
*@return 经度值
*/
int GdalOpr::GetPointYOfLonLat(double *adfGeoTransform, double lon, double lat)
{
    if (adfGeoTransform != NULL)
    {
        if (!adfGeoTransform[4])
        {
            return (int)((lat-adfGeoTransform[3])/adfGeoTransform[5]);
        }
        else
        {
            double date_up = lon -adfGeoTransform[0] - (lat -adfGeoTransform[3])*adfGeoTransform[1]/adfGeoTransform[4];
            double date_down = adfGeoTransform[2] - adfGeoTransform[1]*adfGeoTransform[5]/adfGeoTransform[4];
            return (int)(date_up/date_down);
        }
    }
    return 0;
}
//********************************************************************************//
//                        简单线性重采样（gdal原始库包含）                        //
//            支持的格式（byte;short;int;float;double）                           //
//********************************************************************************//
/**
*@brief 简单线性重采样(byte)
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
void GdalOpr::SimpleLinearResample(GDALDataset *poDataset,byte_t *gDatas,int x,int y,const char *outPath)
{
    int bands = GetBandCount(poDataset);
    int ox = GetWidth(poDataset);
    int oy = GetHeight(poDataset);
    vector<byte_t *> ve;

    for (int i = 1; i <= bands; i++)
    {
        GDALRasterBand *poBand;
        //定义采样后数据集
        byte_t *newDatas = (byte_t *)CPLMalloc(sizeof(byte_t) * x * y);
        poBand = poDataset->GetRasterBand(i);
        poBand->RasterIO(GF_Read,0,0,ox,oy,newDatas,x,y,GDT_Byte,0,0);
        ve.push_back(newDatas);

    }
    DatasetClose(poDataset);
    CreateTiff(outPath,GDT_Byte,x,y,bands);
    GDALDataset *poDataset2 = OpenDatasetW(outPath);
    for(int j = 0; j < bands; j++)
    {
        WriteBandDatas(poDataset2,(j + 1),ve[j]);
    }
    DatasetClose(poDataset2);
}
/**
*@brief 简单线性重采样(short)
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
void GdalOpr::SimpleLinearResample(GDALDataset *poDataset,short *gDatas,int x,int y,const char *outPath)
{
    int bands = GetBandCount(poDataset);
    int ox = GetWidth(poDataset);
    int oy = GetHeight(poDataset);
    vector<short *> ve;

    for (int i = 1; i <= bands; i++)
    {
        GDALRasterBand *poBand;
        //定义采样后数据集
        short *newDatas = (short *)CPLMalloc(sizeof(short) * x * y);
        poBand = poDataset->GetRasterBand(i);
        poBand->RasterIO(GF_Read,0,0,ox,oy,newDatas,x,y,GDT_Int16,0,0);
        ve.push_back(newDatas);

    }
    DatasetClose(poDataset);
    CreateTiff(outPath,GDT_Int16,x,y,bands);
    GDALDataset *poDataset2 = OpenDatasetW(outPath);
    for(int j = 0; j < bands; j++)
    {
        WriteBandDatas(poDataset2,(j + 1),ve[j]);
    }
    DatasetClose(poDataset2);
}
/**
*@brief 简单线性重采样(int)
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
void GdalOpr::SimpleLinearResample(GDALDataset *poDataset,int *gDatas,int x,int y,const char *outPath)
{
    int bands = GetBandCount(poDataset);
    int ox = GetWidth(poDataset);
    int oy = GetHeight(poDataset);
    vector<int *> ve;

    for (int i = 1; i <= bands; i++)
    {
        GDALRasterBand *poBand;
        //定义采样后数据集
        int *newDatas = (int *)CPLMalloc(sizeof(int) * x * y);
        poBand = poDataset->GetRasterBand(i);
        poBand->RasterIO(GF_Read,0,0,ox,oy,newDatas,x,y,GDT_Int32,0,0);
        ve.push_back(newDatas);

    }
    DatasetClose(poDataset);
    CreateTiff(outPath,GDT_Int32,x,y,bands);
    GDALDataset *poDataset2 = OpenDatasetW(outPath);
    for(int j = 0; j < bands; j++)
    {
        WriteBandDatas(poDataset2,(j + 1),ve[j]);
    }
    DatasetClose(poDataset2);
}
/**
*@brief 简单线性重采样(float)
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
void GdalOpr::SimpleLinearResample(GDALDataset *poDataset,float *gDatas,int x,int y,const char *outPath)
{
    int bands = GetBandCount(poDataset);
    int ox = GetWidth(poDataset);
    int oy = GetHeight(poDataset);
    vector<float *> ve;

    for (int i = 1; i <= bands; i++)
    {
        GDALRasterBand *poBand;
        //定义采样后数据集
        float *newDatas = (float *)CPLMalloc(sizeof(float) * x * y);
        poBand = poDataset->GetRasterBand(i);
        poBand->RasterIO(GF_Read,0,0,ox,oy,newDatas,x,y,GDT_Float32,0,0);
        ve.push_back(newDatas);

    }
    DatasetClose(poDataset);
    CreateTiff(outPath,GDT_Float32,x,y,bands);
    GDALDataset *poDataset2 = OpenDatasetW(outPath);
    for(int j = 0; j < bands; j++)
    {
        WriteBandDatas(poDataset2,(j + 1),ve[j]);
    }
    DatasetClose(poDataset2);
}
/**
*@brief 简单线性重采样(double)
*@param adfGeoTransform [in] 坐标转换信息
*@param xPiont [in] x点的位置
*@param yPiont [in] y点的位置
*@return 经度值
*/
void GdalOpr::SimpleLinearResample(GDALDataset *poDataset,double *gDatas,int x,int y,const char *outPath)
{
    int bands = GetBandCount(poDataset);
    int ox = GetWidth(poDataset);
    int oy = GetHeight(poDataset);
    vector<double *> ve;

    for (int i = 1; i <= bands; i++)
    {
        GDALRasterBand *poBand;
        //定义采样后数据集
        double *newDatas = (double *)CPLMalloc(sizeof(double) * x * y);
        poBand = poDataset->GetRasterBand(i);
        poBand->RasterIO(GF_Read,0,0,ox,oy,newDatas,x,y,GDT_Float64,0,0);
        ve.push_back(newDatas);

    }
    DatasetClose(poDataset);
    CreateTiff(outPath,GDT_Float64,x,y,bands);
    GDALDataset *poDataset2 = OpenDatasetW(outPath);
    for(int j = 0; j < bands; j++)
    {
        WriteBandDatas(poDataset2,(j + 1),ve[j]);
    }
    DatasetClose(poDataset2);
}
/************************************************************************/
/*                     指定区域的数据读取                          */
/************************************************************************/
/**
*@brief 读取图像数据集(byte)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,byte_t *datas,
                              int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,offx,offy,pafsizex,pafsizey,datas,
                     pafsizex,pafsizey,GDT_Byte,0,0);
    GDALClose(poBand);
    if (datas != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(unsigned short)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas,
                              int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,offx,offy,pafsizex,pafsizey,datas,
                     pafsizex,pafsizey,GDT_UInt16,0,0);
    GDALClose(poBand);
    if (datas != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(short)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,short *datas,
                              int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,offx,offy,pafsizex,pafsizey,datas,
                     pafsizex,pafsizey,GDT_Int16,0,0);
    GDALClose(poBand);
    if (datas != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(unsigned int)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas,
                              int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,offx,offy,pafsizex,pafsizey,datas,
                     pafsizex,pafsizey,GDT_UInt32,0,0);
    GDALClose(poBand);
    if (datas != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(int)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,int *datas,
                              int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,offx,offy,pafsizex,pafsizey,datas,
                     pafsizex,pafsizey,GDT_Int32,0,0);
    GDALClose(poBand);
    if (datas != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}


/**
*@brief 读取图像数据集(float)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,float *datas,
                              int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,offx,offy,pafsizex,pafsizey,datas,
                     pafsizex,pafsizey,GDT_Float32,0,0);
    GDALClose(poBand);
    if (datas != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}
/**
*@brief 读取图像数据集(double)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/
bool GdalOpr::ReadBandDatas(GDALDataset *poDataset,int nb,double *datas,
                            int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    poBand = poDataset->GetRasterBand(nb);
    poBand->RasterIO(GF_Read,offx,offy,pafsizex,pafsizey,datas,
                     pafsizex,pafsizey,GDT_Float64,0,0);
    GDALClose(poBand);
    if (datas != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}
/************************************************************************/
/*                     指定区域的数据存储                           */
/************************************************************************/
/**
*@brief 写入图像数据集(byte)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param offx,offy [in] 数据的起始点(左上角)
*@param pafsizex,pafsizey [in] 数据的终止点行列大小
*@return
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,byte_t *datas,
                             int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,offx,offy,pafsizex,pafsizey,datas,
                         pafsizex,pafsizey,GDT_Byte,0,0);
        // GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(unsigned short)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas,
                             int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,offx,offy,pafsizex,pafsizey,datas,
                         pafsizex,pafsizey,GDT_UInt16,0,0);
        // GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(short)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,short *datas,
                             int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,offx,offy,pafsizex,pafsizey,datas,
                         pafsizex,pafsizey,GDT_Int16,0,0);
        //GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(unsigned int)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas,
                             int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,offx,offy,pafsizex,pafsizey,datas,
                         pafsizex,pafsizey,GDT_UInt32,0,0);
        //GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(int)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,int *datas,
                             int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,offx,offy,pafsizex,pafsizey,datas,
                         pafsizex,pafsizey,GDT_Int32,0,0);
        //GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}

/**
*@brief 写入图像数据集(float)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,float *datas,
                             int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,offx,offy,pafsizex,pafsizey,datas,
                         pafsizex,pafsizey,GDT_Float32,0,0);
        //GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}
/**
*@brief 写入图像数据集(double)
*@param poDataset [in] gdal数据集
*@param band [in] 波段
*@param x_strat,y_strat [in] 数据的起始点(左上角)
*@param x_end,y_end [in] 数据的终止点（右下角）
*@return
*/
bool GdalOpr::WriteBandDatas(GDALDataset *poDataset,int nb,double *datas,
                             int offx, int offy, int pafsizex, int pafsizey )
{
    GDALRasterBand *poBand;
    try
    {
        poBand = poDataset->GetRasterBand(nb);
        poBand->RasterIO(GF_Write,offx,offy,pafsizex,pafsizey,datas,
                         pafsizex,pafsizey,GDT_Float64,0,0);
        //GDALClose(poBand);
        return true;
    }
    catch (exception *e)
    {
        return false;
    }

}

