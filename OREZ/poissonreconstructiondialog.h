#ifndef POISSONRECONSTRUCTIONDIALOG_H
#define POISSONRECONSTRUCTIONDIALOG_H

#include <QDialog>

namespace Ui {
class PoissonReconstructionDialog;
}

class PoissonReconstructionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PoissonReconstructionDialog(QWidget *parent = 0);
    ~PoissonReconstructionDialog();
    //poisson
    bool getConfidence();
 //   unsigned int getDegree();
    unsigned int getSamplePerNode();
  //  unsigned int getSolverDiverde();
    unsigned int getDepth();
    float getScale();

private:
    Ui::PoissonReconstructionDialog *ui;
};

#endif // POISSONRECONSTRUCTIONDIALOG_H
