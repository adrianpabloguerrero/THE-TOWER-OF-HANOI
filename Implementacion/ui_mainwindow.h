/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo_Juego_2;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QAction *action6;
    QAction *action7;
    QAction *action8;
    QAction *actionTorres_de_Hanoi;
    QAction *actionSalir_2;
    QAction *actionProyecto;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuJuego;
    QMenu *menuConfiguracion;
    QMenu *menuCantidad_Discos;
    QMenu *menuAcerca_de;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(810, 640);
        MainWindow->setMinimumSize(QSize(810, 640));
        MainWindow->setMaximumSize(QSize(810, 640));
        actionNuevo_Juego_2 = new QAction(MainWindow);
        actionNuevo_Juego_2->setObjectName(QStringLiteral("actionNuevo_Juego_2"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QStringLiteral("action1"));
        action2 = new QAction(MainWindow);
        action2->setObjectName(QStringLiteral("action2"));
        action3 = new QAction(MainWindow);
        action3->setObjectName(QStringLiteral("action3"));
        action4 = new QAction(MainWindow);
        action4->setObjectName(QStringLiteral("action4"));
        action5 = new QAction(MainWindow);
        action5->setObjectName(QStringLiteral("action5"));
        action6 = new QAction(MainWindow);
        action6->setObjectName(QStringLiteral("action6"));
        action7 = new QAction(MainWindow);
        action7->setObjectName(QStringLiteral("action7"));
        action8 = new QAction(MainWindow);
        action8->setObjectName(QStringLiteral("action8"));
        actionTorres_de_Hanoi = new QAction(MainWindow);
        actionTorres_de_Hanoi->setObjectName(QStringLiteral("actionTorres_de_Hanoi"));
        actionSalir_2 = new QAction(MainWindow);
        actionSalir_2->setObjectName(QStringLiteral("actionSalir_2"));
        actionProyecto = new QAction(MainWindow);
        actionProyecto->setObjectName(QStringLiteral("actionProyecto"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 810, 21));
        menuJuego = new QMenu(menuBar);
        menuJuego->setObjectName(QStringLiteral("menuJuego"));
        menuConfiguracion = new QMenu(menuBar);
        menuConfiguracion->setObjectName(QStringLiteral("menuConfiguracion"));
        menuCantidad_Discos = new QMenu(menuConfiguracion);
        menuCantidad_Discos->setObjectName(QStringLiteral("menuCantidad_Discos"));
        menuAcerca_de = new QMenu(menuBar);
        menuAcerca_de->setObjectName(QStringLiteral("menuAcerca_de"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(false);
        statusBar->setMaximumSize(QSize(0, 0));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuJuego->menuAction());
        menuBar->addAction(menuConfiguracion->menuAction());
        menuBar->addAction(menuAcerca_de->menuAction());
        menuJuego->addSeparator();
        menuJuego->addAction(actionNuevo_Juego_2);
        menuJuego->addSeparator();
        menuJuego->addAction(actionSalir_2);
        menuConfiguracion->addAction(menuCantidad_Discos->menuAction());
        menuCantidad_Discos->addAction(action1);
        menuCantidad_Discos->addAction(action2);
        menuCantidad_Discos->addAction(action3);
        menuCantidad_Discos->addAction(action4);
        menuCantidad_Discos->addAction(action5);
        menuCantidad_Discos->addAction(action6);
        menuCantidad_Discos->addAction(action7);
        menuCantidad_Discos->addAction(action8);
        menuAcerca_de->addAction(actionTorres_de_Hanoi);
        menuAcerca_de->addAction(actionProyecto);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNuevo_Juego_2->setText(QApplication::translate("MainWindow", "Nuevo Juego", 0));
        action1->setText(QApplication::translate("MainWindow", "1 ", 0));
        action2->setText(QApplication::translate("MainWindow", "2", 0));
        action3->setText(QApplication::translate("MainWindow", "3", 0));
        action4->setText(QApplication::translate("MainWindow", "4", 0));
        action5->setText(QApplication::translate("MainWindow", "5", 0));
        action6->setText(QApplication::translate("MainWindow", "6", 0));
        action7->setText(QApplication::translate("MainWindow", "7", 0));
        action8->setText(QApplication::translate("MainWindow", "8", 0));
        actionTorres_de_Hanoi->setText(QApplication::translate("MainWindow", "Torres de Hanoi", 0));
        actionSalir_2->setText(QApplication::translate("MainWindow", "Salir", 0));
        actionProyecto->setText(QApplication::translate("MainWindow", "Proyecto", 0));
        menuJuego->setTitle(QApplication::translate("MainWindow", "Juego", 0));
        menuConfiguracion->setTitle(QApplication::translate("MainWindow", "Configuracion", 0));
        menuCantidad_Discos->setTitle(QApplication::translate("MainWindow", "Cantidad Discos", 0));
        menuAcerca_de->setTitle(QApplication::translate("MainWindow", "Acerca de", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
