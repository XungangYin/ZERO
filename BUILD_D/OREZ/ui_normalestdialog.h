/********************************************************************************
** Form generated from reading UI file 'normalestdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALESTDIALOG_H
#define UI_NORMALESTDIALOG_H

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

class Ui_NormalEstDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *NormalEstDialog)
    {
        if (NormalEstDialog->objectName().isEmpty())
            NormalEstDialog->setObjectName(QStringLiteral("NormalEstDialog"));
        NormalEstDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(NormalEstDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(NormalEstDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 150, 113, 25));
        label = new QLabel(NormalEstDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 110, 111, 20));
        label_2 = new QLabel(NormalEstDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 131, 20));

        retranslateUi(NormalEstDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NormalEstDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NormalEstDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NormalEstDialog);
    } // setupUi

    void retranslateUi(QDialog *NormalEstDialog)
    {
        NormalEstDialog->setWindowTitle(QApplication::translate("NormalEstDialog", "Dialog", nullptr));
        lineEdit->setText(QApplication::translate("NormalEstDialog", "NormalEST", nullptr));
        label->setText(QApplication::translate("NormalEstDialog", "\350\257\267\350\276\223\345\205\245\346\255\243\346\225\264\346\225\260:", nullptr));
        label_2->setText(QApplication::translate("NormalEstDialog", "Neighbor Number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NormalEstDialog: public Ui_NormalEstDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALESTDIALOG_H
