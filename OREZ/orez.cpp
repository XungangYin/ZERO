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
    viewer->addPointCloud(orezIO->loadPCDRGB("../../data/pcl_logo.pcd"),"pcl_logo");
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
        viewer->removePointCloud("pcl_logo");
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
            creatTreeWidgetItem(info);
            viewer->addPointCloud(pc,orezIO->file_name);
            viewer->resetCamera();
            ui->qvtkwidget->update();
        }

    }else{                         //多个点云合并显示

    }

 //   QTreeWidgetItem *item_1 = new QTreeWidgetItem();

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
            viewer->addPointCloud(pc,orezIO->file_name);
            PointCloudInfo<PointCloudTRGB::Ptr> info;
            info.p = pc;
            info.path = path;
            info.file_name = orezIO->file_name;
            info.size = this->orezIO->size;
            info.dim = this->orezIO->dim;
            cout<<info.file_name<<endl;
            v_PCRGBI.push_back(info);

            creatTreeWidgetItem(info);

            status = true;
            break;
        }else{
            if(i==14){                    //若没有r，则用普通方式读取
               PointCloudT::Ptr pc = orezIO->loadPCD(path);
               viewer->addPointCloud(pc,orezIO->file_name);
               PointCloudInfo<PointCloudT::Ptr> info;
               info.p = pc;
               info.path = path;
               info.file_name = orezIO->file_name;
               info.size = this->orezIO->size;
               info.dim = this->orezIO->dim;
               v_PCI.push_back(info);

               creatTreeWidgetItem(info);
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

    v_PCI.clear();
    v_PCRGBI.clear();

    QTreeWidgetItemIterator it(ui->pointCloudTree);
    /* while (*it) {
             //do something like
            cout<<(*it)->text(0).toStdString()<<endl;
            it++;
        } */

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

template <class T>
bool OREZ::creatTreeWidgetItem(T info){
   if(info.p = nullptr)
       return false;
   else{
        QTreeWidgetItem *title = new QTreeWidgetItem(ui->pointCloudTree);
        title->setText(0,QString::fromStdString(info.file_name));
        title->setCheckState(0, Qt::Checked);
        //检测节点的状态改变 .信号槽函数不能带参数
        connect(ui->pointCloudTree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(widgetChange(QTreeWidgetItem *)));
      //  connect(ui->pointCloudTree,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(widgetChange(QTreeWidgetItem *)));

        QTreeWidgetItem *g = new QTreeWidgetItem(title);
        //------------------TextEdit------------------
        QTextEdit *textEdit = new QTextEdit(this);
        textEdit->setFixedHeight(50);
        QString dim  = QString::fromStdString(info.dim);
        std::string size = std::to_string(info.size); //将size_t转为字符串
        QString qsize = QString::fromStdString(size);
        textEdit->setText("Vertices  :  "+qsize);
        textEdit->append( "Dimension :  "+dim);
        textEdit->setReadOnly(true);
        textEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");//通过css设置为无边框
        ui->pointCloudTree->setItemWidget(g,0,textEdit);
        return true;
   }
}
void OREZ::widgetChange(QTreeWidgetItem * state){
   QString qstr = state->text(0);  //获取当前点击的item的text作为电晕id
   std::string str  = qstr.toStdString();
    if(state->checkState(0) == Qt::Checked){
        std::vector<PointCloudInfo<PointCloudT::Ptr>>::iterator it = v_PCI.begin();
        for(it;it != v_PCI.end();it++){
            if(str == it->file_name){
                this->viewer->addPointCloud(it->p,str);
                break;
            }
        }
        std::vector<PointCloudInfo<PointCloudTRGB::Ptr>>::iterator it_rgb = v_PCRGBI.begin();
        for(it_rgb;it_rgb != v_PCRGBI.end();it_rgb++){
            if(str == it_rgb->file_name){
                this->viewer->addPointCloud(it_rgb->p,str);
                break;
            }
        }
        ui->qvtkwidget->update();
    }
    else{

        this->viewer->removePointCloud(str);
        ui->qvtkwidget->update();
    }
}

//法向估计
void OREZ::on_normal_action_19_triggered()
{

}
