#ifndef COMMON_H
#define COMMON_H

#include "common_global.h"
#include "../common.h"

#include <pcl/features/boundary.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/mls.h>

using namespace std;

class COMMONSHARED_EXPORT Common
{

private:
        std::vector<int> v_index;
        int rand_number;
        pcl::search::KdTree<pcl::PointXYZ>::Ptr tree;
        //pcl::search::KdTree<PointTRGB>::Ptr tree_rgb;

public:
    Common();
    //计算点云平均密度,返回两点间平均距离
    double estimateDistance(const PointCloudT::Ptr p);
    double estimateDistance(const PointCloudTRGB::Ptr p);
    //法向估计.返回计算该出入点云的法向量
    pcl::PointCloud<pcl::Normal>::Ptr normalEstimation(PointCloudT::Ptr p, unsigned int k);
    pcl::PointCloud<pcl::Normal>::Ptr normalEstimation(PointCloudTRGB::Ptr P, unsigned int k);

    //边界识别
    PointCloudT::Ptr boundaryEstimation(PointCloudT::Ptr p, unsigned int k_normal, unsigned int K);
    PointCloudTRGB::Ptr boundaryEstimation(PointCloudTRGB::Ptr p, unsigned int k_normal,unsigned int K);

    //体素网格滤波
    PointCloudT::Ptr filterByVoxel(PointCloudT::Ptr p, int dx, int dy,int dz);
    PointCloudTRGB::Ptr filterByVoxelRGB(PointCloudTRGB::Ptr p, int dx, int dy,int dz);

    //MLS法向估计(统一法向)
    PointCloudWithNormal::Ptr normalEstimationByMLS(PointCloudT::Ptr p,float radius);

};

#endif // COMMON_H
