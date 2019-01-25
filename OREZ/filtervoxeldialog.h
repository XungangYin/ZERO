#ifndef FILTERVOXELDIALOG_H
#define FILTERVOXELDIALOG_H

#include <QDialog>

namespace Ui {
class FilterVoxelDialog;
}

class FilterVoxelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterVoxelDialog(QWidget *parent = 0);
    ~FilterVoxelDialog();

     double getX();
     double getY();
     double getZ();


private:
    Ui::FilterVoxelDialog *ui;

    double dx = 0 ,dy = 0,dz = 0;
};

#endif // FILTERVOXELDIALOG_H
