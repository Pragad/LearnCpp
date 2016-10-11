#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

void findRightMostSetBit(int num)
{
    std::bitset<4> x(num);
    cout << endl << "Rightmost Set Bit of " << num << ": " << x << endl;

    {
        cout << (num & ~(num - 1)) << endl;
    }

    {
        cout << log2(num & -num) + 1 << endl;
    }
}

int hob (int num)
{
    if (!num)
        return 0;

    int ret = 1;

    while (num >>= 1)
        ret <<= 1;

    return ret;
}

int hibit(unsigned int n)
{
    n |= (n >>  1);
    n |= (n >>  2);
    n |= (n >>  4);
    n |= (n >>  8);
    n |= (n >> 16);
    return n - (n >> 1);
}

void findLeftMostSetBit(int num)
{
    std::bitset<4> x(num);
    cout << endl << "Leftmost Set Bit of " << num << ": " << x << endl;
    
    {
        cout << log2( 1 << (int)log2(num) ) + 1 << endl;
    }

    {
        cout << log2(hob(num)) + 1 << endl;
    }

    {
        cout << log2(hibit(num)) + 1 << endl;
    }
}

int main()
{
    findRightMostSetBit(6);
    findRightMostSetBit(11);
    findLeftMostSetBit(6);
    findLeftMostSetBit(11);
    cout << endl;
    return 0;
}
