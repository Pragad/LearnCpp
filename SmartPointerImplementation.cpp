#include <iostream>
using namespace std;

template <class T>
class smartPtr
{
    T* ptr;

public:
    explicit smartPtr(T* p = 0) : ptr(p)
    {
        cout << "In Smart A's Constructor" << endl;
    }

    ~smartPtr()     
    {
        cout << "In Smart A's Destructor" << endl;
        delete ptr;
    }

    T& operator*() 
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    void func1()
    {
        cout << "In Smart A's func1" << endl;
    }
};

class A
{
public:
    A()
    {
        cout << "In A's Constructor" << endl;
    }

    ~A()
    {
        cout << "In A's Destructor" << endl;
    }

    void func1()
    {
        cout << "In A's func1" << endl;
    }
};

int main()
{
    // Normal Pointer
    {
        cout << endl << "Default Pointer" << endl;
        A* ob = new A();
        ob->func1();
        delete ob;
    }

    // Smart Pointer
    {
        cout << endl << "Smart Pointer" << endl;
        smartPtr <A> ob(new A);
        ob->func1();
    }

    return 0;
}
