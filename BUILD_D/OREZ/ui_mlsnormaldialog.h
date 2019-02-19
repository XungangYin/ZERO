/********************************************************************************
** Form generated from reading UI file 'mlsnormaldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MLSNORMALDIALOG_H
#define UI_MLSNORMALDIALOG_H

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

class Ui_MLSNormalDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *MLSNormalDialog)
    {
        if (MLSNormalDialog->objectName().isEmpty())
            MLSNormalDialog->setObjectName(QStringLiteral("MLSNormalDialog"));
        MLSNormalDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(MLSNormalDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(MLSNormalDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 110, 113, 25));
        label = new QLabel(MLSNormalDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 110, 121, 21));

        retranslateUi(MLSNormalDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MLSNormalDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MLSNormalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MLSNormalDialog);
    } // setupUi

    void retranslateUi(QDialog *MLSNormalDialog)
    {
        MLSNormalDialog->setWindowTitle(QApplication::translate("MLSNormalDialog", "Dialog", nullptr));
        lineEdit->setText(QApplication::translate("MLSNormalDialog", "1.0", nullptr));
        label->setText(QApplication::translate("MLSNormalDialog", "\350\257\267\350\276\223\345\205\245\346\220\234\347\264\242\345\215\212\345\276\204:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MLSNormalDialog: public Ui_MLSNormalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MLSNORMALDIALOG_H
