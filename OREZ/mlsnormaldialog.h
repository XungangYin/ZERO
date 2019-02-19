#ifndef MLSNORMALDIALOG_H
#define MLSNORMALDIALOG_H

#include <QDialog>

namespace Ui {
class MLSNormalDialog;
}

class MLSNormalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MLSNormalDialog(QWidget *parent = 0);
    ~MLSNormalDialog();

    float getRadius();
private:
    Ui::MLSNormalDialog *ui;
    //float radius;
};

#endif // MLSNORMALDIALOG_H
