#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

/*
 * PROBLEM 1. Find Right Most Set Bit
 * void findRightMostSetBit(int num)
 *
 * PROBLEM 2. Find Left Most Set Bit
 * int hob (int num)
 * int hibit(unsigned int n)
 * void findLeftMostSetBit(int num)
 *
 * PROBLEM 3. Count Number of Bits
 * uint32_t countNumBits(int num)
 *
 * PROBLEM 4. Set a Bit
 * void setBitInNum(int num, uint32_t bitPos)
 *
 * PROBLEM 5. Unset / Clear a Bit
 * void UnsetBitInNum(int num, uint32_t bitPos)
 *
 * PROBLEM 6. Toggle a Bit
 * void toggleBitInNum(int num, uint32_t bitPos)
 * 
 * PROBLEM 7. Check a Bit
 * uint32_t checkBitInNum(int num, uint32_t bitPos)
 * 
 * PROBLEM 8. Reverse bits in a number
 * int reverseBits(int num)
 */

// -----------------------------------------------------------------------------------------
// PROBLEM 1. Find Right Most Set Bit
// -----------------------------------------------------------------------------------------
void findRightMostSetBit(int num)
{
    std::bitset<4> x(num);
    cout << "Rightmost Set Bit of " << num << ": " << x << endl;

    {
        cout << (num & ~(num - 1)) << endl;
    }

    {
        cout << log2(num & -num) + 1 << endl;
    }
}

// -----------------------------------------------------------------------------------------
// PROBLEM 2. Find Left Most Set Bit
// -----------------------------------------------------------------------------------------
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
    cout << "Leftmost Set Bit of " << num << ": " << x << endl;
    
    {
        //cout << log2( 1 << (int)log2(num) ) + 1 << endl;
        cout << (int)log2(num) + 1 << endl;
    }

    {
        cout << log2(hob(num)) + 1 << endl;
    }

    {
        cout << log2(hibit(num)) + 1 << endl;
    }
}

// -----------------------------------------------------------------------------------------
// PROBLEM 3. Count Number of Bits
// -----------------------------------------------------------------------------------------
uint32_t countNumBits(int num)
{
    uint32_t cnt = 0;
    while (num)
    {
        num = num & (num - 1);
        cnt++;
    }

    return cnt;
}

// -----------------------------------------------------------------------------------------
// PROBLEM 4. Set a Bit
// -----------------------------------------------------------------------------------------
void setBitInNum(int num, uint32_t bitPos)
{

}

// -----------------------------------------------------------------------------------------
// PROBLEM 5. Unset / Clear a Bit
// -----------------------------------------------------------------------------------------
void UnsetBitInNum(int num, uint32_t bitPos)
{
 
}

// -----------------------------------------------------------------------------------------
// PROBLEM 6. Toggle a Bit
// -----------------------------------------------------------------------------------------
void toggleBitInNum(int num, uint32_t bitPos)
{

}

// -----------------------------------------------------------------------------------------
// PROBLEM 7. Check a Bit
// -----------------------------------------------------------------------------------------
uint32_t checkBitInNum(int num, uint32_t bitPos)
{

}
// -----------------------------------------------------------------------------------------
// PROBLEM 8. Reverse bits in a number
// -----------------------------------------------------------------------------------------
uint32_t reverseBits(uint32_t num)
{
    uint32_t revNum = 0;
    uint32_t numBits = (int)log2(num) + 1;
    for (; num; num >>= 1)
    {
        revNum = (revNum << 1) | (num & 1);
    }

    revNum = revNum << ((sizeof(num) * 8) - numBits);
    return revNum;
}

// -----------------------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------------------
int main()
{
    // PROBLEM 1. Find Right Most Set Bit
    {
        cout << endl << "PROBLEM 1. Find Right Most Set Bit" << endl;
        findRightMostSetBit(6);
        findRightMostSetBit(11);
    }

    // PROBLEM 2. Find Left Most Set Bit
    {
        cout << endl << "PROBLEM 2. Find Left Most Set Bit" << endl;
        findLeftMostSetBit(6);
        findLeftMostSetBit(11);
    }

    // PROBLEM 3. Count Number of Bits
    {
        cout << endl << "PROBLEM 3. Count Number of Bits" << endl;
    }

    // PROBLEM 4. Set a Bit
    {
        cout << endl << "PROBLEM 4. Set a Bit" << endl;
    }

    // PROBLEM 5. Unset / Clear a Bit
    {
        cout << endl << "PROBLEM 5. Unset / Clear a Bit" << endl;
    }

    // PROBLEM 6. Toggle a Bit
    {
        cout << endl << "PROBLEM 6. Toggle a Bit" << endl;
    }

    // PROBLEM 7. Check a Bit
    {
        cout << endl << "PROBLEM 7. Check a Bit" << endl;
    }

    // PROBLEM 8. Reverse bits in a number
    {
        cout << endl << "PROBLEM 8. Reverse bits in a number" << endl;
        cout << reverseBits(6) << endl;
        cout << reverseBits(16) << endl;
        cout << reverseBits(26) << endl;
        cout << reverseBits(36) << endl;
        cout << reverseBits(43261596) << endl;
    }

    cout << endl;
    return 0;
}
