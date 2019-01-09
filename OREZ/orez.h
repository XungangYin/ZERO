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

private slots:
    void on_action_3_triggered();    //关闭窗口

    void on_action_triggered();      //打开文件

    void on_action_5_triggered();    //重置视口

public:
    bool addPCDFileView(const string &path);

    void updateMessage(QString info); //状态栏显示点云文件名，点数，类型(xyzOrrgb)

    QString getFileName(const QString &path); //获取点云文件的名字
private:
    //构造默认的显示点云
    PointCloudT::Ptr cloud;
    //IO模块
    OrezIO *orezIO;
    //保存加载进来的数据指针
    vector<PointCloudT::Ptr> v_PointCloud;
    vector<PointCloudTRGB::Ptr> v_PointCloudRGB;

    //保存点云的名字
    QStringList file_name;
};


#endif // OREZ_H

