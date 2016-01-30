#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle();
    void draw(QPixmap *);
};

#endif // RECTANGLE_H
