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
    //                        ͼ���������                                            //
    //            ���ܰ������򿪣�ֻ����д�룩����ò�����������������ɾ��          //
    //********************************************************************************//
    /**
    *@brief���ԭʼͼ������ݼ���ֻ����
    *@param inpath [in] ����·��
    *@return
    */
    GDALDataset *OpenDatasetR(const char *inpath);
    /**
    *@brief���ԭʼͼ������ݼ�������д�룩
    *@param inpath [in] ����·��
    *@return
    */
    GDALDataset *OpenDatasetW(const char *inpath);
    /**
    *@brief ��ò�����
    *@param poDataset [in] gdal���ݼ�
    *@return
    */
    int GetBandCount(GDALDataset *poDataset);
    /**
    *@brief ���դ�����ݿ�
    *@param poDataset [in] gdal���ݼ�
    *@return
    */
    int GetWidth(GDALDataset *poDataset);
    /**
    *@brief ���դ�����ݸ�
    *@param poDataset [in] gdal���ݼ�
    *@return
    */
    int GetHeight(GDALDataset *poDataset);
    /**
    *@brief ��ȡͼ�����ݼ�(byte)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,byte_t *datas);
    /**
    *@brief ��ȡͼ�����ݼ�(unsigned short)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas);
    /**
    *@brief ��ȡͼ�����ݼ�(short)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,short *datas);
    /**
    *@brief ��ȡͼ�����ݼ�(unsigned int)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas);
    /**
    *@brief ��ȡͼ�����ݼ�(int)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,int *datas);
    /**
    *@brief ��ȡͼ�����ݼ�(float)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,float *datas);
    /**
    *@brief ��ȡͼ�����ݼ�(double)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@return width(int)
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,double *datas);
    /**
    *@brief д��ͼ�����ݼ�(byte)
    *@param poDataset [in] gdal���ݼ�
    *@param nb [in] ����
    *@param datas [in] д������
    *@return width(int)
    */

    bool WriteBandDatas(GDALDataset *poDataset,int nb,byte_t *datas);
    /**
        *@brief д��ͼ�����ݼ�(unsigned short)
        *@param poDataset [in] gdal���ݼ�
        *@param nb [in] ����
        *@param datas [in] д������
        *@return width(int)
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas);
    /**
    *@brief д��ͼ�����ݼ�(short)
    *@param poDataset [in] gdal���ݼ�
    *@param nb [in] ����
    *@param datas [in] д������
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,short *datas);
    /**
    *@brief д��ͼ�����ݼ�(unsigned int)
    *@param poDataset [in] gdal���ݼ�
    *@param nb [in] ����
    *@param datas [in] д������
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas);
    /**
    *@brief д��ͼ�����ݼ�(int)
    *@param poDataset [in] gdal���ݼ�
    *@param nb [in] ����
    *@param datas [in] д������
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,int *datas);
    /**
    *@brief д��ͼ�����ݼ�(float)
    *@param poDataset [in] gdal���ݼ�
    *@param nb [in] ����
    *@param datas [in] д������
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,float *datas);
    /**
    *@brief д��ͼ�����ݼ�(double)
    *@param poDataset [in] gdal���ݼ�
    *@param nb [in] ����
    *@param datas [in] д������
    *@return width(int)
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,double *datas);
    /**
    *@brief gdal�ر�dataset
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@return width(int)
    */
    void DatasetClose(GDALDataset *poDataset);
    /**
    *@brief ����tifͼ��
    *@param outpath [in] tif�ļ�·��
    *@param eType [in] gdal��������
    *@param wkt [in] wkt�ַ���
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xSize [in] x�����ݴ�С
    *@param ySize [in] y�����ݴ�С
    *@param eType [in] gdal��������
    *@param bandCount [in] ������
    *@return true����tiff�ɹ���false����tiffʧ��
    */
    bool CreateTiff(const char *outpath,GDALDataType eType,const char *wkt,double *adfGeoTransform,int xSize,int ySize,int bandCount);
    /**
    *@brief ����tifͼ��û��ͶӰ������ת��ϵ��0,1,0,0,0,1��
    *@param outpath [in] tif�ļ�·��
    *@param eType [in] gdal��������
    *@param xSize [in] x�����ݴ�С
    *@param ySize [in] y�����ݴ�С
    *@param eType [in] gdal��������
    *@param bandCount [in] ������
    *@return true����tiff�ɹ���false����tiffʧ��
    */
    bool CreateTiff(const char *outpath,GDALDataType eType,int xSize,int ySize,int bandCount);
    /**
    *@brief ɾ��tifͼ��
    *@param outpath [in] tif�ļ�·��
    *@return trueɾ��tiff�ɹ���falseɾ��tiffʧ��
    */
    bool DeleteTiff(const char *outpath);
    //********************************************************************************//
    //                        ͼ��ü�                                                //
    //            ֧�ֵĸ�ʽ��byte;short;int;float;double��                           //
    //********************************************************************************//
    /**
    *@brief ��òü�ͼƬ�Ŀ�
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@return width(int)
    */
    int GetNewWidth(double *adfGeoTransform,double *xyPeak);
    /**
    *@brief ��òü�ͼƬ�ĸ�
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@return width(int)
    */
    int GetNewHeight(double *adfGeoTransform,double *xyPeak);
    /**
    *@brief ��òü�ͼ�����ݼ�(byte)
    *@param poDataset [in] gdal���ݼ�
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@param band [in] ������
    *@param typeParam [in] �������ر���
    *@return width(int)
    */
    byte_t *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,byte_t typeParam);
    /**
    *@brief ��òü�ͼ�����ݼ�(short)
    *@param poDataset [in] gdal���ݼ�
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@param band [in] ������
    *@param typeParam [in] �������ر���
    *@return width(int)
    */
    short *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,short typeParam);
    /**
    *@brief ��òü�ͼ�����ݼ�(int)
    *@param poDataset [in] gdal���ݼ�
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@param band [in] ������
    *@param typeParam [in] �������ر���
    *@return width(int)
    */
    int *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,int typeParam);
    /**
    *@brief ��òü�ͼ�����ݼ�(float)
    *@param poDataset [in] gdal���ݼ�
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@param band [in] ������
    *@param typeParam [in] �������ر���
    *@return width(int)
    */
    float *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,float typeParam);
    /**
    *@brief ��òü�ͼ�����ݼ���double��
    *@param poDataset [in] gdal���ݼ�
    *@param xyPeak [in] ���϶��㣬�����¶��������{xl,yl,xr,yr}
    *@param band [in] ������
    *@param typeParam [in] �������ر���
    *@return width(int)
    */
    double *GetCutoutDatas(GDALDataset *poDataset,double *xyPeak,int band,double typeParam);
    //********************************************************************************//
    //                        ���ĳһ�㾭γ��                                        //
    //                        ��γ����ͼ�����ת��                                 //
    //********************************************************************************//
    //  ���ĳһ�㴦�����깫ʽ
    //  double xp = adfGeoTransform[0] + i * adfGeoTransform[1] + j * adfGeoTransform[2];
    //  double yp = adfGeoTransform[3] + i * adfGeoTransform[4] + j * adfGeoTransform[5];
    /**
    *@brief ��þ�������ֵ
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    double GetLonOfPoint(double *adfGeoTransform,int xPoint,int yPoint);
    /**
    *@brief ��þ�������ֵ
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    double GetLatOfPoint(double *adfGeoTransform,int xPoint,int yPoint);
    /**
    *@brief ���X����ֵ
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    int GetPointXOfLonLat( double *adfGeoTransform, double lon, double lat );
    /**
    *@brief ���Y����ֵ
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param lat [in] γ��
    *@param lon [in] ����
    *@return ����ֵ
    */
    int GetPointYOfLonLat(double *adfGeoTransform, double lon, double lat);
    //********************************************************************************//
    //                        �������ز�����gdalԭʼ�������                        //
    //            ֧�ֵĸ�ʽ��byte;short;int;float;double��                           //
    //********************************************************************************//
    /**
    *@brief �������ز���(byte)
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    void SimpleLinearResample(GDALDataset *poDataset,byte_t *gDatas,int x,int y,const char *outPath);
    /**
    *@brief �������ز���(short)
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    void SimpleLinearResample(GDALDataset *poDataset,short *gDatas,int x,int y,const char *outPath);
    /**
    *@brief �������ز���(int)
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    void SimpleLinearResample(GDALDataset *poDataset,int *gDatas,int x,int y,const char *outPath);
    /**
    *@brief �������ز���(float)
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    void SimpleLinearResample(GDALDataset *poDataset,float *gDatas,int x,int y,const char *outPath);
    /**
    *@brief �������ز���(double)
    *@param adfGeoTransform [in] ����ת����Ϣ
    *@param xPiont [in] x���λ��
    *@param yPiont [in] y���λ��
    *@return ����ֵ
    */
    void SimpleLinearResample(GDALDataset *poDataset,double *gDatas,int x,int y,const char *outPath);

    /************************************************************************/
    /*                     ָ����������ݶ�ȡ                           */
    /************************************************************************/

    /**
    *@brief ��ȡͼ�����ݼ�(byte_t)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,byte_t *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
        *@brief ��ȡͼ�����ݼ�(unsigned short)
        *@param poDataset [in] gdal���ݼ�
        *@param band [in] ����
        *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
        *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
        *@return
        */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief ��ȡͼ�����ݼ�(short)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,short *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief ��ȡͼ�����ݼ�(unsigned int)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief ��ȡͼ�����ݼ�(int)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,int *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief ��ȡͼ�����ݼ�(float)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,float *datas,
                       int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief ��ȡͼ�����ݼ�(double)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool ReadBandDatas(GDALDataset *poDataset,int nb,double *datas,
                       int offx, int offy, int pafsizex, int pafsizey );

    /************************************************************************/
    /*                     ָ����������ݶ�ȡ                           */
    /************************************************************************/
    /**
        *@brief д��ͼ�����ݼ�(byte)
        *@param poDataset [in] gdal���ݼ�
        *@param band [in] ����
        *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
        *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
        *@return
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,byte_t *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
        *@brief д��ͼ�����ݼ�(unsigned short)
        *@param poDataset [in] gdal���ݼ�
        *@param band [in] ����
        *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
        *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
        *@return
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned short *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
        *@brief д��ͼ�����ݼ�(short)
        *@param poDataset [in] gdal���ݼ�
        *@param band [in] ����
        *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
        *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
        *@return
        */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,short *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief д��ͼ�����ݼ�(unsigned int)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,unsigned int *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief д��ͼ�����ݼ�(int)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,int *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief д��ͼ�����ݼ�(float)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,float *datas,
                        int offx, int offy, int pafsizex, int pafsizey );
    /**
    *@brief д��ͼ�����ݼ�(double)
    *@param poDataset [in] gdal���ݼ�
    *@param band [in] ����
    *@param x_strat,y_strat [in] ���ݵ���ʼ��(���Ͻ�)
    *@param x_end,y_end [in] ���ݵ���ֹ�㣨���½ǣ�
    *@return
    */
    bool WriteBandDatas(GDALDataset *poDataset,int nb,double *datas,
                        int offx, int offy, int pafsizex, int pafsizey );

};
#endif
