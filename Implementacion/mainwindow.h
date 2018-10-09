#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QWidget>
#include <iostream>

#include "escena.h"
#include <dialog2.h>
#include <dialog.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_actionNuevo_Juego_2_triggered();

    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_action4_triggered();

    void on_action5_triggered();

    void on_action6_triggered();

    void on_action7_triggered();

    void on_action8_triggered();

    void on_actionTorres_de_Hanoi_triggered();

    void on_actionSalir_2_triggered();

    void on_actionProyecto_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    Escena *scene;
};

#endif // MAINWINDOW_H
