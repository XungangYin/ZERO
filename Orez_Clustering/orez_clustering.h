#ifndef OREZ_CLUSTERING_H
#define OREZ_CLUSTERING_H

#include "orez_clustering_global.h"
#include "../common.h"
#include <ctime>
#include <cmath>

using namespace  std;

typedef struct st_point{
    PointT pnt;
    unsigned int groupID;
    st_point(PointT &p,unsigned int id){
        pnt = p;
        groupID  = id;
    }
} st_point;

class OREZ_CLUSTERINGSHARED_EXPORT Orez_Clustering
{

public:
    Orez_Clustering();
    class KMeans{
    public:
        unsigned int m_k;
        PointCloudT::Ptr _p;
        typedef vector<st_point> VecPoint; //取一个简单的名字
        VecPoint mv_pntcloud;
        vector<VecPoint> m_group_pntcloud; //K类
        vector<PointT> mv_center; //聚类中心

        KMeans(){ m_k = 0;}
        KMeans(unsigned int k):m_k(k){mv_center.resize(m_k);}

        inline void setK(unsigned int k){m_k = k;}
        bool setInputCloud(PointCloudT::Ptr &p);
        void initCenter(); //初始化聚类中心
        bool cluster(); //聚类计算
        //更新聚类中心
        void updateGroupCenter(vector<VecPoint> &grp_pncloud,vector<PointT> &cer);
        //计算两点的欧式距离
        float distP(PointT &p1,PointT &p2);
        //是否存在中心漂移
        bool exitCenterShift(vector<PointT> &prev,vector<PointT> &curent);

    };
};

#endif // OREZ_CLUSTERING_H
