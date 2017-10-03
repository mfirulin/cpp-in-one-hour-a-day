#include <iostream>
#include <string>

template <typename T>
void myswap(T& param1, T& param2)
{
    T temp = param1;
    param1 = param2;
    param2 = temp;
}

int main()
{
    int a = 10, b = 20;
    std::cout << a << " " << b << std::endl;
    myswap<int>(a, b);
    std::cout << a << " " << b << std::endl;
    
    double c = 10.5, d = 20.5;
    std::cout << c << " " << d << std::endl;
    myswap<double>(c, d);
    std::cout << c << " " << d << std::endl;
    
    std::string s1 = "hello";
    std::string s2 = "world";
    std::cout << s1 << " " << s2 << std::endl;
    myswap<std::string>(s1, s2);
    std::cout << s1 << " " << s2 << std::endl;
    
    return 0;
}
