#include <iostream>
#include <cstring>

class String
{
    char* m_str;
    int m_len;
    
public:
    String(const char* str);
    String(const String& other);
    String(String&& other);
    ~String();
    
    String& operator=(const String& other);
    String& operator=(String&& other);
    
    int length() const;
    const char* string() const;
};

String::String(const char* str) : m_str(nullptr), m_len(0)
{
    std::cout << "constructor" << std::endl;
    
    int len = strlen(str);
    m_str = new(std::nothrow) char[len + 1];
    if(m_str) {
        strncpy(m_str, str, len);
        m_str[len] = '\0';
        m_len = len;
    }
}

String::String(const String& other) : m_str(nullptr), m_len(0)
{
    std::cout << "copy constructor" << std::endl;
        
    if(other.m_str) {
        m_str = new(std::nothrow) char[other.m_len + 1];
        if(m_str) {
            strncpy(m_str, other.m_str, other.m_len);
            m_len = other.m_len;
            m_str[m_len] = '\0';
        }
    }
}

String::String(String&& other) : m_str(nullptr), m_len(0)
{
    std::cout << "move constructor" << std::endl;
    
    if(other.m_str) {
        m_str = other.m_str;
        m_len = other.m_len;
        other.m_str = nullptr;
        other.m_len = 0;
    }
}

String::~String()
{
    std::cout << "destructor" << std::endl;
    
    delete[] m_str;
}

String& String::operator=(const String& other)
{
    std::cout << "copy operator =" << std::endl;
    
    if(this != &other && other.m_str) {
        if(m_str) {
            delete[] m_str;
            m_len = 0;
        }
            
        m_str = new(std::nothrow) char[other.m_len + 1];
        if(m_str) {
            strncpy(m_str, other.m_str, other.m_len);
            m_len = other.m_len;
            m_str[m_len] = '\0';
        }
    }
    return *this;
}

String& String::operator=(String&& other)
{
    std::cout << "move operator =" << std::endl;
    
    if(this != &other && other.m_str) {
        if(m_str)
            delete[] m_str;
            
        m_str = other.m_str;
        m_len = other.m_len;
        other.m_str = nullptr;
        other.m_len = 0;
    }
    return *this;    
}

const char* String::string() const
{
    return m_str;
}

int String::length() const
{
    return m_len;
}

String copy_string(String& str)
{
    String cstr(str.string());
    return cstr;
}

int main()
{   
    char str[] = "Hello, World!";
    
    String str1(str);
    std::cout << "str1: " << str1.length() << " " << str1.string() << std::endl;
    
    String str2(str);
    std::cout << "str2: " << str2.length() << " " << str2.string() << std::endl;
    
    String str3 = str2;
    std::cout << "str3: " << str3.length() << " " << str3.string() << std::endl;
    
    String str4 = copy_string(str3);
    std::cout << "str4: " << str4.length() << " " << str4.string() << std::endl;
    
    return 0;
}
