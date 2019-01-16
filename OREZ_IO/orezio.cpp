#include "orezio.h"


OrezIO::OrezIO()
{
}


//读取PCDRGB文件
PointCloudTRGB::Ptr OrezIO::loadPCDRGB(const std::string &str){
    PointCloudTRGB::Ptr pc(new PointCloudTRGB);
    if(pcl::io::loadPCDFile(str,*pc) == -1){
        PCL_ERROR("打开PCD文件失败");
        return nullptr;
    }
    std::string path = str;
    this->path = path;
    this->file_name = this->getFileName(path);
    this->dim = this->getPontCloudDim(*pc);
    this->size = this->getPointCloudSize(pc);

    return pc;
}
 //读取PCD文件
PointCloudT::Ptr OrezIO::loadPCD(const std::string &str){
    PointCloudT::Ptr pc(new PointCloudT);
    if(pcl::io::loadPCDFile(str,*pc) == -1){
        PCL_ERROR("打开PCD文件失败");
        return nullptr;
    }
    std::string path = str;
    this->path = path;
    this->file_name = this->getFileName(path);
    this->dim = this->getPontCloudDim(*pc);
    this->size = this->getPointCloudSize(pc);
    return pc;
}


PointCloudT::Ptr OrezIO::ascToPCD(const std::string ascPath){
    PointCloudT::Ptr pc(new PointCloudT);
    pc->height =1;
    std::ifstream file(ascPath);
    std::string line;
    std::vector<std::string> v_str;
    if(!file){
        std::cerr<<"打开asc文件失败"<<std::endl;
    }

    PointT p;
    try{
        while(!file.eof()){
            getline(file,line);
            if(line == "")
                continue;
            boost::trim(line); //去掉空格
            //拆分出换行和table键信息
            boost::split(v_str,line,boost::is_any_of("\t\r"),boost::token_compress_on);
            std::stringstream  ss(line);
            ss.imbue(std::locale::classic()); //设置本地环境
            ss>>p.x>>p.y>>p.z;
            pc->points.push_back(p);
        }

        pc->width = static_cast<uint32_t>(pc->points.size());
        if(pc->width <1)
            throw ascPath;

        file.close();

        std::string path = ascPath;
        this->path = path;
        this->file_name = this->getFileName(path);
        this->dim = this->getPontCloudDim(*pc);
        this->size = this->getPointCloudSize(pc);
        return pc;
    }
    catch (const char *exception){
         file.close();
         if(pc->size() == 0)
            return nullptr;
    }

}


std::string OrezIO::getFileName(std::string path){
    QString p = QString::fromStdString(path);
    QFileInfo fileinfo(p);
    return  fileinfo.fileName().toStdString();
}

template <class T>
size_t OrezIO::getPointCloudSize(const T t){
    if(t)
        return t->points.size();
    else{
        std::cout<<"点云不存在"<<std::endl;
        return 0;
    }
}
template<class T>
std::string OrezIO::getPontCloudDim(const T t){
     std::string str =  pcl::getFieldsList(t);
     return str;
}
