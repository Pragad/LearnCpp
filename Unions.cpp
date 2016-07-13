#include <iostream>
using namespace std;

struct dirEntry
{
    uint8_t     dirType;
    int8_t      fileName[9];
    uint16_t    lastBlockUsedBytes;
    uint32_t    actualBlockNumber;
};


struct directory
{
    uint32_t    prevBlock;
    uint32_t    nextBlock;
    uint32_t    firstUnusedBlock;
    uint32_t    fillerChar;
    dirEntry    dirEntries[31];
};

struct file
{
    uint32_t    prevBlock;
    uint32_t    nextBlock;
    uint8_t     fileData[504];
};

// IMP: If the structure is declared inside the Union, then the size of the union will be
// considered as ONE.

union block
{
    directory   directoryEntry;
    file        fileEntry;
};

int main()
{
    cout << sizeof(directory) << endl;
    cout << sizeof(file) << endl;
    cout << sizeof(block) << endl;
    cout << endl;
    return 0;
}
