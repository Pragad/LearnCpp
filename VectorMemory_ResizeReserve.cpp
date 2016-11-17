#include <iostream>
#include <vector>
using namespace std;

// Bloomberg Phone Interview Questions
int main()
{
    // Problem 1
    {
        cout << endl << "Problem 1" << endl;
        vector<int> vec; // holds 0 elements

        // The below line will crash the Program as we are using the memory without initializing
        //int a = vec[0];

        cout << "Cap: " << vec.capacity() << " ; Size: " << vec.size() << endl;
        // Output: Cap: 0 ; Size: 0 
    }

    // Problem 2: reserve
    {
        cout << endl << "Problem 2" << endl;
        vector<int> vec; // holds 0 elements

        // IMP: Doesn't ZERO the elements. Just allocates memory
        vec.reserve(100); // Allocates space for 100 items, and vec2 IS STILL EMPTY.

        // This works as we have allocated memory
        int a = vec[0];
        int b = vec[99];

        cout << "Cap: " << vec.capacity() << " ; Size: " << vec.size() << endl;
        cout << a << ", " << b << endl;
        // Output:  Cap: 100 ; Size: 0
        //          6758944, 0
    }

    // Problem 3: resize
    {
        cout << endl << "Problem 3" << endl;
        vector<int> vec; // holds 0 elements

        vec.resize(100); // Allocates space for 100 items, and vec now has 100 items

        // This works as we have allocated memory
        int a = vec[0];
        int b = vec[99];

        cout << "Cap: " << vec.capacity() << " ; Size: " << vec.size() << endl;
        cout << a << ", " << b << endl;
        // Output:  Cap: 100 ; Size: 100
        //          0, 0
    }

    // Problem 4
    {
        cout << endl << "Problem 4" << endl;
        vector<int> vec(100);

        // This works as the memory is allocated and 0 gets printed
        int a = vec[0];
        int b = vec[99];

        cout << "Cap: " << vec.capacity() << " ; Size: " << vec.size() << endl;
        cout << a << ", " << b << endl;
        // Output:  Cap: 100 ; Size: 100
        //          0, 0
    }

    // Problem 5
    {
        cout << endl << "Problem 5" << endl;
        vector<int> vec(100);

        int& a = vec[0]; // Creating a reference to vec[0]
        a = 100;         // Changing the reference should change vec[0]

        cout << a << ", " << vec[0] << endl;
        // Output:  100, 100
    }

    // Problem 6
    // http://stackoverflow.com/questions/7181372/why-can-i-assign-a-new-value-to-a-reference-and-how-can-i-make-a-reference-refe
    {
        cout << endl << "Problem 6" << endl;
        vector<int> vec(100);

        int& a = vec[0];
        int x = 200;

        // HERE WE ARE JUST CHANGING THE VALUE THAT 'a' IS POINTING
        // WE ARE NOT making 'a' point to x
        a = x;          
        a = 500;

        cout << a << ", " << vec[0] << ", " << x << endl;
        // Output: 500, 500, 200
    }

    cout << endl;
    return 0;
}
