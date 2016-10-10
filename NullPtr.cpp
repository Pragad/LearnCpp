#include <iostream>
using namespace std;

void printA1(int ptr)
{
    cout << "printA1" << endl;
}

void printA2(int* ptr)
{
    cout << "printA2" << endl;
}

int main()
{
    int* pA = NULL;
    int* pB = nullptr;

    // The below line throws a warning
    // NullPtr.cpp:19:17: warning: passing NULL to non-pointer argument 1 of 'void printA1(int)' [-Wconversion-null]
    printA1(NULL);
    printA2(NULL);

    // The below line throws an error
    // NullPtr.cpp:22:20: error: cannot convert 'std::nullptr_t' to 'int' for argument '1' to 'void printA1(int)'
    printA1(nullptr);
    printA2(nullptr);
    return 0;
}
