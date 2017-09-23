#include <iostream>

int main()
{
    // allocation with throwing an exception
    try {
        int* a = new int[10];
        std::cout << "memory allocated at " << std::hex << a << std::endl;
        delete[] a;
    }
    catch(std::bad_alloc) {
        std::cerr << "memory allocation failed" << std::endl;
    }
    
    // allocation without throwing an exception
    int* a = new(std::nothrow) int[100];
    if(a) {
        std::cout << "memory allocated at " << std::hex << a << std::endl;
        delete[] a;
    }        
    else
        std::cerr << "memory allocation failed" << std::endl;
    
    return 0;
}

