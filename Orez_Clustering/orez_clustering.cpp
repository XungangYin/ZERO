#include "orez_clustering.h"

const float DIST_NEAR_ZERO = 0.001;

Orez_Clustering::Orez_Clustering()
{
}

bool Orez_Clustering::KMeans::setInputCloud(PointCloudT::Ptr &p){
    if(p){
        _p=p;
        return true;
    }else{
        return false;
    }
}

void  Orez_Clustering::KMeans::initCenter(){
    int size = _p->points.size();
    srand(unsigned(time (NULL)));
    for(unsigned int i = 0; i< m_k;i++){
        int seed = random()%(size+1);
        mv_center.push_back(_p->points[seed]);
    }
}

float Orez_Clustering::KMeans::distP(PointT &p1, PointT &p2){
    float  dist = 0;
    float x_diff = 0, y_diff = 0, z_diff = 0;

    x_diff = p1.x - p2.x;
    y_diff = p1.y - p2.y;
    z_diff = p1.z - p2.z;
    dist = sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);

    return dist;
}

void Orez_Clustering::KMeans::updateGroupCenter(vector<VecPoint> &grp_pncloud, vector<PointT> &cer){
    float x, y,z;
    for(unsigned int i=  0;i <m_k; i++){
        x=0;y=0;z=0;
        size_t pnt_num = grp_pncloud[i].size();
        for(unsigned int j = 0;j <pnt_num;j++){
            x+=grp_pncloud[i][j].pnt.x;
            y+=grp_pncloud[i][j].pnt.y;
            z+=grp_pncloud[i][j].pnt.z;
        }
        x /= pnt_num;
        y /= pnt_num;
        z /= pnt_num;
        cer[i].x = x;
        cer[i].y = y;
        cer[i].z = z;
    }
}

bool Orez_Clustering::KMeans::exitCenterShift(vector<PointT> &prev, vector<PointT> &curent)
{
    for(unsigned int i = 0; i< m_k;i++){
        float dist = distP(prev[i],curent[i]);
        if(dist >DIST_NEAR_ZERO)   //只要存在一个，就认为存在漂移
            return true;
    }

    return false;
}

bool Orez_Clustering::KMeans::cluster(){
    initCenter();
    vector<PointT> v_center(m_k);
    size_t pntCount = _p->points.size();

    do{



    }while(true);

}








