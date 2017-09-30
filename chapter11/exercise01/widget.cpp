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

}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    Shape* shape1 = new Triangle(QString("Triangle"), QPoint(10, 10), QPoint(110, 10), QPoint(60, 100));
    Shape* shape2 = new Circle(QString("Circle"), QPoint(150, 150), 50);

    qDebug() << shape1->name() << shape1->area();
    qDebug() << shape2->name() << shape2->area();

    shape1->print(painter);
    shape2->print(painter);

    delete shape1;
    delete shape2;

    painter.end();
}
