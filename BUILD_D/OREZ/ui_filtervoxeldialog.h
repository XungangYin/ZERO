/********************************************************************************
** Form generated from reading UI file 'filtervoxeldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERVOXELDIALOG_H
#define UI_FILTERVOXELDIALOG_H

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

class Ui_FilterVoxelDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *FilterVoxelDialog)
    {
        if (FilterVoxelDialog->objectName().isEmpty())
            FilterVoxelDialog->setObjectName(QStringLiteral("FilterVoxelDialog"));
        FilterVoxelDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(FilterVoxelDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(FilterVoxelDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 161, 17));
        label_2 = new QLabel(FilterVoxelDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 90, 31, 17));
        label_3 = new QLabel(FilterVoxelDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 31, 17));
        label_4 = new QLabel(FilterVoxelDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 150, 31, 17));
        lineEdit = new QLineEdit(FilterVoxelDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 90, 113, 25));
        lineEdit_2 = new QLineEdit(FilterVoxelDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 120, 113, 25));
        lineEdit_3 = new QLineEdit(FilterVoxelDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(70, 150, 113, 25));

        retranslateUi(FilterVoxelDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FilterVoxelDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FilterVoxelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FilterVoxelDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterVoxelDialog)
    {
        FilterVoxelDialog->setWindowTitle(QApplication::translate("FilterVoxelDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("FilterVoxelDialog", "\350\257\267\350\276\223\345\205\245\344\275\223\347\264\240\350\214\203\345\233\264:", nullptr));
        label_2->setText(QApplication::translate("FilterVoxelDialog", "dx :", nullptr));
        label_3->setText(QApplication::translate("FilterVoxelDialog", "dy :", nullptr));
        label_4->setText(QApplication::translate("FilterVoxelDialog", "dz : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterVoxelDialog: public Ui_FilterVoxelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERVOXELDIALOG_H
