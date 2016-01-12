#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> sampIntHash;

    //int a[7] = {5, 6, 7, 8, 6, 9, 7};
    char a[7] = {'v', 'q', 'b', 'l', 'q', 'c', 'b'};

    for (unsigned int i = 0; i < sizeof(a)/sizeof(char); i++)
    {
        cout << "A: " << a[i] << " " << endl;

        auto tmpIntHash = sampIntHash.find(a[i]);

        if (tmpIntHash != sampIntHash.end())
        {
            cout << "Present" << endl;
        }
        else
        {
            sampIntHash[a[i]] = i;
        }
    }

    for (auto itr = sampIntHash.begin(); itr != sampIntHash.end(); itr++)
    {
        cout << "Itr: " << itr->first << " : " << itr->second << endl;
    }


    return 0;
}
