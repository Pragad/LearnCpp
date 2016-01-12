// Using a Reference to a Pointer.
// This program helps to understand how to obtain a Class's
// private variable by passing a Reference to a Pointer.
// http://www.learncpp.com/cpp-tutorial/74-passing-arguments-by-address/
// http://stackoverflow.com/questions/33427454/understanding-passing-address-by-reference-in-c

#include <iostream>
using namespace std;

struct Person
{
    unsigned int age;
    float height;
    bool gender;
    char name;
};
 
class A
{
public:
    void increment()
    {
        cout << endl;
        (*_x) = 3;
        // Improvement got from StackOverflow
        /*
        (*_arr)[0] = 1;
        (*_arr)[1] = 2;
        (*_arr)[2] = 3;
        */
        _arr[0] = 1;
        _arr[1] = 2;
        _arr[2] = 3;
   }

    int getX()
    {
        return *_x;
    }

    // Get the address of the Variable that is passed in main.
    // x will now have &y2
    // x addr: 0x246ff08
    A (int* &arr, int* &x):
        _x(x),
        _arr(arr)
    {
        cout << endl;
        cout << "A::x      : " << x << endl;
        cout << "A::arr    : " << arr << endl;

        // _x will now have &y2
        // So *_x can be used to get to the value of y2
        //_x = x;

        // Improvement got from StackOverflow
        //*_arr = arr;
        cout << "A::_x     : " << _x << endl;
        cout << "A::_arr   : " << _arr << endl;
    }

private:
    // _x will have &y2
    int* _x;

    // Improvement got from StackOverflow
    // int ** _arr
    int* _arr;
};


// The following class is same as class A, but it makes use of
// private constructor and a public static function to call the
// constructor.
class B
{
public:
    static void create(int* &pArr, int* &pY, Person* &pPer)
    {
        cout << "B::Cr: xB      : " << pY << endl;
        cout << "B::Cr: arrB    : " << pArr << endl;
        cout << "B::Cr: pPer    : " << pPer << endl;
        B *objB = new B(pArr, pY, pPer);
        objB->incB();
        cout << endl;
    }

private:
    // Assign  values to the array and increment _x.
    void incB()
    {
        (*_xB)++;
        //(_arrB)[(*_xB)] = 11;
        (_arrB)[0] = 12;
        (*_xB)++;
        (_arrB)[1] = 12;
        (*_xB)++;
        (_arrB)[2] = 13;

        _pPer[0].age     = 5;
        _pPer[0].height  = 6.6;
        _pPer[0].gender  = 0;
        _pPer[0].name    = 'a';
    }

    // Get the address of the Variable that is passed in main. x will now have &y2.
    B (int* &arrB, int* &xB, Person* &pPer):
        _xB(xB),
        _arrB(arrB),
        _pPer(pPer)
    {
        cout << endl;
        cout << "B::xB      : " << xB << endl;
        cout << "B::arrB    : " << arrB << endl;
        cout << "B::pPer    : " << pPer << endl;

        cout << "B::_xB     : " << _xB << endl;
        cout << "B::_arrB   : " << _arrB << endl;
        cout << "B::_pPer   : " << _pPer << endl;
    }

    int* _xB;
    int* _arrB;
    Person* _pPer;
};


// Main Function
int main()
{
    cout << "Changing Class Private Variable" << endl << endl;

    // y Addr: 0x246ff08
    // pY Addr: 0x246ff04
    int y;
    int arr[5];

    int *pY = &y;
    int *pArr = arr;

    Person person[3];
    Person *pPerson = person;

    cout << "pY value   : " << pY << endl;
    cout << "y Addr     : " << &y << endl;

    cout << "pArr value : " << pArr << endl;
    cout << "arr Addr   : " << &arr << endl;

    A *obj1 = new A(pArr, pY);
    // This gives a compile time error. warning: initialization of non-const reference int *&' from rvalue `int *'
    // A *obj1 = new A(&y);
    obj1->increment();

    cout << "obj1.getX(): " << obj1->getX() << endl;
    cout << "y          : " << y << endl;
    cout << "[0]: " << arr[0] << "; [1]: " << arr[1] << "; [2]: " << arr[2] << endl;
    cout << endl;
    cout << endl;

    // Another class using Private Constructor and public static funciton to call the constructor.
    B::create(pArr, pY, pPerson);

    cout << "obj1.getX(): " << obj1->getX() << endl;
    cout << "y          : " << y << endl;
    cout << "[0]: " << arr[0] << "; [1]: " << arr[1] << "; [2]: " << arr[2] << endl;
    cout << "p[0].age: " << person[0].age << "; p[0].height: " << person[0].height << "; p[0].gender: " << person[0].gender << "; p[0].name: " << person[0].name << endl;
    cout << endl;

    cout << endl;
    return 0;
}
