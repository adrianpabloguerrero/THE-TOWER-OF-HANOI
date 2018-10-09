#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout *layout = new QHBoxLayout();
    view = new QGraphicsView();
    layout->addWidget(view);
    view->setObjectName("graphicsView");

    scene = new Escena();
    view->setScene(scene);
    view->setSceneRect(scene->sceneRect());

    view->setFixedSize(810, 610);

    QWidget *wlayout = new QWidget();
    wlayout->setLayout(layout);
    setCentralWidget(wlayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionNuevo_Juego_2_triggered()
{
    scene->Iniciar(8);
}

void MainWindow::on_action1_triggered()
{
    scene->Iniciar(1);
}



void MainWindow::on_action2_triggered()
{
    scene->Iniciar(2);
}

void MainWindow::on_action3_triggered()
{
    scene->Iniciar(3);
}

void MainWindow::on_action4_triggered()
{
    scene->Iniciar(4);
}

void MainWindow::on_action5_triggered()
{
    scene->Iniciar(5);
}

void MainWindow::on_action6_triggered()
{
    scene->Iniciar(6);
}

void MainWindow::on_action7_triggered()
{
    scene->Iniciar(7);
}

void MainWindow::on_action8_triggered()
{
    scene->Iniciar(8);
}

void MainWindow::on_actionTorres_de_Hanoi_triggered()
{
    Dialog *ventana=new Dialog(this) ;
    ventana->setModal(true);
    ventana->show();

}

void MainWindow::on_actionSalir_2_triggered()
{
    close();
}

void MainWindow::on_actionProyecto_triggered()
{
    dialog2 *ventana1=new dialog2(this) ;
    ventana1->setModal(true);
    ventana1->show();
}
