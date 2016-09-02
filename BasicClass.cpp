// Splunk
#include <iostream>
#include <vector>
using namespace std;

class B
{

};

class A
{
    public:
        B *b1;          // 0x61fefc A's size is now 4. As this is a pointer, sizeof(b4) is 1
        B b3;           // 0x61ff00 A's size is now 8. Since 'class B' is empty sizeof(b3)= 1
        //B &b2;        // ERR: uninitialized reference member in 'class A'

    public:
        // Default Values:
        bool isValid;   // 0x61ff01 A's size is now 8
        int i;          // 0x61ff04 A's size is now 12
        vector<int> v;  // 0x61ff08 A's size is now 24
        B b4;           // 0x61ff14 A's size is now 28. But since 'class B' is empty sizeof(b4) is 1
        int j;          // A's size is 32
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
    {
        A a;
        B b1;
        B b2(b1);
        B b3 = b1;

        // IMP:
        // &a and &a.b1 ARE SAME
        cout << "A's a size: " << sizeof(a) << "; at : " << &a << endl;
        cout << "A's a.b1 size: " << sizeof(a.b1) <<  "; at : " << &(a.b1) << endl;
        cout << "A's a.b3 size: " << sizeof(a.b3) <<  "; at : " << &(a.b3) << endl << endl;
        cout << "A's a.isValid: " << sizeof(a.isValid) <<  "; at : " << &(a.isValid) << endl;
        cout << "A's a.i size: " << sizeof(a.i) <<  "; at : " << &(a.i) << endl;
        cout << "A's a.v size: " << sizeof(a.v) <<  "; at : " << &(a.v) << endl;
        cout << "A's a.b4 size: " << sizeof(a.b4) <<  "; at : " << &(a.b4) << endl;
        cout << "A's a.j size: " << sizeof(a.j) <<  "; at : " << &(a.j) << endl << endl;

        cout << "B's b1 size: " << sizeof(b1) <<  "; at : " << &(b1) << endl;
        cout << "B's b2 size: " << sizeof(b2) <<  "; at : " << &(b2) << endl;
        cout << "B's b3 size: " << sizeof(b3) <<  "; at : " << &(b3) << endl << endl;

        // Default Values
        cout << "VALUES" << endl;
        cout << "A's isValid: " << a.isValid << endl;
        cout << "A's i: " << a.i << endl;
        cout << "A's v: " << a.v.size() << endl;
    }

    {
        // Want Compile Time failures
        C c2;
        //C c1(c2);     // error: 'C::C(const C&)' is private 
        //C c3 = c2;    // error: within this context
    }

    return 0;
}
