#ifndef BOTONSIG_H
#define BOTONSIG_H

#include <QGraphicsPixmapItem>

class BotonSig: public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 14 };
    int type() const { return Type; }
    BotonSig(int x, int y);
    void setActive (bool val);

private:
    void changePixmap();
    bool valido;
};

#endif // BOTONSIG_H
