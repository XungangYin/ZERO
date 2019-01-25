/********************************************************************************
** Form generated from reading UI file 'boundarydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOUNDARYDIALOG_H
#define UI_BOUNDARYDIALOG_H

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

class Ui_BoundaryDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *BoundaryDialog)
    {
        if (BoundaryDialog->objectName().isEmpty())
            BoundaryDialog->setObjectName(QStringLiteral("BoundaryDialog"));
        BoundaryDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(BoundaryDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(BoundaryDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 80, 113, 25));
        label = new QLabel(BoundaryDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 231, 17));
        label_2 = new QLabel(BoundaryDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 131, 20));
        lineEdit_2 = new QLineEdit(BoundaryDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 180, 113, 25));
        label_3 = new QLabel(BoundaryDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 140, 231, 17));
        label_4 = new QLabel(BoundaryDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 141, 20));

        retranslateUi(BoundaryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BoundaryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BoundaryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BoundaryDialog);
    } // setupUi

    void retranslateUi(QDialog *BoundaryDialog)
    {
        BoundaryDialog->setWindowTitle(QApplication::translate("BoundaryDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("BoundaryDialog", "\350\257\267\350\276\223\345\205\245\346\255\243\346\225\264\346\225\260K_1(\347\224\250\344\272\216\346\263\225\345\220\221\344\274\260\350\256\241):", nullptr));
        label_2->setText(QApplication::translate("BoundaryDialog", "Neighbor Number:", nullptr));
        label_3->setText(QApplication::translate("BoundaryDialog", "\350\257\267\350\276\223\345\205\245\346\255\243\346\225\264\346\225\260K_2(\347\224\250\344\272\216\350\276\271\347\225\214\350\257\206\345\210\253):", nullptr));
        label_4->setText(QApplication::translate("BoundaryDialog", "Neighbor Number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoundaryDialog: public Ui_BoundaryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOUNDARYDIALOG_H
