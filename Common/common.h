#ifndef COMMON_H
#define COMMON_H

#include "common_global.h"
#include "../common.h"

class COMMONSHARED_EXPORT Common
{

public:
    Common();

    //k近邻
    unsigned int k;
    //法向估计.返回计算该出入点云的法向量
    pcl::PointCloud<pcl::Normal>::Ptr NormalEstimation(PointCloudT::Ptr p, unsigned int k);
    pcl::PointCloud<pcl::Normal>::Ptr NormalEstimation(PointCloudTRGB::Ptr P, unsigned int k);
};

#endif // COMMON_H
