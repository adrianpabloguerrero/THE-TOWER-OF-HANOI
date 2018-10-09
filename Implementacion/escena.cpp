#include "escena.h"

#include "Disco.h"
#include "pila.h"

#include <QDebug>
#include <QLabel>
#include<stdio.h>
#include <QFont>
#include <iostream>
#include <math.h>
#include <QGraphicsTextItem>


//---------------------------PARTE LOGICA----------------------------------

Escena::Escena()
//Constructor de la clase, muestra el fondo y se inicia con 8 discos
{

    this->addPixmap(QPixmap(":/Imagenes/fondo.png"));
    this->mensaje= this->addText("");
    Iniciar(8);
}

void Escena::GenerarLista(Lista<Movimientos> & Lis, Pila<int> *torre1, Pila<int> *torre2, int cantidad)
//Genera una nueva lista que permite iterar y mostrar paso a paso los movimientos realizados

{
    Movimientos Nuevo;
    Nuevo.AsignarOrigen(torre1);
    Nuevo.AsignarDestino(torre2);
    Nuevo.AsignarNumero(cantidad);
    Lis.AgregarFinalLista(Nuevo);
}


void Escena::HacerMovimiento(Pila<int> *Origen,Pila<int> *Destino)
//Extrae de la torre Origen para apilar en Destino, ademas de agregar el movimiento a la lista
{
    int Elemento;
    Elemento= Origen->TopePila();
    Origen->EliminarPila();
    Destino->AgregarPila(Elemento);
    GenerarLista(Lis,Origen,Destino,Elemento);
}



void Escena::Hanoi(int cantidad,Pila<int> * torre1,Pila<int> * torre2,Pila<int> * torre3)
//Procedimiento recursivo para la resolucion de Hanoi
{
   if (cantidad>0)
   {
        Hanoi(cantidad-1,torre1,torre3,torre2);
        HacerMovimiento(torre1,torre3);
        Hanoi(cantidad-1,torre2,torre1,torre3);
    }
}


//--------------------------PARTE VISUAL-----------------------------------
//METODOS GRAFICOS PARA LA EJECUCION DEL PROGRAMA

void Escena::Iniciar(int n)
{
    cantidad1=n;
    cantidad2=0;
    cantidad3=0;

    VaciarLista(Lis);
    Lis.AsignarTermino(false);
    Lis.AsignarComienzo(false);
    EliminarDiscos();
    EliminarTorres();
    this-> torre1 = new Pila<int>(50,300);
    this-> addItem(torre1);
    this-> torre2 = new Pila<int>(300,300);
    this-> addItem(torre2);
    this-> torre3 = new Pila<int>(550,300);
    this-> addItem(torre3);
    int x=468;
    this->mensaje->setPlainText("");
    for (int i=n; i>0;i--)
    {
        torre1->AgregarPila(i);
        if (i==8)
        {
            this-> Disco8= new Disco(50,x,i);
            this-> addItem(Disco8);
        }
        if (i==7)
        {
            this-> Disco7= new Disco(50,x,i);
            this-> addItem(Disco7);
        }
        if (i==6)
        {
            this-> Disco6= new Disco(50,x,i);
            this-> addItem(Disco6);
        }
        if (i==5)
        {
            this-> Disco5= new Disco(50,x,i);
            this-> addItem(Disco5);
        }
        if (i==4)
        {
            this-> Disco4= new Disco(50,x,i);
            this-> addItem(Disco4);
        }
        if (i==3)
        {
            this-> Disco3= new Disco(50,x,i);
            this-> addItem(Disco3);
        }
        if (i==2)
        {
            this-> Disco2= new Disco(50,x,i);
            this-> addItem(Disco2);
        }
        if (i==1)
        {
            this-> Disco1= new Disco(50,x,i);
            this-> addItem(Disco1);
        }
        x=x-23;
    }
    Hanoi(n,torre1,torre2,torre3);
    MostrarMovimiento(Lis);

}


void Escena::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QPointF pos(mouseEvent->scenePos().x() ,mouseEvent->scenePos().y());
    if (pos.x() > 450 && pos.y() > 530 && pos.x() < 550 && pos.y() < 590)
    {
        MostrarProximo(Lis);
        MostrarMovimiento(Lis);
        if(!(Lis.RetornarTermino()==false))
            this->mensaje->setPlainText("No hay más movimientos");
    }
    if (pos.x() > 220 && pos.y() > 530 && pos.x() < 320 && pos.y() < 590)
    {
        MostrarAnterior(Lis);
        MostrarMovimiento(Lis);
    }
}


void Escena:: MostrarMovimiento(Lista<Movimientos>& Lis)
{
    Movimientos Activo;
    Activo=Lis.DevuelveElementoLista();
    QFont fuente("Aarial",18);
    this->mensaje->setFont(fuente);
    this->mensaje->setDefaultTextColor(QColor(255,255,255,255));
    this->mensaje->setPos(386,124);
    if (Activo.DevolverOrigen()==torre1)
    {
        if (Activo.DevolverDestino()==torre2)
            this->mensaje->setPlainText("Torre 1 a Torre 2");
        else
           if (Activo.DevolverDestino()==torre3)
                this->mensaje->setPlainText("Torre 1 a Torre 3");
    }
    if (Activo.DevolverOrigen()==torre2)
    {
        if (Activo.DevolverDestino()==torre1)
            this->mensaje->setPlainText("Torre 2 a Torre 1");
        else
           if (Activo.DevolverDestino()==torre3)
                this->mensaje->setPlainText("Torre 2 a Torre 3");
    }
    if (Activo.DevolverOrigen()==torre3)
    {
        if (Activo.DevolverDestino()==torre1)
            this->mensaje->setPlainText("Torre 3 a Torre 1");
        else
           if (Activo.DevolverDestino()==torre2)
                this->mensaje->setPlainText("Torre 3 a Torre 2");
     }
}


void Escena::MostrarAnterior(Lista<Movimientos> &Lis)
{
    if((Lis.RetornarComienzo()==false))
    {
        if (Lis.RetornarTermino()==true)
        {
            Lis.AsignarTermino(false);
            Movimientos Activo;
            Activo=Lis.DevuelveElementoLista();
            EliminarDisco(Activo.DevolverNumero());
            if (Activo.DevolverOrigen()==torre1)
            MostrarDisco(torre1,Activo.DevolverNumero(),cantidad1);
            if (Activo.DevolverOrigen()==torre2)
                 MostrarDisco(torre2,Activo.DevolverNumero(),cantidad2);
            if (Activo.DevolverOrigen()==torre3)
                MostrarDisco(torre3,Activo.DevolverNumero(),cantidad3);
            if (Activo.DevolverOrigen()==torre1)
                cantidad1=cantidad1+1;
            if (Activo.DevolverOrigen()==torre2)
                cantidad2=cantidad2+1;
            if (Activo.DevolverOrigen()==torre3)
                cantidad3=cantidad3+1;
            if (Activo.DevolverDestino()==torre1)
                cantidad1=cantidad1-1;
            if (Activo.DevolverDestino()==torre2)
                cantidad2=cantidad2-1;
            if (Activo.DevolverDestino()==torre3)
                cantidad3=cantidad3-1;
        }
        else
        {
            Lis.AsignarTermino(false);
            Lis.RetrocederLista();
            if (Lis.RetornarComienzo()==false)
            {
                Movimientos Activo;
                Activo=Lis.DevuelveElementoLista();
                EliminarDisco(Activo.DevolverNumero());
                if (Activo.DevolverOrigen()==torre1)
                    MostrarDisco(torre1,Activo.DevolverNumero(),cantidad1);
                if (Activo.DevolverOrigen()==torre2)
                    MostrarDisco(torre2,Activo.DevolverNumero(),cantidad2);
                if (Activo.DevolverOrigen()==torre3)
                    MostrarDisco(torre3,Activo.DevolverNumero(),cantidad3);
                if (Activo.DevolverOrigen()==torre1)
                    cantidad1=cantidad1+1;
                if (Activo.DevolverOrigen()==torre2)
                    cantidad2=cantidad2+1;
                if (Activo.DevolverOrigen()==torre3)
                    cantidad3=cantidad3+1;
                if (Activo.DevolverDestino()==torre1)
                    cantidad1=cantidad1-1;
                if (Activo.DevolverDestino()==torre2)
                    cantidad2=cantidad2-1;
                if (Activo.DevolverDestino()==torre3)
                    cantidad3=cantidad3-1;
            }
        }
    }
}


void Escena::EliminarDiscos()
{
    if (!(this->Disco1==NULL))
        this->removeItem(Disco1);
    if (!(this->Disco2==NULL))
        this->removeItem(Disco2);
    if (!(this->Disco3==NULL))
        this->removeItem(Disco3);
    if (!(this->Disco4==NULL))
        this->removeItem(Disco4);
    if (!(this->Disco5==NULL))
        this->removeItem(Disco5);
    if (!(this->Disco6==NULL))
        this->removeItem(Disco6);
    if (!(this->Disco7==NULL))
        this->removeItem(Disco7);
    if (!(this->Disco8==NULL))
        this->removeItem(Disco8);
}

void Escena::EliminarTorres()
{
   this->removeItem(torre1);
   this->removeItem(torre2);
   this->removeItem(torre3);
   if (!(this->torre1==NULL))
        delete torre1;
   if (!(this->torre2==NULL))
        delete torre2;
   if (!(this->torre3==NULL))
        delete torre3;
}

void Escena::VaciarLista (Lista<Movimientos> & Lis)
{
    while (!(Lis.CantidadLista()==0))
         Lis.EliminarUltimoElemento();
}


void Escena::EliminarDisco(int numero)
{
    if (numero==1)
        this->removeItem(Disco1);
    else
        if (numero==2)
            this->removeItem(Disco2);
        else
            if (numero==3)
                this->removeItem(Disco3);
            else
                if (numero==4)
                    this->removeItem(Disco4);
                else
                    if (numero==5)
                        this->removeItem(Disco5);
                    else
                        if (numero==6)
                            this->removeItem(Disco6);
                        else
                            if (numero==7)
                                this->removeItem(Disco7);
                            else
                                if (numero==8)
                                    this->removeItem(Disco8);

}


void Escena::MostrarProximo(Lista<Movimientos> & Lis)
{
    Lis.AsignarComienzo(false);
    Movimientos Activo;
    Activo=Lis.DevuelveElementoLista();
    if((Lis.RetornarTermino()==false))
    {
        EliminarDisco(Activo.DevolverNumero());
        if (Activo.DevolverOrigen()==torre1)
            cantidad1=cantidad1-1;
        if (Activo.DevolverOrigen()==torre2)
            cantidad2=cantidad2-1;
        if (Activo.DevolverOrigen()==torre3)
            cantidad3=cantidad3-1;
        if (Activo.DevolverDestino()==torre1)
            MostrarDisco(Activo.DevolverDestino(),Activo.DevolverNumero(),cantidad1);
        if (Activo.DevolverDestino()==torre2)
            MostrarDisco(Activo.DevolverDestino(),Activo.DevolverNumero(),cantidad2);
        if (Activo.DevolverDestino()==torre3)
            MostrarDisco(Activo.DevolverDestino(),Activo.DevolverNumero(),cantidad3);
        if (Activo.DevolverDestino()==torre1)
            cantidad1=cantidad1+1;
        if (Activo.DevolverDestino()==torre2)
            cantidad2=cantidad2+1;
        if (Activo.DevolverDestino()==torre3)
            cantidad3=cantidad3+1;
        Lis.AvanzarLista();
   }
}


void Escena::MostrarDisco (Pila<int> * torre, int cantidad,int altura)
{
    if (torre==torre3)
        {
            int x=550;
            int h=(468-(altura*23));
            if  (cantidad==1)
            {
                Disco1->setX(x);
                Disco1->setY(h);
                this->addItem(Disco1);
            }
            if (cantidad==2)
            {
                Disco2->setX(x);
                Disco2->setY(h);
                this->addItem(Disco2);
            }
            if (cantidad==3)
            {
                Disco3->setX(x);
                Disco3->setY(h);
                this->addItem(Disco3);
            }
            if (cantidad==4)
            {
                Disco4->setX(x);
                Disco4->setY(h);
                this->addItem(Disco4);
            }
            if (cantidad==5)
            {
                Disco5->setX(x);
                Disco5->setY(h);
                this->addItem(Disco5);
            }
            if (cantidad==6)
            {
                Disco6->setX(x);
                Disco6->setY(h);
                this->addItem(Disco6);
            }
            if (cantidad==7)
            {
                Disco7->setX(x);
                Disco7->setY(h);
                this->addItem(Disco7);
            }
            if (cantidad==8)
            {
                Disco8->setX(x);
                Disco8->setY(h);
                this->addItem(Disco8);
            }
        }
        else
            if (torre==torre2)
            {
                int x=300;
                int h=(468-(altura*23));
                if  (cantidad==1)
                {
                    Disco1->setX(x);
                    Disco1->setY(h);
                    this->addItem(Disco1);
                }
                if (cantidad==2)
                {
                    Disco2->setX(x);
                    Disco2->setY(h);
                    this->addItem(Disco2);
                }
                if (cantidad==3)
                {
                    Disco3->setX(x);
                    Disco3->setY(h);
                    this->addItem(Disco3);
                }
                if (cantidad==4)
                {
                    Disco4->setX(x);
                    Disco4->setY(h);
                    this->addItem(Disco4);
                }
                if (cantidad==5)
                {
                    Disco5->setX(x);
                    Disco5->setY(h);
                    this->addItem(Disco5);
                }
                if (cantidad==6)
                {
                    Disco6->setX(x);
                    Disco6->setY(h);
                    this->addItem(Disco6);
                }
                if (cantidad==7)
                {
                    Disco7->setX(x);
                    Disco7->setY(h);
                    this->addItem(Disco7);
                }
                if (cantidad==8)
                {
                    Disco8->setX(x);
                    Disco8->setY(h);
                    this->addItem(Disco8);
                }
            }
            if (torre==torre1)
            {
                int x=50;
                int h=(468-(altura*23));
                if  (cantidad==1)
                {
                    Disco1->setX(x);
                    Disco1->setY(h);
                    this->addItem(Disco1);
                }
                if (cantidad==2)
                {
                    Disco2->setX(x);
                    Disco2->setY(h);
                    this->addItem(Disco2);
                }
                if (cantidad==3)
                {
                    Disco3->setX(x);
                    Disco3->setY(h);
                    this->addItem(Disco3);
                }
                if (cantidad==4)
                {
                    Disco4->setX(x);
                    Disco4->setY(h);
                    this->addItem(Disco4);
                }
                if (cantidad==5)
                {
                    Disco5->setX(x);
                    Disco5->setY(h);
                    this->addItem(Disco5);
                }
                if (cantidad==6)
                {
                    Disco6->setX(x);
                    Disco6->setY(h);
                    this->addItem(Disco6);
                }
                if (cantidad==7)
                {
                    Disco7->setX(x);
                    Disco7->setY(h);
                    this->addItem(Disco7);
                }
                if (cantidad==8)
                {
                    Disco8->setX(x);
                    Disco8->setY(h);
                    this->addItem(Disco8);
                }
            }
}


