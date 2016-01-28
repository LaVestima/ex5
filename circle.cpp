#include "circle.h"

Circle::Circle(QPoint p, int shapeRadius) {
    p0 = p;
    radius = shapeRadius;

    painter = new QPainter;
}

void Circle::setRadius(int r) {
    radius = r;
}

void Circle::draw(QPixmap *pixmap) {
    painter->begin(pixmap);
//    painter->setPen(QPen(color));
    painter->setPen(*(new QColor(225, 0, 0, 255)));
    painter->drawEllipse(p0.x(), p0.y(), radius/2, radius/2);
    painter->end();
}

