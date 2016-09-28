#include <iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout << "A before main" << endl;
    }
} a;

int myFun()
{
    cout << "My fun before main" << endl;
    return 0;
}

int X = myFun();

int main()
{
    cout << "Main" << endl;
    return 0;
}
