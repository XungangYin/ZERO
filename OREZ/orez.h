#ifndef OREZ_H
#define OREZ_H

//QT
#include <QMainWindow>
#include <QFileDialog>
#include <QDockWidget>
#include <QMessageBox>
#include <QString>

//othres
#include "../OREZ_IO/orezio.h"
#include "../common.h"

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
    bool addPCDFileView(const string &path);

private:
    OrezIO *orezIO;

};


#endif // OREZ_H

