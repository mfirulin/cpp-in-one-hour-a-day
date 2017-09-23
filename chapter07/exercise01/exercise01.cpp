#include <iostream>
#include <cmath>

double volume(double radius); // volume of sphere
double volume(double radius, double height); // volume of cylinder

int main()
{
    std::cout << "enter a radius and a height: ";
    double radius, height;
    std::cin >> radius >> height;
    
    std::cout << "for radius = " << radius << " and height = " << height << std::endl;
    std::cout << "volume of sphere = " << volume(radius) << std::endl;
    std::cout << "volume of cylinder = " << volume(radius, height) << std::endl;
    
    return 0;
}

double volume(double radius)
{
    return 4 * M_PI * std::pow(radius, 3) / 3;
}

double volume(double radius, double height)
{
    return M_PI * std::pow(radius, 2) * height;
}

