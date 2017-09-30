#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

class QPainter;

class Shape
{
public:
    Shape(const QString& name);
    virtual double area() const = 0;
    virtual void print(QPainter& painter) const = 0;
    virtual ~Shape();
    const QString& name() const;

private:
    QString m_name;
};

#endif // SHAPE_H
