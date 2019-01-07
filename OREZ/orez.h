#ifndef OREZ_H
#define OREZ_H

#include <iostream>
#include <string>
//QT
#include <QMainWindow>
#include <QFileDialog>
#include <QDockWidget>
#include <QMessageBox>
#include <QString>
//pcl
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
//vtk
#include <vtkRenderWindow.h>

typedef pcl::PointXYZ PointT;
typedef pcl::PointXYZRGB PointTRGB;
typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::PointCloud<PointTRGB> PointCloudTRGB;

using namespace  std;

namespace Ui {
class OREZ;
}

class OREZ : public QMainWindow
{
    Q_OBJECT

public:
    explicit OREZ(QWidget *parent = 0);
    ~OREZ();

private:
    Ui::OREZ *ui;

protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    PointCloudT::Ptr cloud;

private slots:
    void on_action_3_triggered();  //关闭窗口

    void on_action_triggered();     //打开文件

    void on_action_5_triggered();

public:
     PointCloudTRGB::Ptr loadPCDRGB(const string &str);
     PointCloudT::Ptr loadPCD(const string &str);
     bool addPCDFileView(string &path);

private:
    //vector<>

};


#endif // OREZ_H

