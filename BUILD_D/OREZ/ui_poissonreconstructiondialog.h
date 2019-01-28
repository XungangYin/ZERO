/********************************************************************************
** Form generated from reading UI file 'poissonreconstructiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POISSONRECONSTRUCTIONDIALOG_H
#define UI_POISSONRECONSTRUCTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PoissonReconstructionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;

    void setupUi(QDialog *PoissonReconstructionDialog)
    {
        if (PoissonReconstructionDialog->objectName().isEmpty())
            PoissonReconstructionDialog->setObjectName(QStringLiteral("PoissonReconstructionDialog"));
        PoissonReconstructionDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(PoissonReconstructionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(PoissonReconstructionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 171, 17));
        lineEdit = new QLineEdit(PoissonReconstructionDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 40, 113, 25));
        lineEdit_2 = new QLineEdit(PoissonReconstructionDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 80, 111, 25));
        label_2 = new QLabel(PoissonReconstructionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 141, 17));
        label_4 = new QLabel(PoissonReconstructionDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 120, 141, 17));
        lineEdit_4 = new QLineEdit(PoissonReconstructionDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(190, 120, 111, 25));
        lineEdit_5 = new QLineEdit(PoissonReconstructionDialog);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(190, 170, 111, 25));
        label_5 = new QLabel(PoissonReconstructionDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 170, 161, 17));

        retranslateUi(PoissonReconstructionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PoissonReconstructionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PoissonReconstructionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PoissonReconstructionDialog);
    } // setupUi

    void retranslateUi(QDialog *PoissonReconstructionDialog)
    {
        PoissonReconstructionDialog->setWindowTitle(QApplication::translate("PoissonReconstructionDialog", "\346\263\212\346\235\276\351\207\215\345\273\272", nullptr));
        label->setText(QApplication::translate("PoissonReconstructionDialog", "\346\230\257\345\220\246\345\220\257\347\224\250\346\263\225\347\272\277\346\240\207\350\256\260(bool):", nullptr));
        label_2->setText(QApplication::translate("PoissonReconstructionDialog", "\345\205\253\345\217\211\346\240\221\346\234\200\345\244\247\346\267\261\345\272\246:", nullptr));
        label_4->setText(QApplication::translate("PoissonReconstructionDialog", "\350\212\202\347\202\271\351\207\207\346\240\267\346\225\260\347\233\256[1-20]:", nullptr));
        label_5->setText(QApplication::translate("PoissonReconstructionDialog", "\350\256\276\347\275\256Gauss-Seidel\346\267\261\345\272\246:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PoissonReconstructionDialog: public Ui_PoissonReconstructionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POISSONRECONSTRUCTIONDIALOG_H
