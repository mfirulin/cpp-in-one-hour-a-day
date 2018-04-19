#include <iostream>
#include <string>

int main()
{
    std::string s1("I");
    std::string s2("Love");
    std::string s3("STL");
    std::string s4("Strings");
    
    std::string s = s1 + ' ' + s2 + ' ' + s3;
    s += ' ';
    s.append(s4);
    
    std::cout << s << std::endl;
    
    return 0;
}
