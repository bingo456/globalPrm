/*
 * file.cpp
 *
 *  Created on: 2012-9-23
 *      Author: wsl
 */
#include "file.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#define PATH_MAX 256

//获取路径下的所有文件夹
vector<string> File::GetFolders(const string &path)
{
    vector<string> folders;
    struct dirent* ent = NULL;
    DIR* pDir;
    pDir = opendir(path.c_str());
    while(NULL != (ent = readdir(pDir)))
    {
        string fullpath = path + "/" + ent->d_name;
        //if(4 == ent->d_type)  //在nfs或xfs下，有的目录d_type也是0
        if(IsFolder(fullpath))
        {
            if(strcmp(ent->d_name, ".")!=0 && strcmp(ent->d_name, "..")!=0)
            {
                folders.push_back(ent->d_name);
            }
        }
    }
    closedir(pDir);
    return folders;
}

//获取路径下的所有文件，可指定文件后缀名
vector<string> File::GetFiles(const string &path, const string &postfix)
{
    vector<string> files;
    struct dirent* ent = NULL;
    DIR* pDir;
    pDir = opendir(path.c_str());
    while(NULL != (ent = readdir(pDir)))
    {
        string fullpath = path + "/" + ent->d_name;
        //if(8 == ent->d_type)  //在nfs或xfs下，有的文件d_type也是0
        if(IsFile(fullpath))
        {
            if(postfix == "" || strstr(ent->d_name, postfix.c_str())!=NULL)
            {
                files.push_back(ent->d_name);
            }
        }
    }
    closedir(pDir);
    return files;
}

//检查文件或目录是否准备好，一定程度上防止数据正在拷贝的时候去读写。
//方法是检查文件或目录的access time是否在5分钟以前
bool File::IsPrepared(const string &path)
{
    struct stat st;
    stat(path.c_str(), &st);
    return time(0)-st.st_ctime >= MAX_DUR;
}

//判断是否为文件夹，用stat的标志来判断
bool File::IsFolder(const string &path)
{
    struct stat st;
    int ret = stat(path.c_str(), &st);
    return ret>=0 && S_ISDIR(st.st_mode);
}

//判断是否为文件，用stat的标志来判断
bool File::IsFile(const string &path)
{
    struct stat st;
    int ret = stat(path.c_str(), &st);
    return ret>=0 && S_ISREG(st.st_mode);
}
//判断是否为目录
bool File::is_dir(const char *path)
{
    struct stat statbuf;
    if(lstat(path, &statbuf) ==0)//lstat返回文件的信息，文件信息存放在stat结构中
    {
        return S_ISDIR(statbuf.st_mode) != 0;//S_ISDIR宏，判断文件类型是否为目录
    }
    return false;
}

//判断是否为常规文件
bool File::is_file(const char *path)
{
    struct stat statbuf;
    if(lstat(path, &statbuf) ==0)
        return S_ISREG(statbuf.st_mode) != 0;//判断文件是否为常规文件
    return false;
}

//判断是否是特殊目录
bool File::is_special_dir(const char *path)
{
    return strcmp(path, ".") == 0 || strcmp(path, "..") == 0;
}

//生成完整的文件路径
void File::get_file_path(const char *path, const char *file_name,  char *file_path)
{
    strcpy(file_path, path);
    if(file_path[strlen(path) - 1] != '/')
        strcat(file_path, "/");
    strcat(file_path, file_name);
}
//删除文件
void File::delete_file(const char *path)
{
    DIR *dir;
    dirent *dir_info;
    char file_path[PATH_MAX];
    if(is_file(path))
    {
        remove(path);
        return;
    }
    if(is_dir(path))
    {
        if((dir = opendir(path)) == NULL)
        {
            // remove(path);
            return;
        }
        while((dir_info = readdir(dir)) != NULL)
        {
            get_file_path(path, dir_info->d_name, file_path);
            if(is_special_dir(dir_info->d_name))
                continue;
            delete_file(file_path);
            rmdir(file_path);
        }
        remove(path);
    }
}
/**
*@brief 获取程序当前路径
*@param
*@return
*/
bool File::fGetCfgFileName(std::string& paraStr_CfgFileName)
{
    paraStr_CfgFileName.clear() ;
    char szWorkDir[MAX_PATH] = {0} ;
    if(!getcwd(szWorkDir, MAX_PATH))
    {
        return false ;
    }

    paraStr_CfgFileName = szWorkDir ;
    paraStr_CfgFileName.append("/") ;

    return true ;
}
/**
*@brief 判断文件夹是否存在
*@param
*@return
*/
bool File::findAndCreat(const char* path,int iDirPermission)
{
    CreateDirectory(path,iDirPermission);
    return true;
}
/**
*@brief 判断文件是否存在
*@param
*@return
*/
bool File::findFile(const char* path)
{
    if(access(path,F_OK) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
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

bool File::CreateDirectory( const char *szDirectoryPath , int iDirPermission )

{
    if ( NULL == szDirectoryPath )
    {
#ifdef DEBUG
        fprintf( stderr , "[%s][%d][%s][parameter < szDirectoryPath > for < CreateDirectory > should not be NULL]\n" , \
                 __FILE__ , __LINE__ , __FUNCTION__ );
#endif
        return false;
    }
    const int iPathLength = static_cast< int >( strlen( szDirectoryPath ) );
    if ( iPathLength > PATH_MAX )
    {
#ifdef DEBUG
        fprintf( stderr , "[%s][%d][%s][the path length(%d) exceeds system max path length(%d)]\n" , \
                 __FILE__ , __LINE__ , __FUNCTION__ , iPathLength , PATH_MAX );
#endif
        return false;
    }
    char szPathBuffer[ PATH_MAX ] = { 0 };
    memcpy( szPathBuffer , szDirectoryPath , iPathLength );
    for ( int i = 0 ; i < iPathLength ; ++i )
    {
        char &refChar = szPathBuffer[ i ];
        //目录分隔符
        if ( ( '/' == refChar ) && ( 0 != i ) )
        {
            refChar = '\0';
            //判断当前目录是否存在
            int iStatus = access( szPathBuffer , F_OK );
            if ( 0 != iStatus )
            {
                if ( ( ENOTDIR == errno ) || ( ENOENT == errno ) )
                {
                    //以指定权限创建目录
                    iStatus = mkdir( szPathBuffer , iDirPermission );
                    if ( 0 != iStatus )
                    {
#ifdef DEBUG
                        fprintf( stderr , "[%s][%d][%s][< mkdir > fail , ErrCode:%d , ErrMsg:%s]\n" , \
                                 __FILE__ , __LINE__ , __FUNCTION__ , errno , strerror( errno ) );
#endif
                        return false;
                    }
                }
                else
                {
#ifdef DEBUG
                    fprintf( stderr , "[%s][%d][%s][< access > fail , RetCode: %d , ErrCode:%d , ErrMsg:%s]\n" , \
                             __FILE__ , __LINE__ , __FUNCTION__ , iStatus , errno , strerror( errno ) );
#endif
                    return false;
                }
            }
            refChar = '/';
        }
    }
    return true;
}


