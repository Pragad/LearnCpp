#include <iostream>
#include <stdio.h>
#include <signal.h>
using namespace std;

/*
// warning: reference to local variable 'i' returned [-Wreturn-local-addr]
int& foo()
{
    int i = 0;
    return i;
}
*/

int main()
{
    {
        /*
        int a = 5;
        int *p = nullptr;
        *p = 1;

        char * ptr = 0;
        *ptr = 1;
        */
    }

    // Can't do it in C++ 's' should be a const char *
    //  warning: deprecated conversion from string constant to 'char*' [-Wwrite-strings]
    {
        /*
        char* s = "abc";
        s = "def";
        */
    }

    {
        /*
        char *c = new char[10];
        delete [] c;
        c[1] = 'a'; 
        */
    }

    {
        *(char *)0 = 0;
    }

    cout << endl;
    return 0;
}
