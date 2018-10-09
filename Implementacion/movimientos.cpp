#include "movimientos.h"

Movimientos::Movimientos()
{

}

void Movimientos::AsignarDestino(Pila<int> *DestinoA)
{
    Destino=DestinoA;
}

void Movimientos::AsignarOrigen(Pila<int> *OrigenA)
{
    Origen=OrigenA;
}

void Movimientos::AsignarNumero(int NumeroDiscoA)
{
    NumeroDisco=NumeroDiscoA;
}

Pila<int> * Movimientos::DevolverOrigen()
{
    return Origen;
}

Pila<int> * Movimientos::DevolverDestino()
{
    return Destino;
}

int Movimientos::DevolverNumero()
{
    return NumeroDisco;
}
