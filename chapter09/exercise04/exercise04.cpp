#include <iostream>

class Circle
{
public:
    Circle(double r = 0);
    int getRadius() const;
    void setRadius(double r);
    double circle();
    double area();
    
private:
    static constexpr double pi = 3.14;
    double radius;
};

Circle::Circle(double r) : radius(r)
{
}

int Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double r)
{
    radius = r;
}

double Circle::circle()
{
    return 2 * pi * radius;
}

double Circle::area()
{
    return pi * radius * radius;
}

int main()
{
    Circle circle;
    std::cout << circle.getRadius() << " " << circle.circle() << " " << circle.area() << std::endl;
    circle.setRadius(10);
    std::cout << circle.getRadius() << " " << circle.circle() << " " << circle.area() << std::endl;
    return 0;
}

