#ifndef BOTONANT_H
#define BOTONANT_H

#include <QGraphicsPixmapItem>

class BotonAnt: public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 14 };
    int type() const { return Type; }
    BotonAnt(int x, int y);
    void setActive (bool val);

private:
    void changePixmap();
    bool valido;
};


#endif // BOTONANT_H
