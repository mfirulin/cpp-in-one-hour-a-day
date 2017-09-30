#include "triangle.h"
#include <QPainter>
#include <QtMath>

Triangle::Triangle(const QPoint &a, const QPoint &b, const QPoint &c) :
    m_a(a), m_b(b), m_c(c)
{

}

Triangle::~Triangle()
{

}

double Triangle::area() const
{
    double ab = qSqrt(qPow(m_a.x() - m_b.x(), 2) + qPow(m_a.y() - m_b.y(), 2));
    double bc = qSqrt(qPow(m_b.x() - m_c.x(), 2) + qPow(m_b.y() - m_c.y(), 2));
    double ac = qSqrt(qPow(m_a.x() - m_c.x(), 2) + qPow(m_a.y() - m_c.y(), 2));

    double p = (ab + bc + ac) / 2;

    return qSqrt(p * (p - ac) * (p - bc) * (p - ac));
}

void Triangle::print(QPainter& painter) const
{
    painter.drawLine(m_a, m_b);
    painter.drawLine(m_a, m_c);
    painter.drawLine(m_b, m_c);
}
