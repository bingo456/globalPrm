#pragma once
#include "GdalOpr.h"

using namespace std;

class GdalProjection :
    public GdalOpr
{
private:
    GdalOpr gbase;
public:
    GdalProjection(void);
    ~GdalProjection(void);
    /**
    *@brief 点对点的转换
    *@param fromWkt [in] 原点的wkt字符串
    *@param toWkt [in] 目标点的wkt字符串
    *@param x [in] x点经度
    *@param y [in] y点纬度
    *@return 转换后的经纬度坐标
    */
    double *PointToPoint(const char *fromWkt,const char *toWkt,double x,double y);
    /**
    *@brief 点对点的转换
    *@param tifPath [in] tif图片路径
    *@param toWkt [in] 目标点的wkt字符串
    *@param x [in] x点经度
    *@param y [in] y点纬度
    *@return 转换后的经纬度坐标
    */
    double *PointToPoint(const char *tifPath,const char *toWkt,int x,int y);
    /**
    *@brief 数组对数组的转换
    *@param fromWkt [in] 原点的wkt字符串
    *@param toWkt [in] 目标点的wkt字符串
    *@param x [in] 经度数组
    *@param y [in] 纬度数组
    *@param nCount [in] 数组大小
    *@return 转换后的经纬度坐标
    */
    vector<double*> ArrayToArray(const char *fromWkt,const char *toWkt,double *x,double *y,int nCount);
    /**
    *@brief 数组对数组的转换
    *@param tifPath [in] tif图片路径
    *@param toWkt [in] 目标点的wkt字符串
    *@param x [in] 经度数组
    *@param y [in] 纬度数组
    *@param nCount [in] 数组大小
    *@return 转换后的经纬度坐标
    */
    vector<double *> ArrayToArray(const char *tifPath,const char *toWkt,int *x,int *y,int nCount);
    /**
    *@brief tif重投影
    *@param tifPath [in] tif图片路径
    *@param toWkt [in] 目标点的wkt字符串
    *@param outPath [in] 转换后文件路径
    *@return
    */
    void TifReProjection(const char *tifPath,const char *outPath);
    /**
    *@brief tif图片投影转换
    *@param tifPath [in] tif图片路径
    *@param toWkt [in] 目标点的wkt字符串
    *@param outPath [in] 转换后文件路径
    *@return
    */
    void TifProjectionTransformation(const char *tifPath, const char *toWkt,const char *outPath);


};
