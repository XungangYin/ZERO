/********************************************************************************
** Form generated from reading UI file 'orez.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OREZ_H
#define UI_OREZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OREZ
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *actionAABB;
    QAction *action_11;
    QAction *actionK_Means;
    QAction *action_12;
    QAction *action_13;
    QAction *action_14;
    QAction *action_15;
    QAction *actionsift;
    QAction *actionFPFH;
    QAction *actionICP;
    QAction *actionSAC_IA;
    QAction *actionMLS;
    QAction *action_16;
    QAction *action_17;
    QAction *action_7;
    QAction *action_18;
    QAction *normal_action_19;
    QWidget *centralWidget;
    QVTKWidget *qvtkwidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_6;
    QMenu *menu_8;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_7;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *LayerDialog;
    QWidget *dockWidgetContents;
    QTreeWidget *pointCloudTree;

    void setupUi(QMainWindow *OREZ)
    {
        if (OREZ->objectName().isEmpty())
            OREZ->setObjectName(QStringLiteral("OREZ"));
        OREZ->resize(720, 463);
        action = new QAction(OREZ);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(OREZ);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(OREZ);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(OREZ);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(OREZ);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_8 = new QAction(OREZ);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(OREZ);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(OREZ);
        action_10->setObjectName(QStringLiteral("action_10"));
        actionAABB = new QAction(OREZ);
        actionAABB->setObjectName(QStringLiteral("actionAABB"));
        action_11 = new QAction(OREZ);
        action_11->setObjectName(QStringLiteral("action_11"));
        actionK_Means = new QAction(OREZ);
        actionK_Means->setObjectName(QStringLiteral("actionK_Means"));
        action_12 = new QAction(OREZ);
        action_12->setObjectName(QStringLiteral("action_12"));
        action_13 = new QAction(OREZ);
        action_13->setObjectName(QStringLiteral("action_13"));
        action_14 = new QAction(OREZ);
        action_14->setObjectName(QStringLiteral("action_14"));
        action_15 = new QAction(OREZ);
        action_15->setObjectName(QStringLiteral("action_15"));
        actionsift = new QAction(OREZ);
        actionsift->setObjectName(QStringLiteral("actionsift"));
        actionFPFH = new QAction(OREZ);
        actionFPFH->setObjectName(QStringLiteral("actionFPFH"));
        actionICP = new QAction(OREZ);
        actionICP->setObjectName(QStringLiteral("actionICP"));
        actionSAC_IA = new QAction(OREZ);
        actionSAC_IA->setObjectName(QStringLiteral("actionSAC_IA"));
        actionMLS = new QAction(OREZ);
        actionMLS->setObjectName(QStringLiteral("actionMLS"));
        action_16 = new QAction(OREZ);
        action_16->setObjectName(QStringLiteral("action_16"));
        action_17 = new QAction(OREZ);
        action_17->setObjectName(QStringLiteral("action_17"));
        action_7 = new QAction(OREZ);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_18 = new QAction(OREZ);
        action_18->setObjectName(QStringLiteral("action_18"));
        normal_action_19 = new QAction(OREZ);
        normal_action_19->setObjectName(QStringLiteral("normal_action_19"));
        centralWidget = new QWidget(OREZ);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qvtkwidget = new QVTKWidget(centralWidget);
        qvtkwidget->setObjectName(QStringLiteral("qvtkwidget"));
        qvtkwidget->setGeometry(QRect(340, 0, 381, 231));
        OREZ->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OREZ);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 28));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_6 = new QMenu(menu_3);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        menu_8 = new QMenu(menu_3);
        menu_8->setObjectName(QStringLiteral("menu_8"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_7 = new QMenu(menuBar);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        OREZ->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OREZ);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OREZ->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OREZ);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OREZ->setStatusBar(statusBar);
        LayerDialog = new QDockWidget(OREZ);
        LayerDialog->setObjectName(QStringLiteral("LayerDialog"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        pointCloudTree = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        pointCloudTree->setHeaderItem(__qtreewidgetitem);
        pointCloudTree->setObjectName(QStringLiteral("pointCloudTree"));
        pointCloudTree->setGeometry(QRect(20, 0, 121, 381));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(pointCloudTree->sizePolicy().hasHeightForWidth());
        pointCloudTree->setSizePolicy(sizePolicy);
        pointCloudTree->setSizeIncrement(QSize(0, 1));
        LayerDialog->setWidget(dockWidgetContents);
        OREZ->addDockWidget(static_cast<Qt::DockWidgetArea>(1), LayerDialog);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_7->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_5);
        menu->addAction(action_3);
        menu_2->addAction(action_12);
        menu_2->addAction(action_13);
        menu_2->addAction(action_14);
        menu_2->addAction(action_15);
        menu_3->addAction(menu_8->menuAction());
        menu_3->addAction(menu_6->menuAction());
        menu_3->addAction(action_8);
        menu_3->addAction(action_9);
        menu_3->addAction(action_10);
        menu_3->addAction(actionAABB);
        menu_3->addAction(action_11);
        menu_3->addAction(actionK_Means);
        menu_3->addAction(actionMLS);
        menu_6->addAction(actionsift);
        menu_6->addAction(actionFPFH);
        menu_6->addAction(actionICP);
        menu_6->addAction(actionSAC_IA);
        menu_8->addAction(normal_action_19);
        menu_5->addAction(action_4);
        menu_7->addAction(action_16);
        menu_7->addAction(action_17);
        menu_7->addAction(action_7);
        menu_7->addAction(action_18);

        retranslateUi(OREZ);

        QMetaObject::connectSlotsByName(OREZ);
    } // setupUi

    void retranslateUi(QMainWindow *OREZ)
    {
        OREZ->setWindowTitle(QApplication::translate("OREZ", "OREZ", nullptr));
        action->setText(QApplication::translate("OREZ", "\345\257\274\345\205\245", nullptr));
        action_2->setText(QApplication::translate("OREZ", "\345\257\274\345\207\272", nullptr));
        action_3->setText(QApplication::translate("OREZ", "\351\200\200\345\207\272", nullptr));
        action_4->setText(QApplication::translate("OREZ", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        action_5->setText(QApplication::translate("OREZ", "\351\207\215\347\275\256", nullptr));
        action_8->setText(QApplication::translate("OREZ", "\351\207\215\345\273\272", nullptr));
        action_9->setText(QApplication::translate("OREZ", "\345\255\224\346\264\236\344\277\256\350\241\245", nullptr));
        action_10->setText(QApplication::translate("OREZ", "\350\276\271\347\225\214\350\257\206\345\210\253", nullptr));
        actionAABB->setText(QApplication::translate("OREZ", "AABB\345\214\205\345\233\264\347\233\222", nullptr));
        action_11->setText(QApplication::translate("OREZ", "\345\214\205\345\233\264\347\220\203", nullptr));
        actionK_Means->setText(QApplication::translate("OREZ", "K-Means", nullptr));
        action_12->setText(QApplication::translate("OREZ", "\346\263\225\345\220\221\351\207\217", nullptr));
        action_13->setText(QApplication::translate("OREZ", "\346\233\262\347\216\207", nullptr));
        action_14->setText(QApplication::translate("OREZ", "\345\214\205\345\233\264\347\233\222", nullptr));
        action_15->setText(QApplication::translate("OREZ", "\347\202\271\344\272\221\347\235\200\350\211\262", nullptr));
        actionsift->setText(QApplication::translate("OREZ", "SIFT\351\205\215\345\207\206", nullptr));
        actionFPFH->setText(QApplication::translate("OREZ", "FPFH", nullptr));
        actionICP->setText(QApplication::translate("OREZ", "ICP", nullptr));
        actionSAC_IA->setText(QApplication::translate("OREZ", "SAC-IA", nullptr));
        actionMLS->setText(QApplication::translate("OREZ", "MLS\346\263\225\345\220\221\347\273\237\344\270\200", nullptr));
        action_16->setText(QApplication::translate("OREZ", "\347\202\271\344\272\221\345\220\210\345\271\266", nullptr));
        action_17->setText(QApplication::translate("OREZ", "\347\202\271\344\272\221\347\262\276\347\256\200", nullptr));
        action_7->setText(QApplication::translate("OREZ", "\347\202\271\344\272\221\345\210\206\345\211\262", nullptr));
        action_18->setText(QApplication::translate("OREZ", "\347\202\271\344\272\221\346\273\244\346\263\242", nullptr));
        normal_action_19->setText(QApplication::translate("OREZ", "\346\263\225\345\220\221\344\274\260\350\256\241", nullptr));
        menu->setTitle(QApplication::translate("OREZ", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("OREZ", "\346\270\262\346\237\223\346\230\276\347\244\272", nullptr));
        menu_3->setTitle(QApplication::translate("OREZ", "\350\256\241\347\256\227\345\267\245\345\205\267", nullptr));
        menu_6->setTitle(QApplication::translate("OREZ", "\351\205\215\345\207\206", nullptr));
        menu_8->setTitle(QApplication::translate("OREZ", "\346\263\225\345\220\221", nullptr));
        menu_4->setTitle(QApplication::translate("OREZ", "\347\252\227\345\217\243", nullptr));
        menu_5->setTitle(QApplication::translate("OREZ", "\345\270\256\345\212\251", nullptr));
        menu_7->setTitle(QApplication::translate("OREZ", "\347\274\226\350\276\221", nullptr));
        LayerDialog->setWindowTitle(QApplication::translate("OREZ", "Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OREZ: public Ui_OREZ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OREZ_H
