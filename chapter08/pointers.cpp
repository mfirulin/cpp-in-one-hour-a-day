#include <iostream>

int main()
{
    int x = 0, y = 1;
    
    // A pointer to a constant
    const int* pc = &x;
    std::cout << *pc << std::endl;
    pc = &y;
    std::cout << *pc << std::endl;
    
    // A constant pointer
    int* const cp = &x;
    *cp = 2;
    std::cout << *cp << std::endl;
    
    return 0;
}
