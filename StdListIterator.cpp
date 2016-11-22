#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main()
{
    {
        // Insert will happen at the END
        // Delete will happen at the FRONT
        list<int> myList;
        list<int>::iterator it = myList.begin();
        unordered_map<int, list<int>::iterator> myListMap;

        // Insert 5 elements
        myList.insert(it, 10);
        myListMap[10] = it;
        it = myList.begin();

        myList.insert(it, 20);
        myListMap[20] = it;
        it = myList.begin();

        myList.insert(it, 30);
        myListMap[30] = it;
        it = myList.begin();

        myList.insert(it, 40);
        myListMap[40] = it;
        it = myList.begin();

        myList.insert(it, 50);
        myListMap[50] = it;
        it = myList.begin();

        for (list<int>::iterator i1 = myList.begin(); i1 != myList.end(); ++i1)
        {
            cout << " " << *i1;
        }
        cout << endl;

        // Remove 3 by using the Map
        auto itr = myListMap.find(30);
        cout << "Itr: " << *(itr->second) << endl;
        myList.erase(itr->second);
        myListMap.erase(itr);

        for (list<int>::iterator i1 = myList.begin(); i1 != myList.end(); ++i1)
        {
            cout << " " << *i1;
        }
        cout << endl;

        auto itr2 = myListMap.find(10);
        myList.splice(myList.begin(), myList, itr2->second);
        for (list<int>::iterator i1 = myList.begin(); i1 != myList.end(); ++i1)
        {
            cout << " " << *i1;
        }
        cout << endl;
    }


    {
        std::list<int> mylist1, mylist2;
        std::list<int>::iterator it;

        // set some initial values:
        for (int i=1; i<=4; ++i)
         mylist1.push_back(i);      // mylist1: 1 2 3 4

        for (int i=1; i<=3; ++i)
         mylist2.push_back(i*10);   // mylist2: 10 20 30

        it = mylist1.begin();
        ++it;                         // points to 2

        mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                    // mylist2 (empty)
                                    // "it" still points to 2 (the 5th element)
                                              
        mylist2.splice (mylist2.begin(),mylist1, it);

        std::cout << "mylist1 contains:";

        for (it=mylist1.begin(); it!=mylist1.end(); ++it)
        {
            std::cout << ' ' << *it;
        }
        std::cout << '\n';

        std::cout << "mylist2 contains:";
        for (it=mylist2.begin(); it!=mylist2.end(); ++it)
        {
            std::cout << ' ' << *it;
        }
        std::cout << '\n';
    }
    cout << endl;
    return 0;
}
