#include "normalestdialog.h"
#include "ui_normalestdialog.h"

NormalEstDialog::NormalEstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormalEstDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(u8"法向量计算");
  //  this->setWindowFlags(Qt::FramelessWindowHint);

    //设置默认lineEdit只能输入正整数,范围在1-500之间.建议设置在8-25之间
    ui->lineEdit->setFixedWidth(50);
    ui->lineEdit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit->setText("8"); //默认近邻个数
    ui->lineEdit->setValidator(new QIntValidator(1, 500, ui->lineEdit));
}

NormalEstDialog::~NormalEstDialog()
{
    delete ui;
}

int NormalEstDialog::getValue(){
    QString str= ui->lineEdit->text();
    return str.toInt();
}
