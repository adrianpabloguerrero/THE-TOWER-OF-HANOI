#include "Disco.h"

void Disco::VisualizarDisco(int a)
{
     this->setPixmap(QPixmap(":/Imagenes/disco"+QString::number(a)+".png"));
}


Disco::Disco(int x,int y,int Valor)
{
   this->setX(x);
   this->setY(y);
   VisualizarDisco(Valor);
}

int Disco::DevolverValor()const
{
    return Valor;
}


