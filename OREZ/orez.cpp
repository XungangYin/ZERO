#include "orez.h"
#include "ui_orez.h"

OREZ::OREZ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OREZ)
{
    ui->setupUi(this);
    this->setWindowTitle("YXG");
    this->setFixedSize(800,600);

    //设置默认点云
    cloud.reset(new PointCloudT);
    cloud->points.resize(200);
    for(size_t i = 0; i< 200;++i){
        cloud->points[i].x = 1024 * rand() /(RAND_MAX+1.0f);
        cloud->points[i].y = 1024 * rand() /(RAND_MAX+1.0f);
        cloud->points[i].z = 1024 * rand() /(RAND_MAX+1.0f);
    }

    //设置QVTK
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer",false));
    viewer->addPointCloud(cloud,"cloud");
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
}

//关闭
void OREZ::on_action_3_triggered()
{
    this->close();
}

//导入一个或者多个点云文件
void OREZ::on_action_triggered()
{
    QString path = QApplication::applicationDirPath();
    QStringList files = QFileDialog::getOpenFileNames(this, "打开点云文件",/*path*/"../../OREZ/data","PointCloud(*.pcd *.ply *.asc)" );
    if(files.isEmpty()){
        QMessageBox::warning(this,"警告：","文件为空");
        return;
    }

    static std::string std_path;
    for(size_t i = 0; i< files.size();i++){
        std_path = files[i].toStdString();
        // 如果endsWith第二个参数是默认的Qt::CaseSensitive，则区分大小写，否则Qt::CaseInsensitive不区分
        if(files[i].endsWith(".pcd",Qt::CaseInsensitive)){
               addPCDFileView(std_path);
        }

        if(files[i].endsWith(".asc",Qt::CaseInsensitive)){
               //addPCDFileView(std_path);
        }
    }


    /**判断输入文件的类型
     * @brief ch 判断字符（输入文件的最后一个字符）
     *ch == k:添加vtk文件，ch==d,添加pcd文件，以此类推

    char ch;
    ch = std_path[std_path.length()-1];
    if(ch =='D' || ch == 'd'){
        addPCDFileView(std_path);
    }else if(ch == 'k' || ch=='K'){
        //添加显示VTK文件的函数
    }
 */
}

bool OREZ::addPCDFileView(string &path){
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
            PointCloudTRGB::Ptr pc = loadPCDRGB(path);
            if( viewer->removeAllPointClouds()){   //检测viewer中是否还有其他点
                viewer->addPointCloud(pc,"");
            }else
                viewer->updatePointCloud(pc);

            status = true;
            break;
        }else{
            if(i==14){                    //若没有r，则用普通方式读取
                PointCloudT::Ptr pc = loadPCD(path);
                if( viewer->removeAllPointClouds()){
                    viewer->addPointCloud(pc,"");
                }else
                    viewer->updatePointCloud(pc);
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

//读取PCDRGB文件
 PointCloudTRGB::Ptr OREZ::loadPCDRGB(const string &str){
    PointCloudTRGB::Ptr pc(new PointCloudTRGB);
    if(pcl::io::loadPCDFile(str,*pc) == -1){
        PCL_ERROR("打开PCD文件失败");
    }
    return pc;
}
 //读取PCD文件
PointCloudT::Ptr OREZ::loadPCD(const string &str){
    PointCloudT::Ptr pc(new PointCloudT);
    if(pcl::io::loadPCDFile(str,*pc) == -1){
        PCL_ERROR("打开PCD文件失败");
    }
    return pc;
}


//清空视口内容
void OREZ::on_action_5_triggered()
{
    viewer->removeAllPointClouds();
    ui->qvtkwidget->update();
}
