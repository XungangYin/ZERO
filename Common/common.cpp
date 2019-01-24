#include "common.h"


Common::Common()
{
    rand_number = 20;
    v_index.resize(rand_number);
}

pcl::PointCloud<pcl::Normal>::Ptr  Common::normalEstimation(PointCloudT::Ptr p, unsigned int k){
    if(p == nullptr){
        std::cerr<<"法向计算: 输入点云错误,请重新输入!!"<<std::endl;
        //return false;
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

pcl::PointCloud<pcl::Normal>::Ptr Common::normalEstimation(PointCloudTRGB::Ptr p, unsigned int k){
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

double Common::estimateDistance(const PointCloudT::Ptr p){
    //随机选取点云中的20个点计算平均密度
    srand(unsigned(time(NULL)));//初始化随机种子
    unsigned int size = p->points.size();
    for(int i =0 ;i < rand_number; i++){
         int seed = random()%(size+1); //取范围为[0,size]的随机数
         v_index.push_back(seed);
    }
    pcl::KdTreeFLANN<PointT> kdtree;
    kdtree.setInputCloud(p);
    int k =2;
    float everagedistance =0;
    for (int i =0; i <v_index.size();i++){
        vector<int> nnh ;
        vector<float> squaredistance;
        kdtree.nearestKSearch(p->points[v_index[i]],k,nnh,squaredistance);
        everagedistance += sqrt(squaredistance[1]);
    }
    v_index.clear();
    return everagedistance/rand_number;
}

double Common::estimateDistance(const PointCloudTRGB::Ptr p){
    srand(unsigned(time(NULL)));//初始化随机种子
    unsigned int size = p->points.size();
    for(int i =0 ;i < rand_number; i++){
         int seed = random()%(size+1); //取范围为[0,size]的随机数
         v_index.push_back(seed);
    }
    pcl::KdTreeFLANN<PointTRGB> kdtree;
    kdtree.setInputCloud(p);
    int k =2;
    float everagedistance =0;
    for (int i =0; i <v_index.size();i++){
        vector<int> nnh ;
        vector<float> squaredistance;
        kdtree.nearestKSearch(p->points[v_index[i]],k,nnh,squaredistance);
        everagedistance += sqrt(squaredistance[1]);
    }

    v_index.clear();
    return everagedistance/rand_number;
}



