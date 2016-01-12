#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    // 1. VECTORS
    // This will add 3 5's to the vector
    std::vector<int> numsSimp (3, 5);

    // Create a Vector from an Array
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    // Tells the Version of _c++. Used to check if C++ 11 is being used.
    cout << "__c++: " <<__cplusplus << endl;

    // First way to iterate through a vector. Using AUTO
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout <<endl;
    
    // Second Way. Using Iterator
    // We can move the iterator to a specific position as well.
    for (std::vector<int>::iterator it = nums.begin() + 2; it != nums.end(); it++)
    {
        cout << *it << " ";
    }  
    cout <<endl;
    
    // Using .at() to access a specific element.
    // Also we have use ARRAY representation
    for (unsigned int i = 0; i < nums.size(); i++)
    {   
        //cout << nums.at(i) << " ";
        cout << nums[i] << " ";
    }
    cout <<endl;


    // 1b. Inserting multiple elements into Vector
    std::vector<int> v{2,5,8,11,14};
    std::vector<int> v = {2,5,8,11,14};

    // 2. UNORDERED MAP
    unordered_map<int, int> myHash;
    myHash[5] = 0;
    cout << myHash[5] << endl;
}
