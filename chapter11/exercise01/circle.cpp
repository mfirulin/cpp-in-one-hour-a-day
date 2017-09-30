#include "circle.h"
#include <cmath>
#include <QtMath>
#include <QPainter>

Circle::Circle(const QString& name, const QPoint& center, double radius) :
    Shape(name), m_center(center), m_radius(radius)
{

}

Circle::~Circle()
{

}

double Circle::area() const
{
    return M_PI * qPow(m_radius, 2);
}

void Circle::print(QPainter& painter) const
{
    int radius = qRound(m_radius);
    painter.drawEllipse(m_center, radius, radius);
}
