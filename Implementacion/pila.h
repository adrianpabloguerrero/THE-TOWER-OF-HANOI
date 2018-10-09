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
// Funci�n Constructora de la Clase
// Se inicializa la lista L en vac�o
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
// Funci�n Destructora de la Clase
// No hace nada ya que invoca al destructor de la lista L
{
}

template <class ELEMENTO>
bool Pila<ELEMENTO>::VaciaPila() const
// Funci�n que devuelve Verdadero si la
// lista L esta vac�a o falso en caso contrario
{
    return (L.VaciaLista());
}

template <class ELEMENTO>
unsigned int Pila<ELEMENTO>::CantidadPila() const
// Funci�n que devuelve un n�mero natural que
// representa la cantidad de elemenos que posee la lista L
{
    return L.CantidadLista();
}

template <class ELEMENTO>
ELEMENTO Pila<ELEMENTO>::TopePila () const
// Funci�n devuelve el elemento ubicado en el tope de la pila
// si la pila est� vac�a termina la ejecuci�n del programa
{
    if (!VaciaPila())
    {
        return L.DevuelveElementoLista();
    }
}

template <class ELEMENTO>
void Pila<ELEMENTO>::AgregarPila(ELEMENTO  dato)
// Funci�n que agrega un elemento al tope de la pila
{
    L.AgregarPrincipioLista(dato);
}

template <class ELEMENTO>
void Pila<ELEMENTO>::EliminarPila()
// Funci�n que elimina el tope de la pila
// si esta no se encuentra vac�a
{
    if (!VaciaPila())
        L.EliminarPosicionLista();
}

#endif
