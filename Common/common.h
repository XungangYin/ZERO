#ifndef COMMON_H
#define COMMON_H

#include "common_global.h"
#include "../common.h"

using namespace std;

class COMMONSHARED_EXPORT Common
{

private:
        std::vector<int> v_index;
        int rand_number;

public:
    Common();
    //计算点云平均密度,返回两点间平均距离
    double estimateDistance(const PointCloudT::Ptr p);
    double estimateDistance(const PointCloudTRGB::Ptr p);
    //法向估计.返回计算该出入点云的法向量
    pcl::PointCloud<pcl::Normal>::Ptr normalEstimation(PointCloudT::Ptr p, unsigned int k);
    pcl::PointCloud<pcl::Normal>::Ptr normalEstimation(PointCloudTRGB::Ptr P, unsigned int k);
};

#endif // COMMON_H
