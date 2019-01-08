#ifndef OREZIO_H
#define OREZIO_H

#include "orez_io_global.h"


/**
 * @brief The OREZ_io class:文件读取模块
 */

#include <iostream>
#include <sstream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/boost.h>

typedef pcl::PointXYZ PointT;
typedef pcl::PointXYZRGB PointTRGB;
typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::PointCloud<PointTRGB> PointCloudTRGB;


class OREZ_IOSHARED_EXPORT OrezIO
{

public:
    OrezIO();
    PointCloudT::Ptr ascToPCD(const std::string ascPath);
    PointCloudTRGB::Ptr loadPCDRGB(const std::string &str);
    PointCloudT::Ptr loadPCD(const std::string &str);
};

#endif // OREZIO_H
