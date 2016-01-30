#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"

class Polygon : public Shape {
public:
    Polygon();
    void draw(QPixmap *);
};

#endif // POLYGON_H
