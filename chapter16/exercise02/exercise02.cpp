#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "input a sentence: ";
    
    std::string str;
    std::getline(std::cin, str);
    
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int n = 0;
    
    for(auto c: vowels) {
        int pos = 0;
        
        for(;;) {
            pos = str.find(c, pos);
            
            if(pos == std::string::npos)
                break;
            
            ++pos;
            ++n;
        }
    }
    
    std::cout << n << std::endl;
    
    return 0;
}
