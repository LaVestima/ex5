#include "square.h"

Square::Square(QPoint p, int shapeWidth, int shapeHeight) {
    p0 = p;
    width = shapeWidth;
    height = shapeHeight;

    painter = new QPainter;
}

void Square::draw(QPixmap *pixmap) {
    painter->begin(pixmap);
    painter->setPen(*(new QColor(225, 0, 0, 255)));
    painter->drawRect(p0.x(), p0.y(), width, height);
    //painter->drawEllipse(p0.x(), p0.y(), radius/2, radius/2);
    painter->end();
}

void Square::setWidth(int shapeWidth) {
    width = shapeWidth;
}

void Square::setHeight(int shapeHeight) {
    height = shapeHeight;
}
