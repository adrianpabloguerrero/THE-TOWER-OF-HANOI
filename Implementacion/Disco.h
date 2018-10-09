/*CLASE DE USO GRAFICO DONDE SE ASIGNA
 * UNA IMAGEN A CADA OBJETO DEL TIPO DISCO*/

#ifndef DISCO_H_INCLUDED
#define DISCO_H_INCLUDED

#include <QGraphicsPixmapItem>


class Disco: public QGraphicsPixmapItem
{
    private:
        int Valor;
    public:
        Disco (int x,int y,int i);
        int DevolverValor () const;
        void VisualizarDisco (int a);
};


#endif // DISCO_H_INCLUDED
