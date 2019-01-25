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
    common = new Common;

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
    delete common;
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

    }else{   //多个点云同时加载显示
        this->viewer->removePointCloud("pcl_logo");
        for(int i = 0; i< files.size();i++){
             std_path = files[i].toStdString();
             if(files[i].endsWith(".asc",Qt::CaseInsensitive)){
                 PointCloudT::Ptr pc =  orezIO->ascToPCD(std_path);
                 PointCloudInfo<PointCloudT::Ptr> info;
                 info.p = pc;
                 info.path = std_path;
                 info.file_name = orezIO->file_name;
                 info.size = this->orezIO->size;
                 info.dim = this->orezIO->dim;
                 v_PCI.push_back(info);
                 creatTreeWidgetItem(info);
                 viewer->addPointCloud(pc,info.file_name);
                 viewer->resetCamera();
                 ui->qvtkwidget->update();
             }else{
                addPCDFileView(std_path);
             }
        }
    }
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

    ui->pointCloudTree->clear();

   /* QTreeWidgetItemIterator it(ui->pointCloudTree);

     while (*it) {
             //do something like
            cout<<(*it)->text(0).toStdString()<<endl;
            it++;
        } */
}

void OREZ::updateMessage(std::string info){
     ui->statusBar->showMessage("Current PointCloud is :  "+QString::fromStdString(info) );
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

   QString qstr = state->text(0);  //获取当前点击的item的text作为点云id
   current_id = qstr.toStdString();
   this->updateMessage(current_id);
   if(state->checkState(0) == Qt::Checked){
         state->setSelected(true);  //改变该item的选中背景色状态
         PointCloudInfo<PointCloudT::Ptr> a=OREZ::getPCInfo(current_id);  //先计算xyz格式的
         if(a.p != nullptr){
              this->viewer->addPointCloud(a.p,current_id);
         }else{
              PointCloudInfo<PointCloudTRGB::Ptr> b = this->getPCRGBInfo(current_id);
              this->viewer->addPointCloud(b.p,current_id);
         }
        ui->qvtkwidget->update();
    }
    else{
        state->setSelected(false);
        this->viewer->removePointCloud(current_id);
        this->viewer->removePointCloud(current_id+"0");//一起删除对应的法向
        ui->qvtkwidget->update();
    }
}

//计算当前选中的item点云的法向量
void OREZ::on_normal_action_19_triggered()
{
    //打开法向估计的对话框,获取k值,然后计算法向量
    NormalEstDialog *normalDia = new NormalEstDialog;
    normalDia->exec();
    int k = normalDia->getValue();
    PointCloudInfo<PointCloudT::Ptr> a=OREZ::getPCInfo(current_id);
    if(a.p != nullptr){
         //point_cloud_normal = common->normalEstimation(a.p,k);

         m_id_normal[current_id] = common->normalEstimation(a.p,k);

    }else{
        PointCloudInfo<PointCloudTRGB::Ptr> b = this->getPCRGBInfo(current_id);
        //point_cloud_normal = common->normalEstimation(b.p,k);
        m_id_normal[current_id] = common->normalEstimation(b.p,k);

    }
}


PointCloudInfo<PointCloudT::Ptr> OREZ::getPCInfo(const string current_id){
    std::vector<PointCloudInfo<PointCloudT::Ptr>>::iterator it = v_PCI.begin();
    for(it;it != v_PCI.end();it++){
         if(current_id == it->file_name){
                return *it;
            }
        }
    PointCloudInfo<PointCloudT::Ptr> flag;
    return flag;
}
PointCloudInfo<PointCloudTRGB::Ptr> OREZ::getPCRGBInfo(const string current_id){
    std::vector<PointCloudInfo<PointCloudTRGB::Ptr>>::iterator it_rgb = v_PCRGBI.begin();
    for(it_rgb;it_rgb != v_PCRGBI.end();it_rgb++){
        if(current_id == it_rgb->file_name){
                 return *it_rgb;
            }
        }
    PointCloudInfo<PointCloudTRGB::Ptr> flag;  //只是作为一个返回标记,并无实际用处
    return flag;
}

void OREZ::on_action_12_triggered(bool checked)
{
    if(checked == true){
        auto normal = m_id_normal.find(current_id);
        if(normal != m_id_normal.end()){
            PointCloudInfo<PointCloudT::Ptr> a = OREZ::getPCInfo(current_id);
            if(a.p != nullptr){
                pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> v(a.p,0,255,0);    //设置点云为绿色
                this->viewer->updatePointCloud(a.p,v,current_id);
                double normal_length = common->estimateDistance(a.p);
               // auto normal = m_id_normal.find(current_id)->second;
                this->viewer->addPointCloudNormals<PointT,pcl::Normal>(a.p,normal->second,10,normal_length*15,current_id+"0");
            }else{
                PointCloudInfo<PointCloudTRGB::Ptr> b = this->getPCRGBInfo(current_id);
                double normal_length = common->estimateDistance(b.p);
                this->viewer->addPointCloudNormals<PointTRGB,pcl::Normal>(b.p,normal->second,10,normal_length*5,current_id+"0");
             }
            ui->qvtkwidget->update();

        }
        else{

              ui->action_12->setChecked(false);
              QMessageBox::warning(this,"警告：","请先计算该点云的法向量...");
        }
    }
    else{
          this->viewer->removePointCloud(current_id+"0");
          ui->qvtkwidget->update();
    }
}

//边界识别
void OREZ::on_action_10_triggered(bool checked)
{
    if(checked == true){
        BoundaryDialog *boundary  = new BoundaryDialog;
        boundary->exec();
        unsigned int k1 = boundary->getNormalValue();
        unsigned int k2 = boundary->getBoundaryValve();
        //此处应该判断current_id是否存在且合理
        PointCloudInfo<PointCloudT::Ptr> a = OREZ::getPCInfo(current_id);
        if(a.p != nullptr){
            PointCloudT::Ptr boundaryP = common->boundaryEstimation(a.p,k1,k2);
           // pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> v(a.p,255,0,0);
            this->viewer->addPointCloud(boundaryP,current_id+"b");
            this->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR,255,0,0,current_id+"b"); //边界点云用红色显示
            this->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,2,current_id+"b");  //设置边界点大小为2个单位

        }else{
            PointCloudInfo<PointCloudTRGB::Ptr> a = this->getPCRGBInfo(current_id);
            PointCloudTRGB::Ptr boundaryP = common->boundaryEstimation(a.p,k1,k2);
            pcl::visualization::PointCloudColorHandlerCustom<PointTRGB> v(a.p,255,0,0);  //设置点云颜色的另一种方式
            this->viewer->addPointCloud(boundaryP,v,current_id+"b");
            this->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,2,current_id+"b");

        }
         ui->qvtkwidget->update();
    }
    else{
       // ui->action_12->setChecked(false);
        this->viewer->removePointCloud(current_id+"b");
        ui->qvtkwidget->update();
        //QMessageBox::warning(this,"警告：","请先计算该点云的边界...");
    }
}

void OREZ::on_action1_triggered(bool checked)
{
    if(checked == true){
        FilterVoxelDialog *voxel_filter = new FilterVoxelDialog;
        voxel_filter->exec();
        //此处应该判断current_id是否存在且合理
        PointCloudInfo<PointCloudT::Ptr> a = OREZ::getPCInfo(current_id);
        if(a.p != nullptr){
            PointCloudT::Ptr filter = common->filterByVoxel(a.p,voxel_filter->getX(),voxel_filter->getY(),voxel_filter->getZ());
           // pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> v(a.p,255,0,0);
            this->viewer->addPointCloud(filter,current_id+"f");
            //this->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR,255,0,0,current_id+"f"); //边界点云用红色显示
            //this->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,2,current_id+"f");  //设置边界点大小为2个单位

        }else{
            PointCloudInfo<PointCloudTRGB::Ptr> a = this->getPCRGBInfo(current_id);
            PointCloudTRGB::Ptr filter = common->filterByVoxelRGB(a.p,voxel_filter->getX(),voxel_filter->getY(),voxel_filter->getZ());
            //pcl::visualization::PointCloudColorHandlerCustom<PointTRGB> v(a.p,255,0,0);  //设置点云颜色的另一种方式
            this->viewer->addPointCloud(filter,current_id+"f");
           // this->viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,2,current_id+"b");

        }
         ui->qvtkwidget->update();
    }
    else{
        this->viewer->removePointCloud(current_id+"f");
        ui->qvtkwidget->update();
    }
}
