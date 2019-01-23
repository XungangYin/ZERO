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
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;

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
        label = new QLabel(NormalEstDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 110, 301, 20));
        label_2 = new QLabel(NormalEstDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 131, 20));
        lineEdit = new QLineEdit(NormalEstDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 150, 113, 25));

        retranslateUi(NormalEstDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NormalEstDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NormalEstDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NormalEstDialog);
    } // setupUi

    void retranslateUi(QDialog *NormalEstDialog)
    {
        NormalEstDialog->setWindowTitle(QApplication::translate("NormalEstDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("NormalEstDialog", "\350\257\267\350\276\223\345\205\245\346\255\243\346\225\264\346\225\260(\345\273\272\350\256\256\345\217\226\345\200\274\350\214\203\345\233\264[8-25]\344\271\213\351\227\264):", nullptr));
        label_2->setText(QApplication::translate("NormalEstDialog", "Neighbor Number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NormalEstDialog: public Ui_NormalEstDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALESTDIALOG_H
