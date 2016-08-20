#include <iostream>
#include <cstddef>
#include <strings.h>
using namespace std;

#ifdef _WIN32
typedef signed char 	        int8_t;
typedef unsigned char 	        uint8_t;
typedef signed short int 	    int16_t;
typedef unsigned short int 	    uint16_t;
typedef signed long int 	    int32_t;
typedef unsigned long int 	    uint32_t;
typedef signed long long int 	int64_t;
typedef unsigned long long int 	uint64_t;
#else
#include <stdint.h>
#endif

struct Book
{
    char *title;
    uint32_t date;
    uint32_t year;
};

int main()
{
    Book *b;
    uint32_t numElmts = 5;

    b = new Book[numElmts];
    for (uint32_t i = 0; i < numElmts; i++)
    {
        // IMP: bzero is deprecated.
        //bzero(&b[i], sizeof(Book));
        memset(&b[i], 0, sizeof(Book));
    }


    for (uint32_t i = 0; i < numElmts; i++)
    {
        b[i].title = "Hello";
        b[i].date = 20151112;
        b[i].year = 1998;
    }

    for (uint32_t i = 0; i < numElmts; i++)
    {
        cout << endl;
        cout << b[i].title << endl;
        cout << b[i].date << endl;
        cout << b[i].year << endl;
    }

    // IMP: new/delete AND new[]/delete[] goes hand in hand.
    // IMP: Delete only if the pointer is NOT null
    if (b != NULL)
    {
        delete [] b;

        // IMP: Optional to make "b" NULL again.
        // http://stackoverflow.com/questions/1931126/is-it-good-practice-to-null-a-pointer-after-deleting-it
        //b = nullptr;
        b = NULL;
    }
    cout << endl;

    // Scenario 1:
    int a1[3] = {1,2,3};
    int *p1;

    p1 = a1;
    cout << p1[0] << " " << p1[1] << " " << p1[2] << endl;
    cout << endl;

    // Scenario 2:
    int *a2 = new int[3];
    int *p2;
    a2[0] = 5;
    a2[1] = 6;
    a2[2] = 7;

    p2 = a2;
    cout << p2[0] << " " << p2[1] << " " << p2[2] << endl;

    cout << endl;
}
