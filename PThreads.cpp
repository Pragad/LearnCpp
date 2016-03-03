#include <iostream>
#include <pthread.h>
using namespace std;

// http://stackoverflow.com/questions/1640423/error-cast-from-void-to-int-loses-precision
#include <stdint.h>

#define NUM 5

void * sampThread(void *tid)
{
    // IMP: Can't cast to "void* arg" to "(int)arg"
    cout << "Thread: " << (intptr_t)tid << endl;

    // This say to terminate the current thread
    pthread_exit(NULL);
}

pthread_mutex_t myMutex;
void * sampThreadMutex(void *tid)
{
    pthread_mutex_lock(&myMutex);
    // IMP: Can't cast to "void* arg" to "(int)arg"
    cout << "Mutex: " << (intptr_t)tid << endl;
    pthread_mutex_unlock(&myMutex);

    // This say to terminate the current thread
    pthread_exit(NULL);
}

int main()
{
    pthread_t my_thread[NUM];

    for(int i = 0; i < NUM; i++)
    {
        // IMP: Casting to (void*) throws "warning: cast to pointer from integer of different size"
        int ret =  pthread_create(&my_thread[i], NULL, &sampThread, (void*)(intptr_t)i);

        if(ret != 0) {
            cout << "Error creating thread" << endl;
            exit(EXIT_FAILURE);
        }
    }

    pthread_t my_thread_mut[NUM];
    for(int i = 0; i < NUM; i++)
    {
        pthread_create(&my_thread_mut[i], NULL, &sampThreadMutex, (void*)(intptr_t)i);
    }

    for(int i = 0; i < NUM; i++)
    {
        pthread_join(my_thread_mut[i], 0);
    }

    // If the below line is commented out, all threads might not FINISH
    // IMP: http://stackoverflow.com/questions/20824229/when-to-use-pthread-exit-and-when-to-use-pthread-join-in-linux
    pthread_exit(NULL);

    return 0;
}
