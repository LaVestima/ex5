#include "circle.h"

Circle::Circle(QPoint p, int shapeWidth, int shapeHeight) {
    p0 = p;
    radius = shapeWidth;

    painter = new QPainter;
}

void Circle::setWidth(int r) {
    radius = r;
}

void Circle::setHeight(int shapeHeight) {

}

void Circle::draw(QPixmap *pixmap) {
    painter->begin(pixmap);
//    painter->setPen(QPen(color));
    painter->setPen(*(new QColor(225, 0, 0, 255)));
    painter->drawEllipse(p0.x(), p0.y(), radius/2, radius/2);
    painter->end();
}

