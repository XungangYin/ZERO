#include "mlsnormaldialog.h"
#include "ui_mlsnormaldialog.h"

MLSNormalDialog::MLSNormalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MLSNormalDialog)
{
    ui->setupUi(this);
  //  radius  =0.0;
}

MLSNormalDialog::~MLSNormalDialog()
{
    delete ui;
    ui->lineEdit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    ui->lineEdit->setText("1.0");
    ui->lineEdit->setValidator(new QDoubleValidator(0.0,100000.0,6,this));
}

float MLSNormalDialog::getRadius(){
    return ui->lineEdit->text().toDouble();
}
