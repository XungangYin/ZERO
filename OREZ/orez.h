#ifndef OREZ_H
#define OREZ_H

//QT
#include <QMainWindow>
#include <QFileDialog>
#include <QDockWidget>
#include <QMessageBox>
#include <QString>
#include <QCheckBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QTreeWidgetItem>
#include <QColorDialog>
#include <QPlainTextEdit>

//othres
#include "../OREZ_IO/orezio.h"
#include "../common.h"
#include "../Common/common.h"
#include "../OREZ_Reconstruct/orez_reconstruct.h"

#include "normalestdialog.h"
#include "boundarydialog.h"
#include "filtervoxeldialog.h"
#include "poissonreconstructiondialog.h"
#include "mlsnormaldialog.h"

#include <pcl/visualization/point_cloud_color_handlers.h>
using namespace  std;

////声明一个结构体模板,保存点云信息
template <class T>
struct PointCloudInfo
{
     T p ;
     std::string path = "";
     std::string file_name=  "";
     size_t size = 0;
     std::string dim = "";
    // PointCloudNormal::Ptr normal;
};



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

    void on_normal_action_19_triggered();  //计算当前选中的item点云的法向量

    void on_action_12_triggered(bool checked); //显示当前选中点云的法向量()

    void on_action_10_triggered(bool checked);  //边界识别

    void on_action1_triggered(bool checked);   //体素网格滤波

    void on_actionPoisson_triggered(bool checked);  //泊松重建

    void on_normal_action_mls_triggered(bool checked);  //MLS法向计算

    void on_action_15_triggered();  //给当前点云设置显示颜色

public:
    bool addPCDFileView(const string &path);

    void updateMessage(std::string info); //状态栏显示点云文件名，点数，类型(xyzOrrgb)

    //std::string getFileName(std::string path); //获取点云文件的名字
    template <class T>
    size_t getPointCloudSize(const T t);  //获取点云大小

    template<class T>
    std::string getPontCloudDim(const T t); //获取点云的维度信息

    template <class T>
    bool  creatTreeWidgetItem(T t);

    //根据current_id(string)获取当前那PointCloudInfo
    PointCloudInfo<PointCloudT::Ptr> getPCInfo(const string current_id);
    PointCloudInfo<PointCloudTRGB::Ptr> getPCRGBInfo(const string current_id);



public slots:
    void widgetClick(QTreeWidgetItem * state);


private:
    //构造默认的显示点云
    PointCloudTRGB::Ptr cloud;
    //IO模块
    OrezIO *orezIO;
    //common模块
    Common *common;
    //重建模块
    OREZ_Reconstruct *reconstruct = new OREZ_Reconstruct;

    //保存点云基础信息数组
    std::vector<PointCloudInfo<PointCloudT::Ptr>> v_PCI;
    std::vector<PointCloudInfo<PointCloudTRGB::Ptr>> v_PCRGBI;

    void initDocketWidget();

    //存贮treewidget中当前选中点云的唯一id
    std::string current_id;

    //存储法向量信息
    PointCloudNormal::Ptr point_cloud_normal;
    //map存储current_id和其对应的法向量
    std::map<std::string, PointCloudNormal::Ptr> m_id_normal;
};


#endif // OREZ_H

