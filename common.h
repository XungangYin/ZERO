//啥也不做，只是提供共有头文件的包含

#include <iostream>
#include <string>
#include <vector>
//pcl
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/PCLHeader.h>
//vtk
#include <vtkRenderWindow.h>

//othres
#include "../OREZ_IO/orezio.h"

typedef pcl::PointXYZ PointT;
typedef pcl::PointXYZRGB PointTRGB;
typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::PointCloud<PointTRGB> PointCloudTRGB;

typedef pcl::PointNormal PointNormal;
typedef pcl::PointCloud<pcl::Normal> PointCloudNormal;
typedef pcl::PointCloud<PointNormal> PointCloudWithNormal;
