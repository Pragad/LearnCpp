#include <exception>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdexcept>
using namespace std;

// ---------------------------------------------------------------------------------------
// Main Function
// ---------------------------------------------------------------------------------------
vector<uint32_t> getRandomNumbers(uint32_t num, uint32_t randomNumCount)
{
    vector<uint32_t> allNumsList;
    vector<uint32_t> randomNumsList;
    uint32_t maxNum = num;

    // Make sure than M is less than N
    if (randomNumCount > num)
    {
        throw std::invalid_argument("M is greater than N");
    }

    // Create a list of N numbers from 0 to N-1
    for (uint32_t i = 0; i < num; i++)
    {
        allNumsList.push_back(i);
    }

    // Use Time as seed to generate different random numbers each time
    srand(time(NULL));
    for (uint32_t i = 0; i < randomNumCount; i++)
    {
        // Generate a random number between 0 and N
        uint32_t tmp = rand() % (maxNum);

        // Add the random number corresponding to the index to the Result
        randomNumsList.push_back(allNumsList[tmp]);

        // Swap position of random number with the max num in the list
        swap(allNumsList[tmp], allNumsList[maxNum-1]);
        maxNum--;
    }

    return randomNumsList;
}

// using standard exceptions
class MyException: public exception
{
  virtual const char* what() const throw()
  {
    return "My Custom Exception Returned";
  }
} myEx;

int main()
{
    // PROBLEM 1. Try Catch Exception example
    {
        cout << endl << "PROBLEM 1. Reverse Data in a 1D array and return new array" << endl;
        try 
        {
            vector<uint32_t> randomNums = getRandomNumbers(10, 11);
        }
        catch (const std::invalid_argument& e)
        {
            cout << "EXCEPTION OCCURRED: " << e.what() << endl;
        }

    }

    // PROBLEM 2. Custom Exception
    {
        cout << endl << "PROBLEM 2. Custom Exception" << endl;
        try
        {
            throw myEx;
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
    }
}
