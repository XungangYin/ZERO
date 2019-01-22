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

//othres
#include "../OREZ_IO/orezio.h"
#include "../common.h"
#include "../Common/common.h"
#include "normalestdialog.h"


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

    void on_normal_action_19_triggered();

public:
    bool addPCDFileView(const string &path);

    void updateMessage(QString info); //状态栏显示点云文件名，点数，类型(xyzOrrgb)

    //std::string getFileName(std::string path); //获取点云文件的名字
    template <class T>
    size_t getPointCloudSize(const T t);  //获取点云大小

    template<class T>
    std::string getPontCloudDim(const T t); //获取点云的维度信息

    template <class T>
    bool  creatTreeWidgetItem(T t);

    //获取current_id所对应的PCinfor


public slots:
    void widgetChange(QTreeWidgetItem * state);


private:
    //构造默认的显示点云
    PointCloudTRGB::Ptr cloud;
    //IO模块
    OrezIO *orezIO;
    //common模块
    Common *common;
    //保存点云基础信息数组
    std::vector<PointCloudInfo<PointCloudT::Ptr>> v_PCI;
    std::vector<PointCloudInfo<PointCloudTRGB::Ptr>> v_PCRGBI;
    void initDocketWidget();

    //存贮treewidget中当前选中点云的唯一id
    std::string current_id;
};


#endif // OREZ_H

