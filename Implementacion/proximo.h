#ifndef PROXIMO_H
#define PROXIMO_H
#include<QGraphicsPixmapItem>

class Proximo: public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 15 };
    int type() const { return Type; }
    Proximo(int x,int y);
    void setActive(bool val);

private:
    void changePixmap();
    bool valido;

};

#endif // PROXIMO_H


