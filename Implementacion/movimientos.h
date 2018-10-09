/* CLASE DEFINIDA PARA LA INSERCION DE ELEMENTOS
 * EN LA LISTA */

#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <pila.h>

class Movimientos
{
public:
    Movimientos();
    void AsignarOrigen(Pila<int>*OrigenA);
    void AsignarDestino (Pila<int>*DestinoA);
    void AsignarNumero (int NumeroDiscoA);
    Pila <int>* DevolverOrigen ();
    Pila <int>* DevolverDestino();
    int DevolverNumero();

private:
    Pila<int> * Origen;
    Pila<int> * Destino;
    int NumeroDisco;
};

#endif // MOVIMIENTOS_H
