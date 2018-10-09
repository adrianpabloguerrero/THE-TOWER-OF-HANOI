#include "botonsig.h"

BotonSig::BotonSig(int x,int y)
{
    this->setX(x);
    this->setY(y);
    this->valido=false;
    this->setPixmap(QPixmap(":/Imagenes/Rehacer.png"));

}

void BotonSig::setActive(bool val)
{
    this->valido = val;
    changePixmap();
}

void BotonSig::changePixmap(){
    if( !(this->valido))
        this->setPixmap(QPixmap(":/Imagenes/Rehacer.png"));
    else
        this->setPixmap(QPixmap(":/Imagenes/Rehacer.png"));
}
