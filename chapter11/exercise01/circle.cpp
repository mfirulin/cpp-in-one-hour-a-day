#include "circle.h"
#include <cmath>
#include <QtMath>
#include <QPainter>

Circle::Circle(const QPoint &center, double radius) :
    m_center(center), m_radius(radius)
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
    painter.drawEllipse(m_center, qRound(m_radius), qRound(m_radius));
}
