/** ::------ TEAM DETAILS ------::
 * Team No: 17
   Name: Manosrija Nasrin (L), Roll: 002111001117
   Name: Spandan Ghatak, Roll: 002111001106
   Name: Anirban Dey, Roll: 002111001108
   Name: Saptarshi Bhattacharya, Roll: 002111001113
 *
 * Date: 29-08-2023
 */

/** ::------ ASSIGNMENT DETAILS ------::
 * Assignment 5: Avoiding DEADLOCK using Thread Programming
 *
 * Problem Definition:
   The objective of this assignment is to avoid deadlock. For this purpose define two global 
   variables (Total_1 and Total_2) and initialize both of them to 100000. You should also have 
   two mutexes to protect these two global variables. You need to create three threads also (Th1, 
   Th2 and Th3). 
   
   The function of thread Th1 is to generate a random quantity (not more than 10) and subtract 
   that quantity from Total_2 and add that quantity to the Total_1. Likewise, The function of 
   thread Th2 is to generate a random quantity (not more than 10) and subtract that quantity 
   from Total_1 and add that quantity to the Total_2. While manipulating the Totals, the Th1 and 
   Th2 should lock both the mutex and then unlock it after changing the Totals.
   
   The function of the thread Th3 is to keep displaying the individual Totals and Grand Total 
   (sum of Total_1 and Total_2). Make sure the displayed values are consistent.
   
   Note that this program should run forever.
   
   The order of locking and unlocking the Mutex is very important, because that’s what avoids a 
   Deadlock or creates one. Once you correctly identify the order for avoiding Deadlock, you 
   should upload the program. Also, include that information (as a comment in your source file) 
   regarding the order for creating Deadlock.
   
   Make sure there are enough printf in your program so that it can be clearly understood that there is no Deadlock.

 *
 * ::------ INPUT DESCRIPTION ------::
   This program does not take any input.
 *
 * ::------ OUTPUT DESCRIPTION ------::
   The program creates three threads, both of which try to modify the values of two global
   variables Total_1 and Total_2. The threads acquire locks on two mutex objects and enter
   a deadlock condition where both threads are waiting for the other thread to relinquish its
   lock on one of the mutexes.

*/

/** ::------ COMPILATION COMMAND ------::
    gcc 17_5.c -o 17_5 -Wall -lpthread
 *
 * ::------ EXECUTION SEQUENCE ------::
 * In a terminal, run:  ./17_5
   Press Ctrl+C to exit.
 */

/**
 * Sample Input: ./17_5
   Sample Output: (No Deadlock)
    Thread 1 is trying to acquire a lock on  mutex for Total_1
	Thread 1 has LOCKED mutex for Total_1
	Thread 1 is trying to acquire a lock on mutex for Total_2
	Thread 1 has LOCKED mutex for Total_2
	Thread 1 UNLOCKED the mutex for Total_2
	Thread 1 UNLOCKED the mutex for Total_1
	Thread 3 is trying to acquire a lock on  mutex for Total_1
    Thread 3 has LOCKED mutex for Total_1
    Thread 3 is trying to acquire a lock on mutex for Total_2
    Thread 3 has LOCKED mutex for Total_2
    =====================================================
    Thread 3 display:
    Thread 1 UNLOCKED the mutex for Total_1
    Thread 1 is trying to acquire a lock on  mutex for Total_1
    Total_1 = 100116, Total_2 = 99884
    Grand Total = 200000
    =====================================================
    Thread 3 UNLOCKED the mutex for Total_2
    Thread 3 UNLOCKED the mutex for Total_1
    Thread 2 is trying to acquire a lock on  mutex for Total_1
    Thread 2 has LOCKED mutex for Total_1
    Thread 2 is trying to acquire a lock on mutex for Total_2
    Thread 2 has LOCKED mutex for Total_2
    Thread 2 UNLOCKED the mutex for Total_2
    Thread 2 UNLOCKED the mutex for Total_1

 */

/* 
   The order in which the mutex objects are locked is same for all three threads in order to avoid deadlock:

   For No Deadlock:
   Thread 1: the lock order is mutex1, mutex2
   Thread 1: the unlock order is mutex2, mutex1
   Thread 2: the lock order is mutex1, mutex2
   Thread 2: the unlock order is mutex2, mutex1
   Thread 3: the lock order is mutex1, mutex2
   Thread 3: the unlock order is mutex2, mutex1
*/

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 10
#define VALUE 100000

pthread_t thread1, thread2, thread3; /* threads */

/* mutex objects */
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

/* global variables */
int Total_1 = VALUE, Total_2 = VALUE;

/* wait function */
void wait_for_a_while() {
    long int i;
    while(i++ < 0xfffffffffff);
}

/* function for thread 1 */
void *thread1_start_function(void *arg)
{
    int random_num;

    while(1) {
        /* generate a random value */
        random_num = rand() % (MAX + 1);

        /* lock mutex object 1 */
        printf("Thread 1 is trying to acquire a lock on  mutex for Total_1\n");
        pthread_mutex_lock(&lock1);
        printf("Thread 1 has LOCKED mutex for Total_1\n");

        /* lock mutex object 2 */
        printf("Thread 1 is trying to acquire a lock on mutex for Total_2\n");
        pthread_mutex_lock(&lock2);
        printf("Thread 1 has LOCKED mutex for Total_2\n");

        Total_2 -= random_num;
        Total_1 += random_num;

        /* unlock mutex object 2 */
        pthread_mutex_unlock(&lock2);
        printf("Thread 1 UNLOCKED the mutex for Total_2\n");

        /* unlock mutex object 1 */
        pthread_mutex_unlock(&lock1);
        printf("Thread 1 UNLOCKED the mutex for Total_1\n");

	    wait_for_a_while();
    }

    /* unreachable code */
    return NULL;
}

/* function for thread 2 */
void *thread2_start_function(void *arg)
{
    int random_num;

    while (1) {
        /* generate a random value */
        random_num = rand() % (MAX + 1);

        /* lock mutex object 1 */
        printf("Thread 2 is trying to acquire a lock on  mutex for Total_1\n");
        pthread_mutex_lock(&lock1);
        printf("Thread 2 has LOCKED mutex for Total_1\n");

        /* lock mutex object 2 */
        printf("Thread 2 is trying to acquire a lock on mutex for Total_2\n");
        pthread_mutex_lock(&lock2);
        printf("Thread 2 has LOCKED mutex for Total_2\n");

        Total_1 -= random_num;
        Total_2 += random_num;

        /* unlock mutex object 2 */
        pthread_mutex_unlock(&lock2);
        printf("Thread 2 UNLOCKED the mutex for Total_2\n");

        /* unlock mutex object 1 */
        pthread_mutex_unlock(&lock1);
        printf("Thread 2 UNLOCKED the mutex for Total_1\n");

	    wait_for_a_while();
    }
    
    /* unreachable code */
    return NULL;
}

/* function to display both totals and grand total */
void* thread3_display_function() {
    while(1) {
        /* lock mutex object 1 */
        printf("Thread 3 is trying to acquire a lock on  mutex for Total_1\n");
        pthread_mutex_lock(&lock1);
        printf("Thread 3 has LOCKED mutex for Total_1\n");

        /* lock mutex object 2 */
        printf("Thread 3 is trying to acquire a lock on mutex for Total_2\n");
        pthread_mutex_lock(&lock2);
        printf("Thread 3 has LOCKED mutex for Total_2\n");
        
        /* display */
	    printf("=====================================================\n");
        printf("Thread 3 display:\n");
        printf("Total_1 = %d, Total_2 = %d\n", Total_1, Total_2);
        printf("Grand Total = %ld\n", (long)(Total_1 + Total_2));
	    printf("=====================================================\n");
        
        /* unlock mutex object 2 */
        pthread_mutex_unlock(&lock2);
        printf("Thread 3 UNLOCKED the mutex for Total_2\n");

        /* unlock mutex object 1 */
        pthread_mutex_unlock(&lock1);
        printf("Thread 3 UNLOCKED the mutex for Total_1\n");

	    wait_for_a_while();
    } 
    /* unreachable code */
    return NULL;
}

/* signal handler for  SIGINT */
void sighandler(int signum) {
    printf("Cleaning up...\n");
    /* destroy the mutex objects */
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    /* exit */
    exit(EXIT_SUCCESS);
}

int main(void)
{
    int error;
    
    srand(time(NULL));
    
    /* create sighandler for SIGINT */
    if (signal(SIGINT, sighandler) == SIG_ERR) {
        perror("Failed to create signal handler for SIGINT");
    }

    /* initialize the mutex objects */
    if (pthread_mutex_init(&lock1, NULL) != 0 || pthread_mutex_init(&lock2, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        exit(EXIT_FAILURE);
    }

    /* create the threads */
    if ((error = pthread_create(&thread1, NULL, &thread1_start_function, NULL)) != 0)
    {
        printf("\nThread 1 cannot be created: [%s]", strerror(error));
    }
    else if ((error = pthread_create(&thread2, NULL, &thread2_start_function, NULL)) != 0)
    {
        printf("\nThread 2 cannot be created: [%s]", strerror(error));
    } else if ((error = pthread_create(&thread3, NULL, &thread3_display_function, NULL)) != 0)
    {
        printf("\nThread 3 cannot be created: [%s]", strerror(error));
    } 
    
    /* ---- unreachable code ---- */
    /* wait for the threads to finish execution */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    /* destroy the mutex objects */
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);

    return 0;
}
