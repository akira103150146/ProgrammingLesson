#include <iostream>
using namespace std;
int main()
{
    int a = 10, b = 20;
    int *p = &a, *q = &b, *r;
    *p = *q + b;
    cout << "a =" << a << " b =" << b << endl;
    r = p;
    a = 30;
    cout << "*q =" << *q << ", *r =" << *r << endl;
    *r += 3;
    *q = *r;
    cout << "a =" << a << " b =" << b << endl;
    *p = *q + *r;
    cout << "a =" << a << " b = " << b << endl;
    cout << " *q = " << *q << ", *r = " << *r << endl;
    p = q;
    q = r;
    r = p;
    cout << " *q = " << *q << ", *r = " << *r << endl;
}