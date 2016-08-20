#include <iostream>
#include <pthread.h>
using namespace std;

#include <stdint.h> // To include the "uintptr_t
#include <unistd.h> // To include sleep

int counter = 0;
uint32_t sumOfNumbers = 0;

pthread_mutex_t mtx;
void* increment(void* arg)
{
    // Removing the lock does not guarentee the order. Gets printed randomly
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mtx);
        counter++;
        usleep(5);
        cout << endl << "i: " << i << "; Counter Value: " << counter << endl;
        pthread_mutex_unlock(&mtx);
    }
}

pthread_mutex_t mtxNum;
void* sumNumbers(void* tid)
{
    // Each threads gets 10 numbers
    // VERY IMP: Mutex should be above the for loop
    pthread_mutex_lock(&mtxNum);
    for (int i = (intptr_t)tid * 10; i < ((intptr_t)tid * 10 )+10; i++)
    {
        cout << "i : " << i << endl;
        sumOfNumbers += i;
        usleep(5);
    }
    pthread_mutex_unlock(&mtxNum);
}

int main()
{
    // Case 1: Increment a common counter using a Mutex variable
    pthread_t th[3];

    // Initialize the mutex
    pthread_mutex_init(&mtx, 0);

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&th[i], NULL, &increment, (void*)(intptr_t)i);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(th[i], 0);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mtxNum);
    cout << "Counter: " << counter << endl;

    // Case 2: Find Sum of Numbers by dedicating numbers to each thread
    pthread_t thNum[3];

    pthread_mutex_init(&mtxNum, 0);
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&thNum[i], 0, &sumNumbers, (void *)(intptr_t)i);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(thNum[i], 0);
    }
    pthread_mutex_destroy(&mtxNum);
    cout << "Sum: " << sumOfNumbers << endl;

    pthread_exit(0);
    return 0;
}
