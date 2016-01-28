#include "shape.h"

void Shape::setColor(const QColor &c) {
    color = c;
}

void Shape::setOrigin(QPoint p) {
    p0 = p;
}

Shape::~Shape() {

}

void Shape::draw() {

}
