#include <iostream>

template <typename T1, typename T2>
class Template_class
{
    static constexpr int m_size = 10;
    T1 m_a1[m_size];
    T2 m_a2[m_size];

public:
    int size() const
    {
        return m_size;
    }
    
    void set(const T1& param1, const T2& param2, int index)
    {
        m_a1[index] = param1;
        m_a2[index] = param2;
    }
    
    void get(T1& param1, T2& param2, int index)
    {
        param1 = m_a1[index];
        param2 = m_a2[index];
    }
    
};

int main()
{
    Template_class<int, double> tc;
    
    std::cout << tc.size() << std::endl;
    
    for(int i = 0; i < tc.size(); ++i)
        tc.set(i + 1, i * 1.1, i);
        
    for(int i = 0; i < tc.size(); ++i) {
        int a;
        double b;
        tc.get(a, b, i);
        std::cout << a << " " << b << std::endl;
    }
    
    return 0;
}
