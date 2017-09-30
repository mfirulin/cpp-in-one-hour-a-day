#include "widget.h"
#include "shape.h"
#include "triangle.h"
#include "circle.h"

#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

}

Widget::~Widget()
{
    delete shape;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    shape = new Triangle(QPoint(10, 10), QPoint(110, 10), QPoint(50, 100));
    qDebug() << shape->area();
    shape->print(painter);
    delete shape;

    shape = new Circle(QPoint(200, 200), 50);
    qDebug() << shape->area();
    shape->print(painter);
    delete shape;
    shape = nullptr;

    painter.end();
}
