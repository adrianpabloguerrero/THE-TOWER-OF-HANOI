/* ESTRUCTURA CONTENDORA DE INFORMACION
 * COMPUESTO POR NODOS DOBLEMENTE VINCULADOS
 * Y UN DATO DE TIPO ELEMENTO */

#ifndef LISTA_H
#define LISTA_H
#include <iostream>


template <class ELEMENTO>

class Lista
{

    public:
        Lista();
        ~Lista();
        void AgregarPrincipioLista (ELEMENTO dato);
        void AgregarFinalLista (ELEMENTO dato);
        void AgregarPosicionLista (ELEMENTO dato,unsigned int posicion);
        unsigned int CantidadLista () const;
        bool ExisteElementoLista (ELEMENTO dato) const;
        bool VaciaLista () const;
        void EliminarElementoLista (ELEMENTO dato);
        void AvanzarLista ();
        void RetrocederLista ();
        void EliminarPosicionLista();
        void EliminarUltimoElemento();
        ELEMENTO DevuelveElementoLista() const;
        bool RetornarTermino();
        void AsignarTermino (bool termino);
        void AsignarComienzo (bool comienzo);
        bool RetornarComienzo ();

    protected:
    private:
        struct nodo
        {
            ELEMENTO dato;
            nodo* siguiente;
            nodo* anterior;
        };
        nodo* primero;
        nodo* ultimo;
        nodo* indice;
        unsigned int cantidad;
        bool Termino;
        bool Comienzo;
};


template <class ELEMENTO>
Lista <ELEMENTO>::Lista()
//Función constructora de la lista vacia.
{
    primero=NULL;
    ultimo=NULL;
    indice=NULL;
    cantidad=0;
    Termino=false;
    Comienzo=false;
}

template <class ELEMENTO>
void Lista <ELEMENTO>::AgregarPrincipioLista(ELEMENTO dato)
//Función que agrega un elemento al principio de la lista
{
    nodo*nuevonodo=new nodo;
    nuevonodo->dato=dato;
    nuevonodo->siguiente=primero;
    nuevonodo->anterior=NULL;
    if (primero!=NULL)
    {
        nuevonodo->siguiente=primero;
        primero=nuevonodo;
        nuevonodo->siguiente->anterior=nuevonodo;
    }
    else
    {
         primero=nuevonodo;
         ultimo=nuevonodo;
    }
    cantidad++;
    indice=primero;
}

template <class ELEMENTO>
void Lista <ELEMENTO>::AsignarComienzo (bool dato)
{
    Comienzo=dato;
}

template <class ELEMENTO>
void Lista <ELEMENTO>::AsignarTermino (bool dato)
{
    Termino=dato;
}


template <class ELEMENTO>
void Lista <ELEMENTO>::AgregarFinalLista(ELEMENTO dato)
//Función que agrega un elemento al final de la lista.
{
    nodo*nuevonodo=new nodo;
    nuevonodo->dato=dato;
    nuevonodo->siguiente=NULL;
    nuevonodo->anterior=ultimo;
    if (cantidad!=0)
    {
        nuevonodo->anterior=ultimo;
        ultimo=nuevonodo;
        nuevonodo->anterior->siguiente=nuevonodo;
    }
    else
    {
        primero=nuevonodo;
        ultimo=nuevonodo;
    }
    cantidad++;
    indice=primero;
}

template <class ELEMENTO>
void Lista <ELEMENTO>::AgregarPosicionLista(ELEMENTO dato, unsigned int posicion)
//Función que agrega un elemento en una posición arbitraria de la lista.
{

    if ((posicion>=1) && (posicion<= cantidad+1))
    {
        if (posicion==1)
            AgregarPrincipioLista(dato);
        else
            if (posicion==cantidad+1)
                AgregarFinalLista(dato);
            else
            {
                 nodo*nuevonodo=new nodo;
                 nuevonodo->dato=dato;
                 unsigned int cont=1;
                 nodo*cursor=primero;
                 while (cont<posicion)
                {
                    cursor=cursor->siguiente;
                    cont++;
                }
                cursor->anterior->siguiente=nuevonodo;
                nuevonodo->anterior=cursor->anterior;
                nuevonodo->siguiente=cursor;
                cursor->anterior=nuevonodo;
                cantidad++;
                indice=nuevonodo;
            }
    }

}

template <class ELEMENTO>
unsigned int Lista <ELEMENTO>::CantidadLista() const
//Función que retorna la cantidad de elementos de la Lista.
{
    return (cantidad);
}

template <class ELEMENTO>
bool Lista<ELEMENTO>::VaciaLista() const
//Funcion que devuelve verdadero si la Lista está Vacia
// o falso si la lista contiene elementos.
{
    if (cantidad==0)
        return true;
    else
        return false;
}

template <class ELEMENTO>
bool Lista<ELEMENTO>::RetornarComienzo()
{
    return Comienzo;
}

template <class ELEMENTO>
bool Lista<ELEMENTO>::RetornarTermino()
{
    return Termino;
}

template <class ELEMENTO>
void Lista<ELEMENTO>::AvanzarLista()
//Función que avanza una posición con el puntero .
{
    if (indice!=ultimo)
        indice=indice->siguiente;
    else
        Termino=true;
}

template <class ELEMENTO>
void Lista<ELEMENTO>::RetrocederLista()
//Función que retrocede una posición con el puntero indice.
{
    if (indice!=primero)
        indice=indice->anterior;
    else
        Comienzo=true;
}

template <class ELEMENTO>
bool Lista<ELEMENTO>::ExisteElementoLista(ELEMENTO dato) const
//Función que dado un elemento y una lista, devuelve
//verdadero si existe o falso si no existe en la lista.
{
 {
    nodo * Cursor = primero;
    while (Cursor != NULL)
    {
        if (Cursor->dato == dato)
            return true;
        Cursor=Cursor->siguiente;
    }
    return false;
}

}

template <class ELEMENTO>
void Lista<ELEMENTO>::EliminarElementoLista(ELEMENTO dato)
//Función que elimina un elemento de la lista
// en todas sus ocurrencias.
{
    while(ExisteElementoLista(dato))
    {
        nodo * Cursor = primero;
        while (Cursor->dato != dato)
            Cursor = Cursor->siguiente;
        if (indice == Cursor)
        {
         if (cantidad>1) indice=primero;
         else indice = NULL;
        }
        if (Cursor != primero)
            Cursor->anterior->siguiente = Cursor->siguiente;
        else
            primero = Cursor->siguiente;
        if (Cursor != ultimo)
            Cursor->siguiente->anterior = Cursor->anterior;
        else
            ultimo = Cursor->anterior;
        delete Cursor;
        cantidad--;
    }
}


template <class ELEMENTO>
Lista<ELEMENTO>::~Lista()
// Función destructora de la lista. Libera el espacio
// utilizado por la lista, vuelve el Indice NULL y la
// Cantidad le asigna 0
{
    ultimo = primero;
    while (primero != NULL)
    {
        primero = primero->siguiente;
        delete ultimo;
        ultimo = primero;
    }
    indice = NULL;
    cantidad = 0;
}




template <class ELEMENTO>
void Lista<ELEMENTO>::EliminarPosicionLista()
// Función que borra el nodo que es apuntado por el Indice
{
    if (!VaciaLista())
    {
        nodo * AEliminar = indice;
        if (indice==primero)
        {
            indice = indice->siguiente;
            if (CantidadLista() > 1)
                indice->anterior = NULL;
            primero = indice;
        }
        else if (indice==ultimo)
        {
            indice = indice->anterior;
            indice->siguiente = NULL;
            ultimo = indice;
        }
        else
        {
            indice = indice->siguiente;
            indice->anterior = AEliminar->anterior;
            AEliminar->anterior->siguiente = indice;
        }
        delete AEliminar;
        cantidad--;
    }
}

template <class ELEMENTO>
ELEMENTO Lista<ELEMENTO>::DevuelveElementoLista() const
// Función que devuelve el elemento que es apuntado por
// el Indice, si el Indice es NULL termina la ejecución
{
    if (!(indice == NULL))
        return (indice->dato);
}

template <class ELEMENTO>
void Lista<ELEMENTO>::EliminarUltimoElemento()
//Funcion que elimina el elemento apuntado por ULTIMO.

{
    if (CantidadLista()!=0)
    {
       nodo*cursor=ultimo;
       if (cursor==indice)
            EliminarPosicionLista();
       else
       {
        if (ultimo==primero)
       {
           primero=NULL;
           ultimo=NULL;
       } else
            {
                ultimo=cursor->anterior;
                ultimo->siguiente=NULL;

            }
            delete cursor;
            cantidad--;
       }
    }
}







#endif // LISTA_H
