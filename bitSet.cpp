#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    ifstream iFile("billionInts.txt");
    string line;
    bitset<1000> myNumBitSet;

    if (iFile.is_open())
    {
        // VERY IMP
        while (getline(iFile, line))
        {
            if (!iFile.eof())
            {
                int x = stoi(line);
                myNumBitSet[x] = 1;
            }
            else
            {
                cout << "EOF reached" << endl;
            }
        }

        /*
        while (!iFile.eof())
        {
            getline(iFile, line);
            cout << line << endl;
            //int x = stoi(line);
            //myNumBitSet[x] = 1;
        }
        */

        iFile.close();
    }
    else
    {
        cout << "Error opening the file" << endl;
    }

    // Go through the bits and find the one that is not set.
    for (size_t i = 0; i < myNumBitSet.size(); ++i)
    {
        if (myNumBitSet[i] == 0)
        {
            // This is the missing number
            cout << "Missing Num: " << i << endl;
        }
    }
}
