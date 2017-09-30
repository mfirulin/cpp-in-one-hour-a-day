#include "shape.h"

Shape::Shape(const QString& name) : m_name(name)
{

}

Shape::~Shape()
{

}

const QString& Shape::name() const
{
    return m_name;
}
