/* CLASE PRINCIPAL PARA LA EJECUCION DEL PROGRAMA
 * INCLUYE LOS ELEMENTOS LOGICOS QUE SON PROCESADOS
 * Y LA VISUALIZACION DE CADA OBJETO */

#ifndef ESCENA_H
#define ESCENA_H

#include "pila.h"
#include "Disco.h"
#include <movimientos.h>
#include <Lista.h>


#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>


class Escena : public QGraphicsScene,QGraphicsPixmapItem{

public:
    Escena();
    void Iniciar(int n);
    void EliminarDiscos();
    void EliminarTorres();
    void HacerMovimiento(Pila<int> * torre1,Pila<int> *torre2);
    void EliminarDisco(int numero);
    void Hanoi(int cantidad,Pila<int> * torre1,Pila<int> * torre2,Pila<int> * torre3);
    void MostrarDisco (Pila <int> * torre1, int cantidad,int altura);
    void GenerarLista (Lista<Movimientos> & Lis,Pila<int> * torre1,Pila<int> *torre2,int cantidad);
    void MostrarProximo (Lista<Movimientos>&Lis);
    void MostrarMovimiento(Lista<Movimientos> &Lis);
    void VaciarLista (Lista<Movimientos> & Lis);
    void MostrarAnterior (Lista<Movimientos>& Lis);



protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *eventoMouse);

private:
    Pila<int> * torre1;
    Pila<int> * torre2;
    Pila<int> * torre3;
    Disco * Disco8;
    Disco * Disco7;
    Disco * Disco6;
    Disco * Disco5;
    Disco * Disco4;
    Disco * Disco3;
    Disco * Disco2;
    Disco * Disco1;
    Lista <Movimientos> Lis;
    int cantidad1;
    int cantidad2;
    int cantidad3;
    QGraphicsTextItem * mensaje;
 };

#endif // GAMESCENE_H

