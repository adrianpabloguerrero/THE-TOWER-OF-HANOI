/* ESTRUCTURA CONTENEDORA DE INFORMACION
 * BASADA EN LA CLASE LISTA*/

#ifndef PILA_H
#define PILA_H

#include "lista.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <Disco.h>


template <class ELEMENTO>
class Pila: public QGraphicsPixmapItem,QGraphicsScene
{
private:
    Lista<ELEMENTO> L;

public:
    Pila(int x,int y);
    ~Pila();
    void AgregarPila(ELEMENTO dato);
    bool VaciaPila() const;
    ELEMENTO TopePila() const;
    unsigned int CantidadPila () const;
    void EliminarPila ();
    void VisualizarTorre();

};

template <class ELEMENTO>
Pila<ELEMENTO>::Pila(int x,int y)
// Función Constructora de la Clase
// Se inicializa la lista L en vacío
{
    this->setX(x);
    this->setY(y);
    VisualizarTorre();
}

template <class ELEMENTO>
void Pila<ELEMENTO>::VisualizarTorre()
{
    this->setPixmap(QPixmap(":/Imagenes/torre.png"));
}





template <class ELEMENTO>
Pila<ELEMENTO>::~Pila()
// Función Destructora de la Clase
// No hace nada ya que invoca al destructor de la lista L
{
}

template <class ELEMENTO>
bool Pila<ELEMENTO>::VaciaPila() const
// Función que devuelve Verdadero si la
// lista L esta vacía o falso en caso contrario
{
    return (L.VaciaLista());
}

template <class ELEMENTO>
unsigned int Pila<ELEMENTO>::CantidadPila() const
// Función que devuelve un número natural que
// representa la cantidad de elemenos que posee la lista L
{
    return L.CantidadLista();
}

template <class ELEMENTO>
ELEMENTO Pila<ELEMENTO>::TopePila () const
// Función devuelve el elemento ubicado en el tope de la pila
// si la pila está vacía termina la ejecución del programa
{
    if (!VaciaPila())
    {
        return L.DevuelveElementoLista();
    }
}

template <class ELEMENTO>
void Pila<ELEMENTO>::AgregarPila(ELEMENTO  dato)
// Función que agrega un elemento al tope de la pila
{
    L.AgregarPrincipioLista(dato);
}

template <class ELEMENTO>
void Pila<ELEMENTO>::EliminarPila()
// Función que elimina el tope de la pila
// si esta no se encuentra vacía
{
    if (!VaciaPila())
        L.EliminarPosicionLista();
}

#endif
