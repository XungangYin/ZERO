#ifndef OREZIO_H
#define OREZIO_H

#include "orez_io_global.h"
#include "../common.h"
#include <QFile>
#include <QFileInfo>
/**
 * @brief The OREZ_io class:文件读取模块
 */
////声明一个结构体模板,保存点云信息
//struct PointCloudInfo
//{
//     std::string path = ""; //这里不要用0初始化
//     std::string file_name=  "";
//     size_t size = 0;
//     std::string dim = "";
//};
class OREZ_IOSHARED_EXPORT OrezIO
{

public:
    OrezIO();
    PointCloudT::Ptr ascToPCD(const std::string ascPath);
    PointCloudTRGB::Ptr loadPCDRGB(const std::string &str);
    PointCloudT::Ptr loadPCD(const std::string &str);

    std::string path;
    size_t size;
    std::string file_name;
    std::string dim ;

    std::string getFileName(std::string path);
    template <class T>
    size_t getPointCloudSize(const T t);  //获取点云大小

    template <class T>
    std::string getPontCloudDim(const T t); //获取点云的维度信息


};

#endif // OREZIO_H
