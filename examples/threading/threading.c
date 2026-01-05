#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* threadParam)
{

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    //struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    
    struct threadData* threadFuncArgs = (struct threadData*) threadParam;

    usleep(threadFuncArgs->sWaitToObtainMs * 1000);

    int ret = pthread_mutex_lock(threadFuncArgs->sMutex);
    if (ret != 0)
    {
        ERROR_LOG("Mutex Lock Failed: %d", ret);
        threadFuncArgs->sThreadCompleteSuccess = false;
    }
    else
        usleep(threadFuncArgs->sWaitToReleaseMs * 1000);

    ret = pthread_mutex_unlock(threadFuncArgs->sMutex);
    if (ret != 0)
    {
        ERROR_LOG("Mutex Unlock Failed: %d\n", ret);
        threadFuncArgs->sThreadCompleteSuccess = false;
    }
    else
        threadFuncArgs->sThreadCompleteSuccess = true;


    return threadParam;
}


bool startThreadObtainingMutex(pthread_t *thread, pthread_mutex_t *mutex,int waitToObtainMs, int waitToReleaseMs)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */

    struct threadData* threadParam = (struct threadData*)malloc(sizeof(struct threadData));

    threadParam->sMutex = mutex;
    threadParam->sWaitToObtainMs = wait_to_obtain_ms;
    threadParam->sWaitToReleaseMs = wait_to_release_ms;

    if ret = pthread_create(thread, NULL, threadFunc, threadParam);
    if (ret != 0)
        ERROR_LOG("Thread Creation Failed: %d\n", ret);

    return true;
}

