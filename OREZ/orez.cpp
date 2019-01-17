#include "orez.h"
#include "ui_orez.h"

OREZ::OREZ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OREZ)
{
    ui->setupUi(this);
    this->setWindowTitle("YXG");
    this->setFixedSize(1200,900);
    //初化输入模块
    orezIO =  new OrezIO;
    //设置默认点云
    initDocketWidget();

   // cloud.reset(new PointCloudTRGB);
  //  cloud =orezIO->loadPCDRGB("../../data/pcl_logo.pcd");

    //设置QVTK
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer",false));
    viewer->addPointCloud(orezIO->loadPCDRGB("../../data/pcl_logo.pcd"),"cloud");
    viewer->resetCamera();

    ui->qvtkwidget->SetRenderWindow(viewer->getRenderWindow());
    //将VTK与pcl的交互方式结合起来
    viewer->setupInteractor(ui->qvtkwidget->GetInteractor(),ui->qvtkwidget->GetRenderWindow());
    this->setCentralWidget(ui->qvtkwidget);
    ui->qvtkwidget->update();
}

OREZ::~OREZ()
{
    delete ui;
    delete orezIO;
}

//关闭
void OREZ::on_action_3_triggered()
{
    this->close();
}

//导入一个或者多个点云文件
void OREZ::on_action_triggered()
{
    //QString path = QApplication::applicationDirPath();
    QStringList files = QFileDialog::getOpenFileNames(this, "打开点云文件",/*path*/"../../data","PointCloud(*.pcd *.ply *.asc)" );
    if(files.isEmpty()){
        QMessageBox::warning(this,"警告：","文件为空");
        return;
    }

    std::string std_path;
    if(files.size() ==1){           //单个点云
        viewer->removeAllPointClouds();
       // file_name.push_back(getFileName(files[0]));
        std_path = files[0].toStdString();
        if(files[0].endsWith(".pcd",Qt::CaseInsensitive)){
             addPCDFileView(std_path);
        }else if(files[0].endsWith(".asc",Qt::CaseInsensitive)){
            PointCloudT::Ptr pc =  orezIO->ascToPCD(std_path);
            PointCloudInfo<PointCloudT::Ptr> info;
            info.p = pc;
            info.path = std_path;
            info.file_name = orezIO->file_name;
            info.size = this->orezIO->size;
            info.dim = this->orezIO->dim;
            v_PCI.push_back(info);
           // cout<<info.file_name<<endl;

//            QTreeWidgetItem *item_1 = new QTreeWidgetItem( ui->pointCloudTree);
//            //item_1->setText(0,QString::fromStdString(info.file_name));
//            QCheckBox *worldElevation = new QCheckBox(this);
//            worldElevation->setText(QString::fromStdString(info.file_name));
//            worldElevation->setCheckState(Qt::Checked);
//            ui->pointCloudTree->setItemWidget(item_1, 0, worldElevation);


            QTreeWidgetItem *w = new QTreeWidgetItem(ui->pointCloudTree);
            w->setText(0,QString::fromStdString(info.file_name));
            w->setCheckState(0, Qt::Checked);

            QTreeWidgetItem *g = new QTreeWidgetItem(w);
            QCheckBox *pCheckBoxWorldImage = new QCheckBox(this);
            pCheckBoxWorldImage->setText(QString::fromLocal8Bit("显隐"));
            pCheckBoxWorldImage->setCheckState(Qt::Checked);
              // 连接信号槽
            ui->pointCloudTree->setItemWidget(g, 0, pCheckBoxWorldImage);

            viewer->addPointCloud(pc);
            viewer->resetCamera();
            ui->qvtkwidget->update();
        }

    }else{                         //多个点云合并显示

    }

    QTreeWidgetItem *item_1 = new QTreeWidgetItem();

}

bool OREZ::addPCDFileView(const string &path){
    /**判断打开的文件是否带有RGB字段
      *主要思想是通过判断PCD文件的第三行是否含有rgb字符
    */
    static bool status = false;
    char tmp[50];
    ifstream open_file;
    open_file.open(path,ios::in);
    if(!open_file){
        cerr<<"文件不存在"<<endl;
        return false;
    }
    else{
        unsigned int count = 0;
        while (open_file.getline(tmp,50)) {
            count++;
            if(count == 3) break;        //获取第三行字段
            }
    }
    for(unsigned int i = 5; i<15;++i){    //判断是否 r字符，只判断后几个字符即可
        if(tmp[i] == 'r'){
            PointCloudTRGB::Ptr pc = orezIO->loadPCDRGB(path);
            viewer->addPointCloud(pc);
            PointCloudInfo<PointCloudTRGB::Ptr> info;
            info.p = pc;
            info.path = path;
            info.file_name = orezIO->file_name;
            info.size = this->orezIO->size;
            info.dim = this->orezIO->dim;
            cout<<info.file_name<<endl;
            v_PCRGBI.push_back(info);
            status = true;
            break;
        }else{
            if(i==14){                    //若没有r，则用普通方式读取
               PointCloudT::Ptr pc = orezIO->loadPCD(path);
               viewer->addPointCloud(pc);
               PointCloudInfo<PointCloudT::Ptr> info;
               info.p = pc;
               info.path = path;
               info.file_name = orezIO->file_name;
               info.size = this->orezIO->size;
               info.dim = this->orezIO->dim;
               v_PCI.push_back(info);
               cout<<info.file_name<<endl;
               status = true;
                break;
            }
        }
    }

    if(status){
        viewer->resetCamera();
        ui->qvtkwidget->update();
        return status;
    }
}

//清空视口内容
void OREZ::on_action_5_triggered()
{
    viewer->removeAllPointClouds();
    ui->qvtkwidget->update();
    v_PointCloud.clear();
    v_PointCloudRGB.clear();
}

void OREZ::updateMessage(QString info){
     ui->statusBar->showMessage(info,100000);
}

void OREZ::initDocketWidget(){
    ui->LayerDialog->setFeatures(QDockWidget::AllDockWidgetFeatures);
    ui->pointCloudTree->setHeaderLabel("PC Tree");
    ui->LayerDialog->setWidget(ui->pointCloudTree);   // 只有这样,treewidget才随Docketwidget移动
    QAction *action = ui->LayerDialog->toggleViewAction();
    ui->mainToolBar->addAction(action);
}


//std::string OREZ::getFileName(std::string path){
//    QString p = QString::fromStdString(path);
//    QFileInfo fileinfo(p);
//    return  fileinfo.fileName().toStdString();
//}
template <class T>
size_t OREZ::getPointCloudSize(const T t){
    if(t)
        return t->points.size();
    else{
        std::cout<<"点云不存在"<<std::endl;
        return 0;
    }
}

template<class T>
std::string OREZ::getPontCloudDim(const T t){
     std::string str =  pcl::getFieldsList(t);
     return str;
}
