#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::cout << "input a word: ";
    
    std::string str;
    std::cin >> str;
//    std::getline(std::cin, str);
    
    std::string str_copy(str);
    
    std::reverse(str_copy.begin(), str_copy.end());
    
    if(str == str_copy)
        std::cout << "it is a palindrome: ";
    else
        std::cout << "it is not a palindrome: ";
    
    std::cout << str << " " << str_copy << std::endl;
    return 0;
}
