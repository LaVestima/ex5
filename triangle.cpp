#include "triangle.h"

Triangle::Triangle(QPoint p, int shapeWidth, int shapeHeight) {
    p0 = p;
    width = shapeWidth;
    height = shapeHeight;

    painter = new QPainter;
}

void Triangle::draw(QPixmap *pixmap) {
    painter->begin(pixmap);
    painter->setPen(*(new QColor(225, 0, 0, 255)));
    painter->drawLine(p0.x()+width/2, p0.y(), p0.x()+width, p0.y()+height);
    painter->drawLine(p0.x()+width, p0.y()+height, p0.x(), p0.y()+height);
    painter->drawLine(p0.x(), p0.y()+height, p0.x()+width/2, p0.y());
    painter->end();
}

void Triangle::setWidth(int shapeWidth) {
    width = shapeWidth;
}

void Triangle::setHeight(int shapeHeight) {
    height = shapeHeight;
}
