#include "common.h"


Common::Common()
{
    rand_number = 20;
    v_index.resize(rand_number);
    tree.reset();
    //tree_rgb = new pcl::search::KdTree<PointTRGB>();
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


PointCloudT::Ptr Common::boundaryEstimation(PointCloudT::Ptr p, unsigned int k_normal,unsigned K){
    if(p != nullptr){
        pcl::PointCloud<pcl::Boundary>::Ptr boundary(new pcl::PointCloud<pcl::Boundary>);
        pcl::BoundaryEstimation<PointT,pcl::Normal,pcl::Boundary> est;
        pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT>());

        est.setInputCloud(p);
        est.setInputNormals(this->normalEstimation(p,k_normal));
        est.setSearchMethod(tree);
        est.setKSearch(K);
        est.compute(*boundary);

        PointCloudT::Ptr boundaryPoints(new PointCloudT);
        for(size_t i = 0; i< p->size();i++){
            int a = static_cast<int>(boundary->points[i].boundary_point);
            if(a ==1){
                (*boundaryPoints).push_back(p->points[i]);
            }
        }
        return boundaryPoints;
    }else{
        std::cerr<<"请输入有效点云,用于计算法向量!!"<<endl;
        return nullptr;
    }

}

PointCloudTRGB::Ptr Common::boundaryEstimation(PointCloudTRGB::Ptr p, unsigned int k_normal,unsigned int K){
    if(p != nullptr){
        pcl::PointCloud<pcl::Boundary>::Ptr boundary(new pcl::PointCloud<pcl::Boundary>);
        pcl::BoundaryEstimation<PointTRGB,pcl::Normal,pcl::Boundary> est;
        pcl::search::KdTree<PointTRGB>::Ptr tree (new pcl::search::KdTree<PointTRGB>());

        est.setInputCloud(p);
        est.setInputNormals(this->normalEstimation(p,k_normal));
        est.setSearchMethod(tree);
        est.setKSearch(K);
        est.compute(*boundary);

        PointCloudTRGB::Ptr boundaryPoints(new PointCloudTRGB);
        for(size_t i = 0; i< p->size();i++){
            int a = static_cast<int>(boundary->points[i].boundary_point);
            if(a ==1){
                (*boundaryPoints).push_back(p->points[i]);
            }
        }
        return boundaryPoints;
    }else{
        std::cerr<<"请输入有效点云,用于计算法向量!!"<<endl;
        return nullptr;
    }
}

PointCloudT::Ptr Common::filterByVoxel(PointCloudT::Ptr p, int dx, int dy, int dz){
    pcl::VoxelGrid<PointT> voxel;
    PointCloudT::Ptr out(new PointCloudT);
    voxel.setInputCloud(p);
    voxel.setLeafSize(dx,dy,dz);
    voxel.filter(*out);
    return out;
}

PointCloudTRGB::Ptr Common::filterByVoxelRGB(PointCloudTRGB::Ptr p, int dx, int dy, int dz){
    pcl::VoxelGrid<PointTRGB> voxel;
    PointCloudTRGB::Ptr out(new PointCloudTRGB);
    voxel.setInputCloud(p);
    voxel.setLeafSize(dx,dy,dz);
    voxel.filter(*out);
    return out;
}


PointCloudWithNormal::Ptr Common::normalEstimationByMLS(PointCloudT::Ptr p,float radius){
    PointCloudWithNormal mls_points;
    pcl::MovingLeastSquares<PointT,PointNormal> mls;
    mls.setComputeNormals(true);
    mls.setInputCloud(p);
    mls.setPolynomialFit(true); //采用多项式拟合来优化
    mls.setPolynomialOrder(2); //多项式拟合阶数
    mls.setSearchMethod(tree);
    mls.setSearchRadius(radius);

    mls.process(mls_points);

    //PointCloudWithNormal::Ptr mls_normal (new PointCloudWithNormal);
    return mls_points.makeShared();
}
