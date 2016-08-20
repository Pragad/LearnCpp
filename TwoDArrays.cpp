#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>        // std::fill_n
#include <queue>            // Priority Queue
#include <typeinfo>         // typeid
#include <vector>
#include <cmath>            // ciel
#include <cstring>          // memset
using namespace std;

int main()
{

    uint32_t rows = 3; 
    uint32_t cols = 5;

    // Set two D int array to 1
    {
        int **abc = new int*[rows];

        for (uint32_t i = 0; i < rows; i++)
        {
            abc[i] = new int[cols];
            //std::fill_n(*(abc+i), cols, sizeof(int));
            std::fill_n(*(abc+i), cols, 9);
        }

        //std::fill_n(abc, rows * cols, 1);
        //memset(abc, 1, rows * cols * sizeof(int));
        //memset(abc, 1, rows * cols * sizeof(*abc));

        for (uint32_t i = 0; i < rows; i++)
        {
            for (uint32_t j = 0; j < cols; j++)
            {
                cout << abc[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }

    // Set 2d bool array to true
    {
        bool **abc = new bool*[rows];

        for (uint32_t i = 0; i < rows; i++)
        {
            abc[i] = new bool[cols];
        }

        //std::fill_n(abc, rows * cols, 0);
    }
}
