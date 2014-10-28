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
    *@brief ��Ե��ת��
    *@param fromWkt [in] ԭ���wkt�ַ���
    *@param toWkt [in] Ŀ����wkt�ַ���
    *@param x [in] x�㾭��
    *@param y [in] y��γ��
    *@return ת����ľ�γ������
    */
    double *PointToPoint(const char *fromWkt,const char *toWkt,double x,double y);
    /**
    *@brief ��Ե��ת��
    *@param tifPath [in] tifͼƬ·��
    *@param toWkt [in] Ŀ����wkt�ַ���
    *@param x [in] x�㾭��
    *@param y [in] y��γ��
    *@return ת����ľ�γ������
    */
    double *PointToPoint(const char *tifPath,const char *toWkt,int x,int y);
    /**
    *@brief ����������ת��
    *@param fromWkt [in] ԭ���wkt�ַ���
    *@param toWkt [in] Ŀ����wkt�ַ���
    *@param x [in] ��������
    *@param y [in] γ������
    *@param nCount [in] �����С
    *@return ת����ľ�γ������
    */
    vector<double*> ArrayToArray(const char *fromWkt,const char *toWkt,double *x,double *y,int nCount);
    /**
    *@brief ����������ת��
    *@param tifPath [in] tifͼƬ·��
    *@param toWkt [in] Ŀ����wkt�ַ���
    *@param x [in] ��������
    *@param y [in] γ������
    *@param nCount [in] �����С
    *@return ת����ľ�γ������
    */
    vector<double *> ArrayToArray(const char *tifPath,const char *toWkt,int *x,int *y,int nCount);
    /**
    *@brief tif��ͶӰ
    *@param tifPath [in] tifͼƬ·��
    *@param toWkt [in] Ŀ����wkt�ַ���
    *@param outPath [in] ת�����ļ�·��
    *@return
    */
    void TifReProjection(const char *tifPath,const char *outPath);
    /**
    *@brief tifͼƬͶӰת��
    *@param tifPath [in] tifͼƬ·��
    *@param toWkt [in] Ŀ����wkt�ַ���
    *@param outPath [in] ת�����ļ�·��
    *@return
    */
    void TifProjectionTransformation(const char *tifPath, const char *toWkt,const char *outPath);


};
