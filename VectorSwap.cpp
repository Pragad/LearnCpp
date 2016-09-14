#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> nums)
{
    for (auto num : nums)
    {
        cout << num << ",";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    printVector(nums);
    std::iter_swap(nums.begin() + 2, nums.end() - 1);
    printVector(nums);

    cout << endl;
    return 0;
}
