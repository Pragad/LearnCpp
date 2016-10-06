#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// -----------------------------------------------------------------------------------------
// PROBLEM 1. Increment a value using mutex
// -----------------------------------------------------------------------------------------
// A Global variable x that will be shared by the threads
uint32_t x = 0;

void incrementX()
{
    for (uint32_t i = 0; i < 100; i++)
    {
        x = x + 1;
    }
}

mutex mtx2;
void incrementXMtx()
{
    // With unique_lock, we don't have to manually unlock. When the function goes out of scope
    // automatic unlock of the mutex happens
    unique_lock<mutex> lock(mtx2);
    for (uint32_t i = 0; i < 100; i++)
    {
        x = x + 1;
    }
}

// -----------------------------------------------------------------------------------------
// PROBLEM 2. Print Chars using Mutex
//
// Race Condition Here.
// We can't predict the order of execution.
// The order of execution depends on thread scheduling algorithm
// Multiple Runs of the same program will give different output
// -----------------------------------------------------------------------------------------
void printChars(uint32_t num, char ch)
{
    for (uint32_t i = 0; i < num; i++)
    {
        cout << ch << " ";
    }
    cout << endl;
}

// With Mutex to protect the critical section
// Declare a mutex variable
mutex mtx;
void printCharsMutex(uint32_t num, char ch)
{
    unique_lock<mutex> lock(mtx);
    for (uint32_t i = 0; i < num; i++)
    {
        cout << ch << " ";
    }
    cout << endl;
}

// -----------------------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------------------
int main()
{
    // Example 1
    {
        x = 0;
        thread th5 (incrementX);
        thread th6 (incrementX);

        th5.join();
        th6.join();
        cout << "Without Mutex X Val: " << x << endl;

        x = 0;
        thread th7 (incrementXMtx);
        thread th8 (incrementXMtx);

        th7.join();
        th8.join();
        cout << "With Mutex X Val: " << x << endl;
    }

    // Example 2
    {
        cout << "Without Mutex" << endl;
        thread th1 (printChars, 10, '*');
        thread th2 (printChars, 10, '$');

        th1.join();
        th2.join();

        cout << "With Mutex" << endl;
        thread th3 (printCharsMutex, 10, '*');
        thread th4 (printCharsMutex, 10, '$');

        // Main will wait for the threads to finish execution before continuing its work
        th3.join();
        th4.join();
    }

    cout << endl;
    return 0;
}
