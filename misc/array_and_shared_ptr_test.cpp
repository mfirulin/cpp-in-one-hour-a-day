#include <iostream>
#include <memory>
#include <array>
#include <algorithm>

using namespace std;

struct A { 
    int i = 1; 
    A() { cout << "created" << endl; }
    ~A() { cout << "destroyed" << endl; }
};

using APtr = std::shared_ptr<A>;

array<APtr, 10> a;

int main()
{
    a[0] = make_shared<A>();
    a[5] = make_shared<A>();
    a[9] = make_shared<A>();
   
    for_each(a.cbegin(), a.cend(), [](const APtr& e) { if (e) cout << e->i << endl; else cout << "undefined" << endl; } );
    
    for_each(a.begin(), a.end(), [](APtr& e) { e.reset(); } );
    
    for_each(a.begin(), a.end(), [](const APtr& e) { if (e) cout << e->i << endl; else cout << "undefined" << endl; } );
   
    return 0;
}
