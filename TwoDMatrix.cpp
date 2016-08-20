#include <iostream>
#include <vector>
using namespace std;

// Allocate Memory to a 2D array using NEW
// Riverbed phone interview
int** allocate ( int row, int col )
{
    if (row < 0)
    {
        cout << "Invalid row" << endl;
        return NULL;
    }

    if (col < 0)
    {
        cout << "Invalid col" << endl;
        return NULL;
    }

    int** twoDarray = new(std::nothrow) int*[row];
    if (twoDarray != NULL)
    {
        for (unsigned int i = 0; i < row; i++)
        {
            twoDarray[i] = new (std::nothrow) int[col];

            if (twoDarray[i] == NULL)
            {
                for (unsigned int tmp = 0; tmp < i; tmp++)
                {
                    delete twoDarray[tmp];
                }
        
                delete[] twoDarray;
                return NULL;
            }
        }
    }
    else
    {
        return NULL;
    }

    return twoDarray;
}

template <size_t rows, size_t cols>
void printTwoDMatrix(int (&matrix)[rows][cols])
{
    for (uint32_t i = 0; i < rows; i++)
    {
        for (uint32_t j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printTwoDPtrToPtr(int** array, uint32_t rows, uint32_t cols)
{
    for (uint32_t i = 0; i < rows; i++)
    {
        for (uint32_t j = 0; j < cols; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void printTwoDVec(vector< vector<int> > twoDVec)
{
    cout << "Two D Vector" << endl;
    for (uint32_t i = 0; i < twoDVec.size(); i++)
    {
        for (uint32_t j = 0; j < twoDVec[i].size(); j++)
        {
            cout << twoDVec[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // How to allocate a 2-D array in C++
    int matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    // VERY IMP: The values should be compile time.
    // Does not work if the values are got from run time
    int twoD[5][5] = {{1, 1, 0, 0, 0},
                            {0, 1, 0, 0, 1},
                            {1, 0, 0, 1, 1},
                            {0, 0, 0, 0, 0},
                            {1, 0, 1, 0, 1}};

    uint32_t rows = 5;
    uint32_t cols = 5;
    int **arrayTwoD = new int *[rows];

    for (uint32_t i = 0; i < rows; i++)
    {
        arrayTwoD[i] = new int[cols];
    }

    for (uint32_t i = 0; i < rows; i++)
    {
        for (uint32_t j = 0; j < cols; j++)
        {
            arrayTwoD[i][j] = twoD[i][j];
        }
    }

    printTwoDPtrToPtr(arrayTwoD, rows, cols);

    // VERY IMP: the below will fail.
    // Can't cast 'int (*)[5]' to 'int**'
    //printTwoDPtrToPtr((int**)twoD, rows, cols);

    // Initialize 2D array to 0
    {
        rows = 3;
        cols = 4;
        vector< vector<int> > myTwoDVec(rows, vector<int> (cols, 5));
        printTwoDVec(myTwoDVec);
    }
    cout << endl;
    return 0;
}
