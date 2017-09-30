#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QPoint>

class Circle : public Shape
{
public:
    Circle(const QPoint& center, double radius);
    double area() const;
    void print(QPainter& painter) const;
    ~Circle();
private:
    QPoint m_center;
    double m_radius;
};

#endif // CIRCLE_H
