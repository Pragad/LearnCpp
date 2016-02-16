#include <iostream>
#include <unordered_map>
using namespace std;

struct Info
{
    string name;
    uint32_t score;
};

int main()
{
    unordered_map<char, Info> myMap;
    myMap['a'] = {"apple", 5};
    myMap['b'] = {"boy", 8};
    myMap['c'] = {"cat", 7};

    for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
    {
        cout << itr->first << ": " << itr->second.name << " , " << itr->second.score << endl;
    }
    cout << endl;

    for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
    {
        itr->second.score = 5;
    }


    for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
    {
        cout << itr->first << ": " << itr->second.name << " , " << itr->second.score << endl;
    }
    cout << endl;


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
