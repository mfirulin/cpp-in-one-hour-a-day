#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Shape;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Shape* shape;
    void paintEvent(QPaintEvent*);
};

#endif // WIDGET_H
