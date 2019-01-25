#include "filtervoxeldialog.h"
#include "ui_filtervoxeldialog.h"

FilterVoxelDialog::FilterVoxelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterVoxelDialog)
{
    ui->setupUi(this);

    this->setWindowTitle(u8"体素网格滤波");

    //使用正则表达式控制输入类型
 //   QRegExp regExp("^\d+(\.\d+)?$");//创建了一个模式
  //  QRegExpValidator *pattern= new QRegExpValidator(regExp, this);//创建了一个表达式

    ui->lineEdit->setFixedWidth(150);
    ui->lineEdit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit->setText("0.0"); //默认
    ui->lineEdit->setValidator(new QDoubleValidator(0.0,10000.0,6,this));  //小数点后6位有效数字


    ui->lineEdit_2->setFixedWidth(150);
    ui->lineEdit_2->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit_2->setText("0.0"); //默认
    ui->lineEdit_2->setValidator(new QDoubleValidator(0.0,10000.0,6,this));

    ui->lineEdit_3->setFixedWidth(150);
    ui->lineEdit_3->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit_3->setText("0.0"); //默认
    ui->lineEdit_3->setValidator(new QDoubleValidator(0.0,10000.0,6,this));
}

double FilterVoxelDialog::getX(){
    QString str= ui->lineEdit->text();
    return str.toDouble();
}
double FilterVoxelDialog::getY(){
    QString str= ui->lineEdit_2->text();
    return str.toDouble();
}
double FilterVoxelDialog::getZ(){
    QString str= ui->lineEdit_3->text();
    return str.toDouble();
}

FilterVoxelDialog::~FilterVoxelDialog()
{
    delete ui;
}
