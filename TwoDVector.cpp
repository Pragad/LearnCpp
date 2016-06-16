#include <iostream>
#include <vector>
using namespace std;

int main()
{
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
