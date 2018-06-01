#include <iostream>

using namespace std;

class A 
{
protected: 
    int a;
public: 
    A(int i): a(i) {}
    virtual void f() const { cout << "A: " << a << endl; };
};

class B: public A 
{
public: 
    B(int i): A(i) {}
    void f() const override { cout << "B: " << a << endl; }
};

class C: public B
{
public: 
    C(int i): B(i) {}
    void f() const override { cout << "C: " << a << endl; }
};


void f(const A& r) { r.f(); }


int main()
{
    A a(0);
    B b(1);
    C c(2);
   
    A* p = &a;
    p->f();
    p = &b;
    p->f();
    p = &c;
    p->f();
   
    f(a);
    f(b);
    f(c);
   
    A& ra = a;
    ra.f();
    A& rb = b;
    rb.f();
    A& rc = c;
    rc.f();
    
    f(ra);
    f(rb);
    f(rc);
    
    A& r = a;
    r.f();
    r = b;
    r.f();
    r = c;
    r.f();
    a.f();
   
    return 0;
}
