#include "common.h"


Common::Common()
{
}

pcl::PointCloud<pcl::Normal>::Ptr Common::NormalEstimation(PointCloudT::Ptr p, unsigned int k){
    if(p == nullptr){
        std::cerr<<"法向计算: 输入点云错误,请重新输入!!"<<std::endl;
        return false;
    }
    else {
        pcl::NormalEstimation<PointT,pcl::Normal> ne;
        pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT>());
        ne.setSearchMethod(tree);
        ne.setKSearch(k);
        ne.setInputCloud(p);
    // Output datasets
        pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
    // Compute the features
        ne.compute (*cloud_normals);

        return cloud_normals;
    }
}

pcl::PointCloud<pcl::Normal>::Ptr Common::NormalEstimation(PointCloudTRGB::Ptr p, unsigned int k){
    if(p == nullptr){
        std::cerr<<"法向计算: 输入点云错误,请重新输入!!"<<std::endl;
        return false;
    }
    else {
        pcl::NormalEstimation<PointTRGB,pcl::Normal> ne;
        pcl::search::KdTree<PointTRGB>::Ptr tree (new pcl::search::KdTree<PointTRGB>());
        ne.setSearchMethod(tree);
        ne.setKSearch(k);
        ne.setInputCloud(p);
    // Output datasets
        pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
    // Compute the features
        ne.compute (*cloud_normals);

        return cloud_normals;
    }
}
