#include "poissonreconstructiondialog.h"
#include "ui_poissonreconstructiondialog.h"

PoissonReconstructionDialog::PoissonReconstructionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PoissonReconstructionDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText("true");  //confidece
    ui->lineEdit->setFixedWidth(50);
    ui->lineEdit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit->setValidator(new QIntValidator(1, 500, ui->lineEdit));


    ui->lineEdit_2->setFixedWidth(50);
    ui->lineEdit_2->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit_2->setText("8"); //默认近邻个数 8叉树
    ui->lineEdit_2->setValidator(new QIntValidator(1, 20, ui->lineEdit));


    //ui->lineEdit_4->setText("节点采样数目");
    ui->lineEdit_4->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit_4->setText("15");
    ui->lineEdit_4->setValidator(new QIntValidator(1, 20, ui->lineEdit));


   // ui->lineEdit_5->setText("Gauss 迭代深度");
    ui->lineEdit_5->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit_5->setText("1.2"); //默认
    ui->lineEdit_5->setValidator(new QDoubleValidator(0.0,10000.0,6,this));  //小数点后6位有效数字

}

bool PoissonReconstructionDialog::getConfidence(){
    //return ui->lineEdit->text(); //转化为bool
    return false;
}

unsigned int PoissonReconstructionDialog::getSamplePerNode(){
    return ui->lineEdit_4->text().toInt(); //int
}

unsigned int PoissonReconstructionDialog::getDepth(){
    return ui->lineEdit_2->text().toInt(); //转
}

float PoissonReconstructionDialog::getScale(){
    return ui->lineEdit_5->text().toFloat(); //转
}

PoissonReconstructionDialog::~PoissonReconstructionDialog()
{
    delete ui;
}
