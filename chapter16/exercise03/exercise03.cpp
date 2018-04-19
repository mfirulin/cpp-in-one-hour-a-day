#include <iostream>
#include <string>

int main()
{
    std::cout << "input a sentence: ";
    
    std::string str;
    std::getline(std::cin, str);
    
    for(int i = 0; i < str.length(); i += 2) {
        str[i] = ::toupper(str[i]);
        str[i + 1] = ::tolower(str[i + 1]);
    }
    
    std::cout << str << std::endl;    
    
    return 0;
}
