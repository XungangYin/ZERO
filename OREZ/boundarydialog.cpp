#include "boundarydialog.h"
#include "ui_boundarydialog.h"

BoundaryDialog::BoundaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoundaryDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(u8"边界识别");
  //  this->setWindowFlags(Qt::FramelessWindowHint);

    //设置默认lineEdit只能输入正整数,范围在1-500之间.建议设置在8-25之间
    ui->lineEdit->setFixedWidth(50);
    ui->lineEdit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit->setText("8"); //默认近邻个数
    ui->lineEdit->setValidator(new QIntValidator(1, 500, ui->lineEdit));

    ui->lineEdit_2->setFixedWidth(50);
    ui->lineEdit_2->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit_2->setText("20"); //默认近邻个数
    ui->lineEdit_2->setValidator(new QIntValidator(1, 500, ui->lineEdit));
}

BoundaryDialog::~BoundaryDialog()
{
    delete ui;
}

unsigned int BoundaryDialog::getNormalValue(){
    QString str= ui->lineEdit->text();
    return str.toInt();
}
unsigned int BoundaryDialog::getBoundaryValve(){
    QString str= ui->lineEdit_2->text();
    return str.toInt();
}
