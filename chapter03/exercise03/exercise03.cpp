#include <iostream>

constexpr double pi()
{
    return 22.0 / 7.0;
}

double circle(double radius)
{
    return 2 * pi() * radius;
}

double area(double radius)
{
    return pi() * radius * radius;
}

int main()
{
    std::cout << "enter a radius: ";
    
    double r;
    std::cin >> r;
    
    std::cout << "pi=" << pi() << " radius=" << r << std::endl;
    std::cout << "circle=" << circle(r) << " area=" << area(r) << std::endl;
    return 0;
}


