#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

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

int main()
{
    thread th1 (printChars, 10, '*');
    thread th2 (printChars, 10, '$');

    th1.join();
    th2.join();

    thread th3 (printCharsMutex, 10, '*');
    thread th4 (printCharsMutex, 10, '$');

    th3.join();
    th4.join();

    cout << endl;
    return 0;
}
