#ifndef OREZ_RECONSTRUCT_H
#define OREZ_RECONSTRUCT_H

#include "orez_reconstruct_global.h"
#include "../common.h"
#include "../Common/common.h"

#include <pcl/surface/poisson.h> //泊松
#include <pcl/surface/marching_cubes.h> //mc重建

class OREZ_RECONSTRUCTSHARED_EXPORT OREZ_Reconstruct
{

public:
    OREZ_Reconstruct();

    pcl::PolygonMesh poissonReconstruction(PointCloudT::Ptr p,bool confidence,unsigned int depth,unsigned int samplePerNode,float scale/*,unsigned int solverDivide*/);
    pcl::PolygonMesh poissonReconstruction(PointCloudTRGB::Ptr p,bool confidence,unsigned int depth,unsigned int samplePerNode,float scale/*,unsigned int solverDivide*/);


private:
    pcl::PolygonMesh mesh;
   // pcl::search::KdTree<PointNormal>::Ptr kdtree;
    //泊松重建参数
    bool confidence;
    unsigned int depth;
    unsigned int samplePerNode;
    float scale;
    unsigned int solverDivide;

    //法向
    Common *common;
};

#endif // OREZ_RECONSTRUCT_H
