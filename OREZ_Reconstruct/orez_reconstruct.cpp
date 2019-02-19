#include "orez_reconstruct.h"


OREZ_Reconstruct::OREZ_Reconstruct()
{
  //  kdtree.reset(new pcl::search::KdTree<PointCloudNormal>());
    common = new Common;
}

pcl::PolygonMesh OREZ_Reconstruct::poissonReconstruction(PointCloudT::Ptr p,bool confidence, unsigned int depth, unsigned int samplePerNode, float scale/*, unsigned int solverDivide*/){
    pcl::Poisson<pcl::PointNormal> po;
    pcl::search::KdTree<pcl::PointNormal>::Ptr tree(new pcl::search::KdTree<pcl::PointNormal>);
    auto normal =  common->normalEstimation(p,8);
    PointCloudWithNormal::Ptr cloud_with_normal (new PointCloudWithNormal);
    pcl::concatenateFields(*p,*normal,*cloud_with_normal);
    po.setConfidence(confidence); //是否使用法向量的长度作为置信信息。如果为false，则对法线进行归一化处理
    po.setDegree(2);
    po.setDepth(depth); //设置重建算法中八叉树的深度。（由于八叉树自适应点云，所以该值仅为最大深度）
    po.setIsoDivide(8); //设置等值面提取时的深度参数,设置该值可避免重建时可能的内存溢出，实践表明设置为7～8比较合适，当该值大于9时，内存使用明显减少，但是重建时间会变长
    po.setManifold(false); //流行标志（若为true，则对细分三角形添加形心）
    po.setOutputPolygons(false); //设置是否输出多边形，ture输出为多边形，false输出三角形 重建后的曲面
    po.setSamplesPerNode(samplePerNode);//设置每个八叉树节点的最小采样数目。（噪声较小是 1～5,较大时15～20），有利于得到最终平滑无噪声的曲面
    po.setScale(scale); //设置用于重构的立方体直径和样本边界立方体直径的比率。
    po.setSolverDivide(10); //设置求解线性方程组的Gauss-Seidel迭代方法的深度

    po.setInputCloud(cloud_with_normal);
    po.setSearchMethod(tree);

    po.performReconstruction(mesh);

    return mesh;
}

pcl::PolygonMesh OREZ_Reconstruct::poissonReconstruction(PointCloudTRGB::Ptr p,bool confidence, unsigned int depth, unsigned int samplePerNode, float scale/*, unsigned int solverDivide*/){
    pcl::Poisson<pcl::PointXYZRGBNormal> po;
    pcl::search::KdTree<pcl::PointXYZRGBNormal>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGBNormal>);
    auto normal =  common->normalEstimation(p,8);
    pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normal(new  pcl::PointCloud<pcl::PointXYZRGBNormal>);
    //pcl::PointXYZRGBNormal::Ptr cloud_with_normal;
    pcl::concatenateFields(*p,*normal,*cloud_with_normal);
    po.setConfidence(confidence); //是否使用法向量的长度作为置信信息。如果为false，则对法线进行归一化处理
    po.setDegree(2);
    po.setDepth(depth); //设置重建算法中八叉树的深度。（由于八叉树自适应点云，所以该值仅为最大深度）
    po.setIsoDivide(8); //设置等值面提取时的深度参数,设置该值可避免重建时可能的内存溢出，实践表明设置为7～8比较合适，当该值大于9时，内存使用明显减少，但是重建时间会变长
    po.setManifold(false); //流行标志（若为true，则对细分三角形添加形心）
    po.setOutputPolygons(false); //设置是否输出多边形，ture输出为多边形，false输出三角形 重建后的曲面
    po.setSamplesPerNode(samplePerNode);//设置每个八叉树节点的最小采样数目。（噪声较小是 1～5,较大时15～20），有利于得到最终平滑无噪声的曲面
    po.setScale(scale); //设置用于重构的立方体直径和样本边界立方体直径的比率。
    po.setSolverDivide(10); //设置求解线性方程组的Gauss-Seidel迭代方法的深度

    po.setInputCloud(cloud_with_normal);
    po.setSearchMethod(tree);

    po.performReconstruction(mesh);

    return mesh;
}
