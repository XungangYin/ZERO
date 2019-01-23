#ifndef NORMALESTDIALOG_H
#define NORMALESTDIALOG_H

#include <QDialog>

namespace Ui {
class NormalEstDialog;
}

class NormalEstDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NormalEstDialog(QWidget *parent = 0);
    ~NormalEstDialog();
    int getValue();

private:
    Ui::NormalEstDialog *ui;
};

#endif // NORMALESTDIALOG_H
