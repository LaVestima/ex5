#ifndef SQUARE_H
#define SQUARE_H

#include <QPixmap>
#include <QPainter>

#include "rectangle.h"

class Square : public Rectangle {
private:
    int width;
    int height;
    QPainter *painter;
public:
    Square(QPoint);
    Square(QPoint, int, int);
    void setWidth(int);
    void setHeight(int);
    void draw(QPixmap *);
};

#endif // SQUARE_H
