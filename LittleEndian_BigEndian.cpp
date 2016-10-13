#include <iostream>
using namespace std;

/*
// Big endian machines:
//      FIRST byte of binary representation of the multibyte data-type is stored first
//      So "01" gets stored first
//
/ Little endian:
//      LAST byte of binary representation of the multibyte data-type is stored first
//      So "67" gets stored first
/
//    Num = 0x01234567
//
//    Big Endian:
//      0x100   0x101   0x102   0x103
//    +-------+-------+-------+-------+
//    | 0x01  | 0x23  | 0x45  | 0x67  |
//    +-------+-------+-------+-------+
//
//    Little Endian:
//      0x100   0x101   0x102   0x103
//    +-------+-------+-------+-------+
//    | 0x67  | 0x45  | 0x23  | 0x01  |
//    +-------+-------+-------+-------+
//
//    Num = 0x00000001
// 
//    Big Endian:
//      0x100   0x101   0x102   0x103
//    +-------+-------+-------+-------+
//    | 0x00  | 0x00  | 0x00  | 0x01  |
//    +-------+-------+-------+-------+
//    |
//    &i
// 
//    Little Endian:
//      0x100   0x101   0x102   0x103
//    +-------+-------+-------+-------+
//    | 0x01  | 0x00  | 0x00  | 0x00  |
//    +-------+-------+-------+-------+
//    |
//    &i
//
*/
int main()
{
    unsigned int i = 1;
    char *c = (char*)&i; // Storing the 0th byte of 'i' in 'c'

    if (*c)
    {
        cout << "Little Endian" << endl;
    }
    else
    {
        cout << "Big Endian" << endl;
    }
}
