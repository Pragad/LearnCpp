#include <iostream>
#include <string>
using namespace std;

#ifdef _WIN32
typedef char 	                uint8_t;
typedef unsigned short int 	    uint16_t;
typedef unsigned int 	        uint32_t;
typedef unsigned long long int 	uint64_t;
#else
#include <stdint.h>
#endif

// Q1. Assigning value to a struct inside a union
// http://stackoverflow.com/questions/17556780/how-can-i-assign-value-to-the-struct-inside-union-here

int main()
{
    // Q2. We can't enter a string with just 5 characters.
    // http://stackoverflow.com/questions/579734/assigning-strings-to-arrays-of-characters
    //
    // Q3: IMP: Array Decaying
    // http://stackoverflow.com/questions/10088661/assigning-a-string-of-characters-to-a-char-array?lq=1
    uint8_t fileName[9];
    //strncpy(fileName, "hello", 9);
    //fileName = "hello000";
    cout << fileName << endl;


    int *a;
    int *b; 
   // *a = 5;
    /*
    cout<<a<<endl;
    cout<<*a<<endl;
    cout<<b<<endl;
    cout<<*b<<endl;
    
    char test[9];
    std::string str("HelloWorld");

    str.copy(test, 5);
    cout << test << endl;
    */

    string tempStr = "xyz";
    tempStr[0] = 'a';
    tempStr[1] = 'b';
    tempStr[2] = 'c';
    cout << "TempStr: " << tempStr << endl;
    cout <<  endl;
    return 0;
}
