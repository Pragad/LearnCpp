#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<string> namesList;
    unordered_map<string, list<string>::iterator> namesMap;

    namesList.push_front("hello");
    namesMap["hello"] = namesList.begin();

    namesList.push_front("hi");
    namesMap["hi"] = namesList.begin();

    namesList.push_front("abc");
    namesMap["abc"] = namesList.begin();

    // Now to access "hi" on the list, I can just look it up on the map
    // Get iterator to "hi" from the map and access it
    auto itr = namesMap.find("hi");
    if (itr != namesMap.end())
    {
        // This is a simple case where my list is just storing the key
        cout << *(itr->second) << endl;
    }
    
    cout << endl;
    return 0;
}
