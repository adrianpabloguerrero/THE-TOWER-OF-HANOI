#include "proximo.h"

Proximo::Proximo(int x, int y){
    this->setX(x);
    this->setY(y);
    this->valido = false;
    changePixmap();
}

void Proximo::setActive(bool val){
    this->valido = val;
    changePixmap();
}

void Proximo::changePixmap(){
   // if (this->valido)
        this->setPixmap(QPixmap(":/imagenes/proximo.png"));
}

