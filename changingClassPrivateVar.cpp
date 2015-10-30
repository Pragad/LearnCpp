// Using a Reference to a Pointer.
// This program helps to understand how to obtain a Class's
// private variable by passing a Reference to a Pointer.
// http://www.learncpp.com/cpp-tutorial/74-passing-arguments-by-address/

#include <iostream>
using namespace std;

class A
{
public:
    void increment()
    {
        cout << endl;
        cout << "Inc1 _x         : " << _x << endl;
        cout << "Inc1 *_arr      : " << *_arr << endl;

        (*_x) = 3;
        (*_arr)[0] = 1;
        (*_arr)[1] = 2;
        (*_arr)[2] = 3;

        cout << endl;
        cout << "Inc2 _x         : " << _x << endl;
        cout << "Inc2 *_arr      : " << *_arr << endl;
    }

    int getX()
    {
        return *_x;
    }

    // Get the address of the Variable that is passed in main.
    // x will now have &y2
    // x addr: 0x246ff08
    A (int* &arr, int* &x)
    {
        cout << endl;
        cout << "x      : " << x << endl;
        cout << "arr    : " << arr << endl;

        // _x will now have &y2
        // So *_x can be used to get to the value of y2
        _x = x;
        *_arr = arr;
        cout << "_x     : " << _x << endl;
        cout << "*_arr  : " << *_arr << endl;
    }

private:
    // _x will have &y2
    int* _x;
    int** _arr;
};

int main()
{
    cout << "Changing Class Private Variable" << endl << endl;

    // y2 Addr: 0x246ff08
    // y1 Addr: 0x246ff04
    int y2;
    int arr[5];

    int *y1 = &y2;
    int *yArr = arr;


    cout << "y1 value   : " << y1 << endl;
    cout << "y2 Addr    : " << &y2 << endl;

    cout << "yArr value : " << yArr << endl;
    cout << "arr Addr   : " << &arr << endl;

    A *obj1 = new A(yArr, y1);
    // This gives a compile time error. warning: initialization of non-const reference int *&' from rvalue `int *'
    // A *obj1 = new A(&y2);
    obj1->increment();

    cout << endl;
    cout << "obj1.getX(): " << obj1->getX() << endl;
    cout << "y2         : " << y2 << endl;
    cout << "[0]: " << arr[0] << "; [1]: " << arr[1] << "; [2]: " << arr[2] << endl;

    cout << endl;
    return 0;
}
