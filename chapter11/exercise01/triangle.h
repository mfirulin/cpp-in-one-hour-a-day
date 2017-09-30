#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QPoint>

class QPainter;

class Triangle : public Shape
{
public:
    Triangle(const QString& name, const QPoint& a, const QPoint& b, const QPoint& c);
    double area() const;
    void print(QPainter& painter) const;
    ~Triangle();

private:
    QPoint m_a, m_b, m_c;
};

#endif // TRIANGLE_H
