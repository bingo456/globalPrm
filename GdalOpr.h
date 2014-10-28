#ifndef GDALOPR_H
#define GDALOPR_H
//#include "gdal.h"
#include <iostream>
#include "gdal_priv.h"
//#include "ogr_spatialref.h"
typedef unsigned char byte_t;

class GdalOpr
{
public:
    GdalOpr(void);
    ~GdalOpr(void);
    //********************************************************************************//
    //                        图像基本操作                                            //
    //            功能包括：打开（只读，写入）；获得波段数，长宽；创建；删除          //
    //********************************************************************************//
    /**
    *@brief获得原始图像的数据集（只读）
    *@param inpath [in] 输入路径
    *@return
    */
    GDALDataset *OpenDatasetR(const char *inpath);
    /**
    *@brief获得原始图像的数据集（可以写入）
    *@param inpath [in] 输入路径
    *@return
    */
    GDALDataset *OpenDatasetW(const char *inpath);
    /**
    *@brief 获得波段数
    *@param poDataset [in] gdal数据集
    *@return
    */
    int GetBandCount(GDALDataset *poDataset);
    /**
    *@brief 获得栅格数据宽
    *@param poDataset [in] gdal数据集
    *@return
    */
    int GetWidth(GDALDataset *poDataset);
    /**
    *@brief 获得栅格数据高
    *@param poDataset [in] gdal数据集
    *@return
    */
    int GetHeight(GDALDataset *poDataset);
    /**
    *@brief 读取图像数据集(byte)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,byte_t *datas);
    /**
    *@brief 读取图像数据集(unsigned short)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas);
    /**
    *@brief 读取图像数据集(short)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,short *datas);
    /**
    *@brief 读取图像数据集(unsigned int)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas);
    /**
    *@brief 读取图像数据集(int)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,int *datas);
    /**
    *@brief 读取图像数据集(float)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,float *datas);
    /**
    *@brief 读取图像数据集(double)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,double *datas);
    /**
    *@brief 写入图像数据集(byte)
    *@param poDataset [in] gdal数据集
    *@param nb [in] 波段
    *@param datas [in] 写入数据
    *@return width(int)
    */

    bool WriteBandDatas(GDALDataset *poDataset,int nb,byte_t *datas);
    /**
        *@brief 写入图像数据集(unsigned short)
        *@param poDataset [in] gdal数据集
        *@param nb [in] 波段
        *@param datas [in] 写入数据
        *@return width(int)
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas);
    /**
    *@brief 写入图像数据集(short)
    *@param poDataset [in] gdal数据集
    *@param nb [in] 波段
    *@param datas [in] 写入数据
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,short *datas);
    /**
    *@brief 写入图像数据集(unsigned int)
    *@param poDataset [in] gdal数据集
    *@param nb [in] 波段
    *@param datas [in] 写入数据
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas);
    /**
    *@brief 写入图像数据集(int)
    *@param poDataset [in] gdal数据集
    *@param nb [in] 波段
    *@param datas [in] 写入数据
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,int *datas);
    /**
    *@brief 写入图像数据集(float)
    *@param poDataset [in] gdal数据集
    *@param nb [in] 波段
    *@param datas [in] 写入数据
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,float *datas);
    /**
    *@brief 写入图像数据集(double)
    *@param poDataset [in] gdal数据集
    *@param nb [in] 波段
    *@param datas [in] 写入数据
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,double *datas);
    /**
    *@brief gdal关闭dataset
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
    *@return width(int)
    */
    void DatasetClose(GDALDataset *poDataset);
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
    bool CreateTiff(const char *outpath,GDALDataType eType,const char *wkt,double *adfGeoTransform,int xSize,int ySize,int bandCount);
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
    bool CreateTiff(const char *outpath,GDALDataType eType,int xSize,int ySize,int bandCount);
    /**
    *@brief 删除tif图像
    *@param outpath [in] tif文件路径
    *@return true删除tiff成功；false删除tiff失败
    */
    bool DeleteTiff(const char *outpath);
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
    int GetNewWidth(double *adfGeoTransform,double *xyPeak);
    /**
    *@brief 获得裁剪图片的高
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
    *@return width(int)
    */
    int GetNewHeight(double *adfGeoTransform,double *xyPeak);
    /**
    *@brief 获得裁剪图像数据集(byte)
    *@param poDataset [in] gdal数据集
    *@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
    *@param band [in] 波段数
    *@param typeParam [in] 类型重载变量
    *@return width(int)
    */
    byte_t *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,byte_t typeParam);
    /**
    *@brief 获得裁剪图像数据集(short)
    *@param poDataset [in] gdal数据集
    *@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
    *@param band [in] 波段数
    *@param typeParam [in] 类型重载变量
    *@return width(int)
    */
    short *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,short typeParam);
    /**
    *@brief 获得裁剪图像数据集(int)
    *@param poDataset [in] gdal数据集
    *@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
    *@param band [in] 波段数
    *@param typeParam [in] 类型重载变量
    *@return width(int)
    */
    int *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,int typeParam);
    /**
    *@brief 获得裁剪图像数据集(float)
    *@param poDataset [in] gdal数据集
    *@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
    *@param band [in] 波段数
    *@param typeParam [in] 类型重载变量
    *@return width(int)
    */
    float *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,float typeParam);
    /**
    *@brief 获得裁剪图像数据集（double）
    *@param poDataset [in] gdal数据集
    *@param xyPeak [in] 左上顶点，和右下顶点的坐标{xl,yl,xr,yr}
    *@param band [in] 波段数
    *@param typeParam [in] 类型重载变量
    *@return width(int)
    */
    double *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,double typeParam);
    //********************************************************************************//
    //                        获得某一点经纬度                                        //
    //                        经纬度与图像点间的转换                                 //
    //********************************************************************************//
    //  获得某一点处的坐标公式
    //  double xp = adfGeoTransform[0] + i * adfGeoTransform[1] + j * adfGeoTransform[2];
    //  double yp = adfGeoTransform[3] + i * adfGeoTransform[4] + j * adfGeoTransform[5];
    /**
    *@brief 获得经度坐标值
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xPiont [in] x点的位置
    *@param yPiont [in] y点的位置
    *@return 经度值
    */
    double GetLonOfPoint(double *adfGeoTransform,int xPoint,int yPoint);
    /**
    *@brief 获得经度坐标值
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xPiont [in] x点的位置
    *@param yPiont [in] y点的位置
    *@return 经度值
    */
    double GetLatOfPoint(double *adfGeoTransform,int xPoint,int yPoint);
    /**
    *@brief 获得X坐标值
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xPiont [in] x点的位置
    *@param yPiont [in] y点的位置
    *@return 经度值
    */
    int GetPointXOfLonLat( double *adfGeoTransform, double lon, double lat );
    /**
    *@brief 获得Y坐标值
    *@param adfGeoTransform [in] 坐标转换信息
    *@param lat [in] 纬度
    *@param lon [in] 经度
    *@return 经度值
    */
    int GetPointYOfLonLat(double *adfGeoTransform, double lon, double lat);
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
    void SimpleLinearResample(GDALDataset *poDataset,byte_t *gDatas,int x,int y,const char *outPath);
    /**
    *@brief 简单线性重采样(short)
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xPiont [in] x点的位置
    *@param yPiont [in] y点的位置
    *@return 经度值
    */
    void SimpleLinearResample(GDALDataset *poDataset,short *gDatas,int x,int y,const char *outPath);
    /**
    *@brief 简单线性重采样(int)
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xPiont [in] x点的位置
    *@param yPiont [in] y点的位置
    *@return 经度值
    */
    void SimpleLinearResample(GDALDataset *poDataset,int *gDatas,int x,int y,const char *outPath);
    /**
    *@brief 简单线性重采样(float)
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xPiont [in] x点的位置
    *@param yPiont [in] y点的位置
    *@return 经度值
    */
    void SimpleLinearResample(GDALDataset *poDataset,float *gDatas,int x,int y,const char *outPath);
    /**
    *@brief 简单线性重采样(double)
    *@param adfGeoTransform [in] 坐标转换信息
    *@param xPiont [in] x点的位置
    *@param yPiont [in] y点的位置
    *@return 经度值
    */
    void SimpleLinearResample(GDALDataset *poDataset,double *gDatas,int x,int y,const char *outPath);

    /************************************************************************/
    /*                     指定区域的数据读取                           */
    /************************************************************************/

    /**
    *@brief 读取图像数据集(byte_t)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,byte_t *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
        *@brief 读取图像数据集(unsigned short)
        *@param poDataset [in] gdal数据集
        *@param band [in] 波段
        *@param x_strat,y_strat [in] 数据的起始点(左上角)
        *@param x_end,y_end [in] 数据的终止点（右下角）
        *@return
        */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 读取图像数据集(short)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,short *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 读取图像数据集(unsigned int)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 读取图像数据集(int)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,int *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 读取图像数据集(float)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,float *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 读取图像数据集(double)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,double *datas,
                       int offx, int offy, int pafsizex, int pafsizey );

    /************************************************************************/
    /*                     指定区域的数据读取                           */
    /************************************************************************/
    /**
        *@brief 写入图像数据集(byte)
        *@param poDataset [in] gdal数据集
        *@param band [in] 波段
        *@param x_strat,y_strat [in] 数据的起始点(左上角)
        *@param x_end,y_end [in] 数据的终止点（右下角）
        *@return
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,byte_t *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
        *@brief 写入图像数据集(unsigned short)
        *@param poDataset [in] gdal数据集
        *@param band [in] 波段
        *@param x_strat,y_strat [in] 数据的起始点(左上角)
        *@param x_end,y_end [in] 数据的终止点（右下角）
        *@return
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
        *@brief 写入图像数据集(short)
        *@param poDataset [in] gdal数据集
        *@param band [in] 波段
        *@param x_strat,y_strat [in] 数据的起始点(左上角)
        *@param x_end,y_end [in] 数据的终止点（右下角）
        *@return
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,short *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 写入图像数据集(unsigned int)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 写入图像数据集(int)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,int *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 写入图像数据集(float)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,float *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief 写入图像数据集(double)
    *@param poDataset [in] gdal数据集
    *@param band [in] 波段
    *@param x_strat,y_strat [in] 数据的起始点(左上角)
    *@param x_end,y_end [in] 数据的终止点（右下角）
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,double *datas,
                        int offx, int offy, int pafsizex, int pafsizey );

};
#endif
