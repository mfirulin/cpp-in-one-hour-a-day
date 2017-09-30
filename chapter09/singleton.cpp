#include <iostream>
#include <string>

class Singleton
{
private:
    Singleton() {};
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    
    std::string str;
    
public:
    static Singleton& instance();
    std::string get() const;
    void set(const std::string&);
};

Singleton& Singleton::instance()
{
    static Singleton self;
    return self;
}

std::string Singleton::get() const
{
    return str;
}

void Singleton::set(const std::string& s)
{
    str = s;
}

int main()
{
    Singleton& singleton = Singleton::instance();
    singleton.set("Singleton");
    Singleton& singleton2 = Singleton::instance();
    std::cout << singleton.get() << " " << singleton2.get() << std::endl; 
    return 0;
}
