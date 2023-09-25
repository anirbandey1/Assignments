/** ::------ TEAM DETAILS ------::
 * Team No: 17
   Name: Manosrija Nasrin (L), Roll: 002111001117
   Name: Spandan Ghatak, Roll: 002111001106
   Name: Anirban Dey, Roll: 002111001108
   Name: Saptarshi Bhattacharya, Roll: 002111001113
 *
 * Date: 13-09-2023
 */

/** ::------ ASSIGNMENT DETAILS ------::
 * Assignment 7:  Thread, Synchronizations & Shared Memory
 *
 * Problem Definition:
   Consider a main process which creates three threads Th1, Th2, and Th3. The main
   process also creates two random quantities (X, Y), both less than 10. These two
   values will be placed by the main process in the shared memory (One variant of IPC
   Primitive)  that is accessible by all the three threads Th1, Th2 and Th3. The
   shared memory will be created by the main process also.

   For each pair of values (X,Y), it is required that some computations will be done
   by various threads. The thread Th1 will compute A (X*Y) and the thread Th2 will
   compute B (X*Y)/2). Similarly,  Th3 computes C (X+Y), Th2 again computes D ((X*Y)/(X+Y)),
   and finally Th1 computes E ((X+Y)(X-Y)). All these values are kept in the shared memory
   in a tabular fashion as shown below.

   The number of (X,Y) pairs will be taken as an argument from the CLI. It is the
   responsibility of the main process to populate required numbers of (X,Y)s in the
   shared memory. The program will only exit when all A,B,C etc. are computed for all
   given (X,Y) values. Before exiting, all (X,Y)s, As, Bs etc. should be displayed.

   Whenever, the threads complete one phase of computations (A, B, C, D and E), they will
   go for another pair of (X,Y) values; but they will start all together. This can be
   achieved by proper synchronization.

   Use the proper shell command to display the Shared Memory Status/Info/Statistics and
   attach this sample output as a comment.


 * ::------ INPUT DESCRIPTION ------::
   This program takes one commandline input: N, number of random pairs - a positive integer
   that specifies the number of pairs the threads should generate the data for.
 *
 * ::------ OUTPUT DESCRIPTION ------::
   The main process creates three threads. Based on the given input, N, the main process
   generates N random pairs (X, Y) where X, Y <= 10. The three threads calculate certain values
   for the given pairs and populates a data structure with these calculated values. All the threads
   must complete their respective calculations for a certain pair before moving on to the next
   one.

   Barrier synchronization has been used for this given problem where each thread waits for the
   others to complete before resuming their execution. First, The main process generates a new
   random pair. Then the threads start their calculation for the current pair, and after finishing
   they wait again at the beginning to wait for the main process to generate a new pair. The main
   process waits during this time for threads to complete their execution. Then increments the current
   row number and generates a fresh pair. This process continues for n pairs.
           BARRIER
             ↓
    Pairs    |        A   |   B   |   C   |   D   |   E   |
    (1, 0)   |       0.00 |  0.00 |  1.00 |  0.00 |  1.00 |

   At the end, the entire table is printed by the main process.
 */

/** ::------ COMPILATION COMMAND ------::
    gcc 17_7.c -o 17_7 -Wall -lpthread
 *
 * ::------ EXECUTION SEQUENCE ------::
   Open a Linux terminal and run:   ./17_7 <number_of_pairs>
   The shared memory statistics have been printed in the program itself (using ipcs -m)
   via a system call, and the command has been printed along with the proper team prompt.
 */

/**
 * Sample Input: ./17_7 5
 * Sample Output:
    In the main process. Allocating shared memory...

    <<TEAM17>> $ ipcs -m | head -n 3 && ipcs -m | grep 0x11007203 ;

    ------ Shared Memory Segments --------
    key        shmid      owner      perms      bytes      nattch     status
    0x11007203 6946838    be21117    666        140        1

    Shared memory allocated successfully. Creating threads...
    Threads created successfully. Waiting for them to finish execution...
    All threads have finished execution.

    Thread 1: A = (X * Y)           Thread 1: E = (X + Y)(X - Y)
    Thread 2: B = (X * Y) / 2       Thread 2: D = (X * Y)/(X + Y)
                    Thread 3: C = (X + Y)

    Pairs	 |	  A   |   B   |   C   |   D   |   E   |
    (8, 7)	 | 	56.00 |	28.00 |	15.00 |	 3.73 |	15.00 |
    (3, 10)	 | 	30.00 |	15.00 |	13.00 |	 2.31 |	-1.86 |
    (1, 0)	 | 	 0.00 |	 0.00 |	 1.00 |	 0.00 |	 1.00 |
    (4, 0)	 | 	 0.00 |	 0.00 |	 4.00 |	 0.00 |	 1.00 |
    (7, 5)	 | 	35.00 |	17.50 |	12.00 |	 2.92 |	 6.00 |
 */

/**
 * Output from the ipcs command:
   <<TEAM17>> $ ipcs -m | head -n 3 && ipcs -m | grep 0x11007203 ;

    ------ Shared Memory Segments --------
    key        shmid      owner      perms      bytes      nattch     status
    0x11007203 6946838    be21117    666        140        1
 */

#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXLEN 50
#define MAX_VALUE 10
#define NUM_THREADS 3
#define NUM_VALUES 5

/* custom structure to store the values and the pairs
 - created to allocate shared memory using shmget */
typedef struct shm_17
{
    int pair[2];
    float values[5];
} shm_17;

/* custom structure to pass arguments to threads */
typedef struct thread_args
{
    unsigned int n;
    shm_17 *shm;
} thread_args;

/* global variables */
unsigned int curr = 0;
key_t key_ = 0;
pthread_t thread1, thread2, thread3; /* threads */
pthread_barrier_t barrier;           /* barrier objects */

/* utility function for external error handling */
void die(const char *message, const char *action)
{
    perror(message);
    if (action != NULL)
        fprintf(stderr, "Please %s.\n", action);
    else
        fprintf(stderr, "Please check the error message.\n");
    exit(EXIT_FAILURE);
}

/* utility function: handle SIGINT signal  */
void sighandler(int signum)
{
    char command[MAXLEN], echo[MAXLEN * 2];
    if (key_ != 0)
    {
        /* remove thse ipc shm segment */
        if (sprintf(command, "ipcrm -M %#x", key_) == 0)
            die("sprintf", NULL);
        /* prepare the corresponding echo command */
        else if (sprintf(echo, "echo \"%s %s\"", "\x1b[32;1m<<TEAM17>> $\x1b[0m", command) == 0)
            die("sprintf", NULL);
        /* echo and exceute */
        else if (system(echo) != 0 || system(command) != 0)
            die("ipcrm", "ensure that the process with given key exists");
        exit(EXIT_FAILURE);
    }
}

/* utility function: contains a very large loop */
void wait_for_a_while()
{
    unsigned int i;
    for (i = 0; i < 0xfffff; i++)
        ;
}

/* function for thread 1 */
void *thread1_function(void *args)
{
    float X, Y, A, E;
    thread_args *th_arg = (thread_args *)args;
    unsigned int n = th_arg->n;
    shm_17 *shared_memory = th_arg->shm;

    while (curr < n)
    {
        /* wait for the main process to generate the current random pair */
        pthread_barrier_wait(&barrier); /* barrier synchronization */

        /* calculate the required values */
        X = shared_memory[curr].pair[0], Y = shared_memory[curr].pair[1];
        A = X * Y, E = (X + Y) / (X - Y);
        shared_memory[curr].values[0] = A, shared_memory[curr].values[4] = E;
    }

    return NULL;
}

/* function for thread 2 */
void *thread2_function(void *args)
{
    float X, Y, B, D;
    thread_args *th_arg = (thread_args *)args;
    unsigned int n = th_arg->n;
    shm_17 *shared_memory = th_arg->shm;

    while (curr < n)
    {
        /* wait for the main process to generate the current random pair */
        pthread_barrier_wait(&barrier); /* barrier synchronization */

        /* calculate the required values */
        X = shared_memory[curr].pair[0], Y = shared_memory[curr].pair[1];
        B = (X * Y) / 2, D = (X * Y) / (X + Y);
        shared_memory[curr].values[1] = B, shared_memory[curr].values[3] = D;
    }

    return NULL;
}

/* function for thread 3 */
void *thread3_function(void *args)
{
    float X, Y, C;
    thread_args *th_arg = (thread_args *)args;
    unsigned int n = th_arg->n;
    shm_17 *shared_memory = th_arg->shm;

    while (curr < n)
    {
        /* wait for the main process to generate the current random pair */
        pthread_barrier_wait(&barrier); /* barrier synchronization */

        /* calculate the required values */
        X = shared_memory[curr].pair[0], Y = shared_memory[curr].pair[1];
        C = X + Y;
        shared_memory[curr].values[2] = C;
    }

    return NULL;
}

/* display the pairs and the values in a tabular format */
void print_table(shm_17 *shared_memory, unsigned int n)
{
    size_t i, j;

    printf("Pairs\t |\t  A   |   B   |   C   |   D   |   E   |\n");

    for (i = 1; i <= n; i++)
    {
        if (shared_memory[i].pair[0] == 10 && shared_memory[i].pair[1] == 10)
        {
            printf("(%d, %d) | \t", shared_memory[i].pair[0], shared_memory[i].pair[1]);
            for (j = 0; j < NUM_VALUES; j++)
            {
                if (j == 0)
                    printf("\x1b[1D%5.2f | ", shared_memory[i].values[j]);
                else if (j < NUM_VALUES - 1)
                    printf("%5.2f |\t", shared_memory[i].values[j]);
                else
                    printf("%5.2f |\n", shared_memory[i].values[j]);
            }
        }
        else
        {
            printf("(%d, %d)\t | \t", shared_memory[i].pair[0], shared_memory[i].pair[1]);
            for (j = 0; j < NUM_VALUES; j++)
            {
                if (j < NUM_VALUES - 1)
                    printf("%5.2f |\t", shared_memory[i].values[j]);
                else
                    printf("%5.2f |\n", shared_memory[i].values[j]);
            }
        }
    }
}

/* print the values associated with the variables */
void print_value_dict()
{
    printf("Thread 1: A = (X * Y)\t\t"
           "Thread 1: E = (X + Y)(X - Y)\n"
           "Thread 2: B = (X * Y) / 2\t"
           "Thread 2: D = (X * Y)/(X + Y)\n"
           "\t\tThread 3: C = (X + Y)\n\n");
}

int main(int argc, char *argv[])
{
    int n, error, assign_no = 17, shmid;
    char *shmfile = "/tmp/shm_17", command[MAXLEN], echo[MAXLEN * 2];
    char **endptr = malloc(sizeof *endptr);
    key_t key;
    thread_args *th_args = NULL; /* thread argument */

    /* check if commandline arguments have been supplied */
    if (argc < 2)
    {
        printf("Not enough commandline arguments!\n");
        printf("Usage: %s number_of_pairs\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));               /* seed the random number generator */
    n = strtol(argv[1], endptr, 10); /* parse the commandline argument */

    if (strcmp(argv[1], *endptr) == 0)
    {
        errno = EINVAL;
        die("commandline argument parsing", "enter a positive integer as the input");
    }
    else if (n < 0) /* check for validity */
    {
        printf("Number of pairs cannot be negative!\n");
        exit(EXIT_FAILURE);
    }
    else if (signal(SIGINT, sighandler) < 0) /* set the signal handler */
        die("signal", "remove the IPC Shared memory segment with ipcrm command: ipcrm -m <shmid> OR ipcrm -M <key>");

    th_args = malloc(sizeof *th_args);
    th_args->n = n;

    printf("In the main process. Allocating shared memory...\n\n");

    /* create the shmfile if it does not already exist */
    if (sprintf(command, "touch %s", shmfile) == 0 || system(command) != 0)
        die("touch", NULL);
    /* generate an IPC key using ftok */
    else if ((key_ = key = ftok(shmfile, assign_no)) == -1)
        die("ftok", "check if file exists");
    /* get the shared memory identifier for key, size = n elements */
    else if ((shmid = shmget(key, (n + 1) * sizeof *th_args->shm, 0666 | IPC_CREAT)) == -1)
        die("shmget", "make sure that there is no existing SHM segment with same ID but different size");
    /* attach an address to the shared memory */
    else if ((th_args->shm = (shm_17 *)shmat(shmid, NULL, 0)) == (void *)-1)
        die("shmat", NULL);
    /* prepare the command that is to be executed */
    else if (sprintf(command, "ipcs -m | head -n 3 && ipcs -m | grep %#x ;", key) == 0)
        die("sprintf", NULL);
    /* prepare the corresponding echo command */
    else if (sprintf(echo, "echo \"%s %s\"", "\x1b[32;1m<<TEAM17>> $\x1b[0m", command) == 0)
        die("sprintf", NULL);
    /* echo and exceute */
    else if (system(echo) == -1 || system(command) == -1)
        die("ipcs system call", NULL);
    /* initialize the barrier object */
    else if (pthread_barrier_init(&barrier, NULL, NUM_THREADS + 1) != 0)
        die("barrier_init", NULL);

    printf("\nShared memory allocated successfully. Creating threads...\n");

    /* create the threads */
    if ((error = pthread_create(&thread1, NULL, &thread1_function, (void *)th_args)) != 0)
        printf("\nThread 1 cannot be created: [%s]", strerror(error));
    else if ((error = pthread_create(&thread2, NULL, &thread2_function, (void *)th_args)) != 0)
        printf("\nThread 2 cannot be created: [%s]", strerror(error));
    else if ((error = pthread_create(&thread3, NULL, &thread3_function, (void *)th_args)) != 0)
        printf("\nThread 3 cannot be created: [%s]", strerror(error));

    printf("Threads created successfully. Waiting for them to finish execution...\n");

    /* for n elements */
    while (curr < n)
    {
        curr += 1; /* increment the current row number */

        /* generate a new random pair */
        th_args->shm[curr].pair[0] = rand() % (MAX_VALUE + 1);
        th_args->shm[curr].pair[1] = rand() % (MAX_VALUE + 1);

        /* barrier synchronization - wait for all threads to finish execution */
        pthread_barrier_wait(&barrier);

        /* wait for some time for threads to finish execution for current
        row and return at barrier */
        wait_for_a_while();
    }

    /* wait for the threads to finish execution */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("All threads have finished execution.\n\n");

    /* destroy the barrier object */
    pthread_barrier_destroy(&barrier);

    print_value_dict();

    /* display all pairs and values */
    print_table(th_args->shm, n);

    /* deallocate resources */
    if (shmdt(th_args->shm) != 0)
        die("shmdt", NULL);
    else if (shmctl(shmid, IPC_RMID, NULL) == -1)
        die("shmctl IPC_RMID", "check whether the shared memory segment with the aforementioned id exists");
    else if (remove(shmfile) != 0)
        die("remove", "check if file exists");

    free(endptr);
    free(th_args);

    return 0;
}
