#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QPoint>
#include <QPixmap>
#include <QPainter>

class Shape {
protected:
    QColor color;
    QPoint p0;
    QPainter *painter;
public:
    Shape() {}// : color(Qt::black), p0(100, 100) {painter = new QPainter;}
    //Shape(QColor c) {color = c; painter = new QPainter;}
    //Shape(QPoint, int, int) {painter = new QPainter;}
    //Shape();
    virtual ~Shape();
    void setColor(const QColor &);
    void setOrigin(QPoint);
    virtual void draw(QPixmap *) {}
    virtual void setWidth(int);
    virtual void setHeight(int);
};

#endif // SHAPE_H
