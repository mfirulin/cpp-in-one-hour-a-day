#ifndef SHAPE_H
#define SHAPE_H

class QPainter;

class Shape
{
public:
    Shape();
    virtual double area() const = 0;
    virtual void print(QPainter& painter) const = 0;
    virtual ~Shape();
};

#endif // SHAPE_H
