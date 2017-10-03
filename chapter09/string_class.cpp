#include <iostream>
#include <cstring>

class String
{
    char* m_str;
    int m_len;
    
public:
    String();
    String(const char* str);
    String(const String& other);
    String(String&& other);
    ~String();
    
    String& operator=(const String& other);
    String& operator=(String&& other);
    operator const char*();
    String operator+(const String& other);
    void operator+=(const String& other);
    bool operator==(const String& other);
    bool operator!=(const String& other);
    const char operator[](int index) const;
    
    int length() const;
    const char* string() const;
};

String::String() : m_str(nullptr), m_len(0)
{
}

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

String::operator const char*()
{
    return m_str;
}

String String::operator+(const String& other)
{
    int len = m_len + other.m_len;
    String str;    
    str.m_str = new(std::nothrow) char[len + 1];
    if(str.m_str) {
        strncpy(str.m_str, m_str, m_len);
        if(other.m_str)
            strncat(str.m_str, other.m_str, other.m_len);
       str.m_len = len;
    }
    return str;
}

void String::operator+=(const String& other)
{
    int len = m_len + other.m_len;    
    char* str = new(std::nothrow) char[len + 1];
    if(str) {
        strncpy(str, m_str, m_len);
        if(other.m_str)
            strncat(str, other.m_str, other.m_len);
        delete[] m_str;
        m_str = str;
        m_len = len;
    }
}

bool String::operator==(const String& other)
{
    return strncmp(m_str, other.m_str, m_len) == 0;
}

bool String::operator!=(const String& other)
{
    return !operator==(other);
}

const char String::operator[](int index) const
{
    if(0 <= index && index < m_len)
        return m_str[index];
        
    return '\0';
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
    
    String str0;
    std::cout << "str0: " << str0.length() << std::endl;
    
    String str1(str);
    std::cout << "str1: " << str1.length() << " " << str1 << std::endl;
    
    String str2(str1);
    std::cout << "str2: " << str2.length() << " " << str2 << std::endl;
    
    String str3;
    str3 = str2;
    std::cout << "str3: " << str3.length() << " " << str3 << std::endl;
    
    String str4;
    str4 = copy_string(str3);
    std::cout << "str4: " << str4.length() << " " << str4 << std::endl;
    
    String hello("Hello, ");
    String world("World!");
    String str5;
    str5 = hello + world;
    std::cout << "str5: " << str5.length() << " " << str5 << std::endl;
    
    hello += world;
    std::cout << "hello: " << hello.length() << " " << hello << std::endl;
    
    std::cout << (hello == hello) << " " << (hello != hello) << std::endl;
    
    for(int i = 0; i < str5.length(); ++i)
        std::cout << str5[i] << " ";
    std::cout << std::endl;
    
    return 0;
}
