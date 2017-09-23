#include <iostream>

int main()
{
    bool a, b;
    
    std::cout << "enter two boolean values: ";
    std::cin >> a >> b;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "~a = " << ~a << ", ~b = " << ~b << std::endl;
    std::cout << "a & b = " << (a & b) << std::endl;
    std::cout << "a | b = " << (a | b) << std::endl;
    std::cout << "a ^ b = " << (a ^ b) << std::endl;
   
    return 0;
}
