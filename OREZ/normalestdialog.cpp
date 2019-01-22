#include "normalestdialog.h"
#include "ui_normalestdialog.h"

NormalEstDialog::NormalEstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormalEstDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(u8"法向量计算");
  //  this->setWindowFlags(Qt::FramelessWindowHint);
}

NormalEstDialog::~NormalEstDialog()
{
    delete ui;
}

int NormalEstDialog::getValue(){

    return k;
}
