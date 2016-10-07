#include <iostream>
#include <vector>
using namespace std;

void printVectorInt(const vector<int>& vec)
{
    for (auto v : vec)
    {
        cout << v << ", ";
    }
    cout << endl;
}

int main()
{
    // Add elements to TwoD vector and print it
    {
        cout << endl << "Case 1" << endl;
        uint32_t rows = 2;
        uint32_t cols = 3;

        vector< vector<int> > myTwoDVec(rows, vector<int> (cols, 5));

        for (uint32_t i = 0; i < rows; i++)
        {
            for (uint32_t j = 0; j < cols; j++)
            {
                cout << myTwoDVec[i][j] << " ";
            }
            cout << endl;
        }

        vector< vector<bool> > myTwoDBoolVec(rows, vector<bool> (cols, false));

        for (uint32_t i = 0; i < rows; i++)
        {
            for (uint32_t j = 0; j < cols; j++)
            {
                cout << myTwoDBoolVec[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Adding at a random point to a vector
    {
        cout << endl << "Case 2" << endl;
        vector<int> vec;
        vec.reserve(10);

        cout << vec.size() << endl;
        // The below line crashes the program
        //vec.insert(vec.begin() + 2, 5);

        printVectorInt(vec);
    }

}
