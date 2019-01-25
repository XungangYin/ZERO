#ifndef BOUNDARYDIALOG_H
#define BOUNDARYDIALOG_H

#include <QDialog>

namespace Ui {
class BoundaryDialog;
}

class BoundaryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BoundaryDialog(QWidget *parent = 0);
    ~BoundaryDialog();

    unsigned int getNormalValue();
    unsigned int getBoundaryValve();

private:
    Ui::BoundaryDialog *ui;
};

#endif // BOUNDARYDIALOG_H
