#include <iostream>

void func(double[], int);

int main()
{
    double array[] = {1.1, 2.1, 3.1, 4.1, 5.1};
    func(array, sizeof(array) / sizeof(array[0]));
    return 0;
}

void func(double array[], int size)
{
    for(int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
