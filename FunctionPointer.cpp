#include <iostream>
#include <vector>
using namespace std;

// Case 1:
void add(int a, int b)
{
    cout << "Addition is: " << a+b << endl;
}

void subtract(int a, int b)
{
    cout << "Subtraction is: " << a-b << endl;
}

void multiply(int a, int b)
{
    cout << "Multiplication is: " << a*b << endl;
}

// Case 2:
void fillRandomValues(vector<int>& randVec, int (*fnPtrRand)(void))
{
    for (uint32_t i = 0; i < randVec.size(); i++)
    {
        randVec[i] = fnPtrRand();
    }
}

int generateRandom()
{
    return rand() % 10;
}

// Case 3:
void doSomeOp(string str, void (*fnPtrOp)(string))
{
    fnPtrOp(str);
}

void printString(string s)
{
    cout << "String: " << s << endl;
}

int main()
{
    {
        // fun_ptr_arr is an array of function pointers
        void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
        unsigned int ch, a = 15, b = 10;
     
        cout << "Enter Choice: 0 for add, 1 for subtract and 2 for multiply: ";
        // cin >> ch;
        ch = 1;
     
        if (ch > 2) return 0;
     
        (*fun_ptr_arr[ch])(a, b);
    }

    {
        vector<int> randVec(10);
        fillRandomValues(randVec, generateRandom);

        for (int i : randVec)
        {
            cout << i << ", ";
        }
        cout << endl;
    }

    {
        string str = "Hello";
        doSomeOp(str, printString); 
    }

    return 0;
}
