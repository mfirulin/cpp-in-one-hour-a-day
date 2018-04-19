#include <iostream>

template <typename T>
void display(T p)
{
    std::cout << p << std::endl;
}

template <typename T, typename... Args>
void display(T p, Args... args)
{
    std::cout << p << ' ';
    display(args...);
}

int main()
{
    display(1, 2, 3);
    display("first", "second", "third");
    
    return 0;
}
