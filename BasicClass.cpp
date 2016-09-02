// Splunk
#include <iostream>
#include <vector>
using namespace std;

class B
{

};

class A
{
    private:
        B b3;           // A's size is now 4
        B *b1;          // A's size is now 8
        //B &b2; uninitialized reference member in 'class A'

    public:
        // Default Values:
        bool isValid;   // A's size is now 12
        int i;          // A's size is now 16
        vector<int> v;  // A's size is now 28
};

class C
{
    public:
        C() { }

    private:
        C(const C& ob) { }
        C& operator = (const C& ob) { }
};


int main()
{
    A a;
    B b1;
    B b2(b1);
    B b3 = b1;

    cout << "A's a size: " << sizeof(a) << endl;
    cout << "B's b1 size: " << sizeof(b1) << endl;
    cout << "B's b2 size: " << sizeof(b2) << endl;
    cout << "B's b3 size: " << sizeof(b3) << endl;

    // Default Values
    cout << "A's isValid: " << a.isValid << endl;
    cout << "A's i: " << a.i << endl;
    cout << "A's v: " << a.v.size() << endl;

    // Want Compile Time failures
    C c2;
    //C c1(c2);     // error: 'C::C(const C&)' is private 
    //C c3 = c2;    // error: within this context

    return 0;
}
