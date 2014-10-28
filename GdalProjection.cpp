#include "gdal.h"
#include "gdal_priv.h"
#include "GdalProjection.h"
#include "ogr_spatialref.h"
#include "gdalwarper.h"
#include<vector>
#include <iostream>
using namespace std;

GdalProjection::GdalProjection(void)
{
}

GdalProjection::~GdalProjection(void)
{
}
/**
*@brief 点对点的转换
*@param poDataset [in] gdal数据集
*@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
*@param band [in] 波段数
*@param typeParam [in] 类型重载变量
*@return
*/
double *GdalProjection::PointToPoint(const char *fromWkt,const char *toWkt,double x,double y)
{
    OGRSpatialReference oSourceSRS,oTargetSRS;
    OGRCoordinateTransformation *poct;

    oSourceSRS.importFromWkt((char **) &fromWkt);
    oTargetSRS.importFromWkt((char **) &toWkt);

    poct = OGRCreateCoordinateTransformation(&oSourceSRS,&oTargetSRS);
    double *xy = (double *)malloc(sizeof(double) * 2);
    if (poct == NULL || !poct->Transform(1,&x,&y))
    {
        xy[0] = 0.0;
        xy[1] = 0.0;
    }
    else
    {
        xy[0] = x;
        xy[1] = y;
    }
    delete poct;
    return xy;
}
/**
*@brief 点对点的转换
*@param tifPath [in] tif图片路径
*@param toWkt [in] 目标点的wkt字符串
*@param x [in] x点经度
*@param y [in] y点纬度
*@return 转换后的经纬度坐标
*/
double *GdalProjection::PointToPoint(const char *tifPath,const char *toWkt,int x,int y)
{
    GDALDataset *poDataset = gbase.OpenDatasetR(tifPath);
    const char *fromWkt = poDataset->GetProjectionRef();
    double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    poDataset->GetGeoTransform(adfGeoTransform);
    double nx = gbase.GetLonOfPoint(adfGeoTransform,x,y);
    double ny = gbase.GetLatOfPoint(adfGeoTransform,x,y);
    double *ptop = PointToPoint(fromWkt,toWkt,nx,ny);
    GDALClose(poDataset);
    CPLFree(adfGeoTransform);
    return ptop;
}
/**
*@brief 数组对数组的转换
*@param fromWkt [in] 原点的wkt字符串
*@param toWkt [in] 目标点的wkt字符串
*@param x [in] 经度数组
*@param y [in] 纬度数组
*@param nCount [in] 数组大小
*@return 转换后的经纬度坐标
*/
vector<double*> GdalProjection::ArrayToArray(const char *fromWkt,const char *toWkt,double *x,double *y,int nCount)
{
    vector<double*> ve;
    OGRSpatialReference oSourceSRS,oTargetSRS;
    OGRCoordinateTransformation *poct;

    oSourceSRS.importFromWkt((char **) &fromWkt);
    oTargetSRS.importFromWkt((char **) &toWkt);

    poct = OGRCreateCoordinateTransformation(&oSourceSRS,&oTargetSRS);

    if (poct == NULL || !poct->Transform(nCount,x,y))
    {
        x = NULL;
        y = NULL;
        ve.push_back(x);
        ve.push_back(y);
    }
    else
    {
        ve.push_back(x);
        ve.push_back(y);
    }
    return ve;
}
/**
*@brief 数组对数组的转换
*@param tifPath [in] tif图片路径
*@param toWkt [in] 目标点的wkt字符串
*@param x [in] 经度数组
*@param y [in] 纬度数组
*@param nCount [in] 数组大小
*@return 转换后的经纬度坐标
*/
vector<double *> GdalProjection::ArrayToArray(const char *tifPath,const char *toWkt,int *x,int *y,int nCount)
{
    vector<double *> ve;
    GDALDataset *poDataset = gbase.OpenDatasetR(tifPath);
    const char *fromWkt = poDataset->GetProjectionRef();
    double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    poDataset->GetGeoTransform(adfGeoTransform);
    double *nx = (double *)CPLMalloc(sizeof(double) * nCount);
    double *ny = (double *)CPLMalloc(sizeof(double) * nCount);
    for (int i = 0; i < nCount; i++)
    {
        nx[i]  =  gbase.GetLonOfPoint(adfGeoTransform,x[i],y[i]);
        ny[i]  =  gbase.GetLatOfPoint(adfGeoTransform,x[i],y[i]);
    }
    free(x);
    free(y);
    ve = ArrayToArray(fromWkt,toWkt,nx,ny,nCount);
    return ve;
}
/**
*@brief tif重投影
*@param tifPath [in] tif图片路径
*@param toWkt [in] 目标点的wkt字符串
*@param outPath [in] 转换后文件路径
*@return
*/
void GdalProjection::TifReProjection(const char *tifPath,const char *outPath)
{
    GDALDatasetH  hsrcds, hdstds;
    hsrcds = GDALOpen(tifPath,GA_ReadOnly);
    hdstds = GDALOpen(outPath,GA_Update);

    GDALWarpOptions *psWarpOptions = GDALCreateWarpOptions();
    psWarpOptions->hSrcDS = hsrcds;
    psWarpOptions->hDstDS = hdstds;

    psWarpOptions->nBandCount = 1;
    psWarpOptions->panSrcBands = (int *)CPLMalloc(sizeof(int) * psWarpOptions->nBandCount);
    psWarpOptions->panSrcBands[0] = 1;
    psWarpOptions->panDstBands = (int *)CPLMalloc(sizeof(int) * psWarpOptions->nBandCount);
    psWarpOptions->panDstBands[0] = 1;
    psWarpOptions->pfnProgress = GDALTermProgress;

    psWarpOptions->pTransformerArg = GDALCreateGenImgProjTransformer(hsrcds,GDALGetProjectionRef(hsrcds),
                                     hdstds,GDALGetProjectionRef(hdstds),
                                     FALSE,0.0,1);
    psWarpOptions->pfnTransformer = GDALGenImgProjTransform;

    GDALWarpOperation oOperation;
    oOperation.Initialize(psWarpOptions);
    oOperation.ChunkAndWarpImage(0,0, GDALGetRasterXSize( hdstds ),GDALGetRasterYSize( hdstds ));
    GDALDestroyGenImgProjTransformer(psWarpOptions->pTransformerArg);
    GDALDestroyWarpOptions(psWarpOptions);
    GDALClose(hdstds);
    GDALClose(hsrcds);
}
/**
*@brief tif图片投影转换
*@param tifPath [in] tif图片路径
*@param toWkt [in] 目标点的wkt字符串
*@param outPath [in] 转换后文件路径
*@return
*/
void GdalProjection::TifProjectionTransformation(const char *tifPath, const char *toWkt,const char *outPath)
{
    GDALDataset *poDataset = gbase.OpenDatasetR(tifPath);
    const char *fromWkt = poDataset->GetProjectionRef();
    //double *adfGeoTransform = (double *)CPLMalloc(sizeof(double) * 6);
    //int x = poDataset->GetRasterXSize();
    //int y = poDataset->GetRasterYSize();
    int bands = poDataset->GetRasterCount();
    double adfGeoTransform[6];
    GDALDataType  gdt = poDataset->GetRasterBand(1)->GetRasterDataType();
    void *hTransformArg;
    //cout<<fromWkt;
    hTransformArg = GDALCreateGenImgProjTransformer(poDataset,fromWkt,NULL,toWkt,FALSE,0,1);
    //cout<<toWkt<<endl;
    int nPixels = 0,nLines = 0;
    CPLErr eErr;
    eErr = GDALSuggestedWarpOutput(poDataset,GDALGenImgProjTransform,hTransformArg,
                                   adfGeoTransform,&nPixels,&nLines);
    //cout<<nPixels<<" : "<<nLines<<endl;


    //创建转换后的投影和坐标系的空图像

    CreateTiff(outPath,gdt,toWkt,adfGeoTransform,nPixels,nLines,bands);

    ////重投影
    TifReProjection(tifPath,outPath);

}
