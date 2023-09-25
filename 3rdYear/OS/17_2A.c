/**
 * ::------ TEAM DETAILS ------::
   Team No: 17
   Name: Manosrija Nasrin (L), Roll: 002111001117
   Name: Spandan Ghatak, Roll: 002111001106
   Name: Anirban Dey, Roll: 002111001108
   Name: Saptarshi Bhattacharya, Roll: 002111001113
 *
 * Date: 09-08-2023
 */

/**
 * ::------ ASSIGNMENT DETAILS ------::
 * Assignment 2A: SIGNAL Handling
 *
 * Problem Definition:
   Catch the signal 'SIGINT' and display "Ha Ha, Not Stopping". Use 'signal'
   system call. Always use "perror" to check the return status of a library/system
   call.
 *
 *
 * ::------ INPUT DESCRIPTION ------::
   This program does not take any input.
 *
 * ::------ OUTPUT DESCRIPTION ------::
 * The program demonstrates signal handling of SIGINT signal. A while loop
   starts for some predefined number of seconds and any SIGINT signal sent
   to the process during that time gets passed to the sighandler function
   to be handled, and the appropriate message "Ha Ha, Not Stopping" is displayed.
 */

/**
 * ::------ COMPILATION COMMAND ------::
    gcc 17_2A.c -o 17_2A -Wall
 *
 * ::------ EXECUTION SEQUENCE ------::
    ./17_2A
 */
/**
 * Sample Input: ./17_2A
 * Sample Output:
    Process started. Wait for 5 seconds...
    ^CHa Ha, Not Stopping
    ^CHa Ha, Not Stopping
    ^CHa Ha, Not Stopping
    ^CHa Ha, Not Stopping
    ^CHa Ha, Not Stopping
    ^CHa Ha, Not Stopping


 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT_VAL_SECS 5

void die(const char *msg)
{
    perror(msg);
    exit(1);
}

void sighandler(int signum)
{
    /* do nothing on receiving SIGINT signal */
    printf("\x1b[31mHa Ha, Not Stopping\x1b[0m\n");
}

int main(int argc, char **argv)
{
    int msec = 0, trigger = TIMEOUT_VAL_SECS * 1000;
    clock_t before = clock(); /* get t */

    if (before < 0)
        die("could not get system time");

    if (signal(SIGINT, sighandler) == SIG_ERR)
        die("could not set handler for SIGINT"); /* handle error and exit */

    printf("Process started. Wait for %d seconds...\n", TIMEOUT_VAL_SECS);

    do
    {
        clock_t difference = clock() - before;

        if (difference + before < 0)
            die("could not get system time");

        msec = difference * 1000 / CLOCKS_PER_SEC; /* CLOCKS_PER_SEC number of clock ticks per second measured by the clock function */
    } while (msec < trigger);

    return 0;
}
