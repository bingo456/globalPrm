/*
 * file.h
 *
 *  Created on: 2012-9-23
 *      Author: wsl
 */

#ifndef FILE_H
#define FILE_H
#include <vector>
#include <string>
#include <time.h>
#include <sys/stat.h>
using namespace std;
#define MAX_PATH 256

const int MAX_DUR = 5*60;  //时间阈值

class File
{
public:
    //获取路径下的所有文件夹
    vector<string> GetFolders(const string &path);

    //获取路径下的所有文件，可指定文件后缀名
    vector<string> GetFiles(const string &path, const string &postfix="");

    //检查文件或目录是否准备好，一定程度上防止数据正在拷贝的时候去读写。
    //方法是检查文件或目录的access time是否在5分钟以前
    bool IsPrepared(const string &path);

    //判断是否为文件夹
    bool IsFolder(const string &path);

    //判断是否为文件
    bool IsFile(const string &path);
    //删除文件
    void delete_file(const char *path);
    /**
        *@brief 获取程序当前路径
        *@param
        *@return
        */
    bool fGetCfgFileName(std::string& paraStr_CfgFileName);
    /**
    *@brief 判断文件夹是否存在
    *@param
    *@return
    */
    bool findAndCreat(const char* path,int iDirPermission);
    /**
    *@brief 判断文件是否存在
    *@param
    *@return
    */
    bool findFile(const char* path);
//! @brief 生成目录

    /*!

    以指定的权限创建目录.

    对于指定要创建的目录，如果其父目录不存在(递归至要生成的目标上报的根目录)，那么会创建其对应的父目录

    例如，指定要创建的目录: "/foo/bar"，如果/foo/目录不存在，那么在创建 bar 目录之前会创建 /foo 目录

    对于要生成的目标目录，"./foo/bar" 等价于 "foo/bar"

    @param szDirectoryPath 要创建的目录的路径

    @param iDirPermission 创建目录时，为所创建的目录所指定的权限

    @return 如果创建成功，返回<b>true</b>;如果创建失败，返回<b>false</b>.

    */

    bool CreateDirectory( const char *szDirectoryPath , int iDirPermission  );

private:
    //判断是否为目录
    bool is_dir(const char *path);

    //判断是否为常规文件
    bool is_file(const char *path);

    //判断是否是特殊目录
    bool is_special_dir(const char *path);

    //生成完整的文件路径
    void get_file_path(const char *path, const char *file_name,  char *file_path);

};




#endif /* FILE_H_ */
