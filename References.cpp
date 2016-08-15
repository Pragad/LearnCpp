#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

void printVector(vector< stack<uint32_t> >& nums)
{
    cout << "Print Vector of Stacks" << endl;
    for (auto num : nums)
    {
        cout << num.top() << ", ";
    }
    cout << endl;
}

void printUnorderedMap(unordered_map<uint32_t, uint32_t> myMap)
{
    cout << "Print Map" << endl;
    for (auto mm : myMap)
    {
        cout << mm.first << ": " << mm.second << " , ";
    }
    cout << endl;
}

void fun2(vector< stack<uint32_t> >& myStack,
          unordered_map<uint32_t, uint32_t>& stackIdx)
{
    cout << "In Fun 2" << endl;
    printVector(myStack);
    printUnorderedMap(stackIdx);
}


void fun1(vector< stack<uint32_t> >& myStack,
          unordered_map<uint32_t, uint32_t>& stackIdx)
{
    cout << "In Fun 1" << endl;
    fun2(myStack, stackIdx);
}

int main()
{
    vector< stack<uint32_t> > myStack(5);
    unordered_map<uint32_t, uint32_t> stackIdx {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

    cout << "Main" << endl;

    myStack[0].push(1);
    myStack[1].push(2);
    myStack[2].push(3);
    myStack[3].push(4);
    myStack[4].push(5);

    cout << "Calling Fun from Main" << endl;
    fun2(myStack, stackIdx);

    cout << endl;
    return 0;
}

