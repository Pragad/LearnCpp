#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
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
// PROBLEM 3. Another example of Mutex, Unique_lock
// http://baptiste-wicht.com/posts/2012/03/cp11-concurrency-tutorial-part-2-protect-shared-data.html
// -----------------------------------------------------------------------------------------
class PersonCountNoMtx
{
public:
    int _value;

    PersonCountNoMtx() : _value(0) { }

    void increment()
    {
        _value++;
    }
};

class PersonCountWithMtx
{
public:
    std::mutex mtx;
    int _value;

    PersonCountWithMtx() : _value(0) { }

    void increment()
    {
        mtx.lock();
        _value++; // IMP: If Exception happens and we crash then the lock does not get released
        mtx.unlock();
    }
};

class PersonCountUniqLock
{
public:
    std::mutex mtx;
    int _value;

    PersonCountUniqLock() : _value(0) { }

    void increment()
    {
        unique_lock<mutex> uniqLock(mtx);   // Unlock gets called when we go out of scope
        _value++;
    }
};

// -----------------------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------------------
int main()
{
    // Example 1
    {
        cout << endl << "Problem 1" << endl;
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
        cout << endl << "Problem 2" << endl;
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

    // PROBLEM 3. Another example of Mutex, Unique_lock
    {
        cout << endl << "Problem 3" << endl;
        PersonCountNoMtx ob1;
        vector<thread> vecThreads1;
        for (uint32_t i = 0; i < 3; i++)
        {
            // Different ways to create a thread for a Class's member function
            //thread th1(&PersonCountNoMtx::increment, PersonCountNoMtx());
            //thread th2(&PersonCountNoMtx::increment, &ob1);
            vecThreads1.push_back(thread(&PersonCountNoMtx::increment, &ob1));

            for (uint32_t j = 0; j < 5; j++)
            {
                ob1.increment();
            }
        }

        for (auto& th : vecThreads1)
        {
            th.join();
        }
        cout << "Thread 1's Value: " << ob1._value << endl;

        PersonCountWithMtx ob2;
        vector<thread> vecThreads2;
        for (uint32_t i = 0; i < 3; i++)
        {
            vecThreads2.push_back(thread(&PersonCountNoMtx::increment, &ob1));
            for (uint32_t j = 0; j < 5; j++)
            {
                ob2.increment();
            }
        }

        for (auto& th : vecThreads2)
        {
            th.join();
        }
        cout << "Thread 2's Value: " << ob2._value << endl;


        PersonCountUniqLock ob3;
        vector<thread> vecThreads3;
        for (uint32_t i = 0; i < 3; i++)
        {
            vecThreads3.push_back(thread(&PersonCountNoMtx::increment, &ob1));
            for (uint32_t j = 0; j < 5; j++)
            {
                ob3.increment();
            }
        }

        for (auto& th : vecThreads3)
        {
            th.join();
        }
        cout << "Thread 3's Value: " << ob3._value << endl;

    }

    cout << endl;
    return 0;
}
