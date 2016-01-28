#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPixmap>
#include <QPainter>

#include "polygon.h"

class Triangle : public Polygon {
private:
    int width;
    int height;
    QPainter *painter;
public:
    Triangle(QPoint);
    Triangle(QPoint, int, int);
    void setWidth(int);
    void setHeight(int);
    void draw(QPixmap *);
};

#endif // TRIANGLE_H
