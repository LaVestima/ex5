#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QPoint>

class Shape {
protected:
    QColor color;
    QPoint p0;
public:
    //Shape() : color(Qt::black), p0(100, 100) {}
    //Shape(QColor c) {color = c;}
    Shape();
    ~Shape();
    //void setColor(const QColor &);
    //void setOrigin(QPoint);
    virtual void draw();
};

#endif // SHAPE_H
