#include <iostream>
#include <memory>       // Unique Pointer
#include <unordered_map>
using namespace std;

int main()
{
    // 1. Create a normal Pointer
    {
        int *pInt = new int(5);
        cout << "Pint: " << *pInt << endl;
        delete pInt;
    }

    // 2. Create a Unique Pointer
    {
        unique_ptr<int> pUniqInt (new int(5));
        cout << "UniqPint: " << *pUniqInt << endl;

        std::unordered_map<int, std::unique_ptr<int>> intMap;

        // 2a. Not able to insert it using the below line
        //intMap[5] = pUniqInt;

        // 2b. Insert INT, Unique Pointer into a map
        int num3 = 3;
        intMap.insert(make_pair(num3, unique_ptr<int>(new int(3))));

        // 2c. Insert INT, Unique Pointer using previous objects
        // Requires std::move to push into the map
        int num = 2;
        unique_ptr<int> pNum2 (new int(2));
        intMap.insert(make_pair(num, std::move(pNum2)));

        // 2d. Check if an element is present in the map
        auto itr = intMap.find(3);
        if (itr != intMap.end())
        {
            cout << "Present" << endl;
        }

        // 2e. Print the contents of a map
        for (auto itr = intMap.begin(); itr != intMap.end(); itr++)
        {
            cout << itr->first << " : ";
            cout << *(itr->second) << endl;
        }
    }

    cout << endl;
    return 0;
}
