/** ::------ TEAM DETAILS ------::
 * Team No: 17
   Name: Manosrija Nasrin (L), Roll: 002111001117
   Name: Spandan Ghatak, Roll: 002111001106
   Name: Anirban Dey, Roll: 002111001108
   Name: Saptarshi Bhattacharya, Roll: 002111001113
 *
 * Date: 23-08-2023
 */

/** ::------ ASSIGNMENT DETAILS ------::
 * Assignment 4: mmap and page fault
 *
 * Problem Definition:
   Objective of this programming assignment is to use mmap() call and observe page-fault using the 'sar' command.

   A big file (about 8GB) should be created using the 'fallocate' command. This big file should be written with a
   single integer value (say X) at a specific offset (say F). Both the integer value and the offset should be
   generated using a random function. Please do remember this random function should generate a quantity anywhere
   between 0 and 8G.

   The above big file should also be mapped in the virtual address space using mmap() call. Once it is mapped, the
   data should be read from the same specific offset (F). Now, if the data read is X`; then verify that X and X`
   are the same. In case of verification failure, an error message is to be printed. Note that, the offset value F
   can be anywhere between 0 and 8G.

   This sequence of writing and reading data to/from a specific offset and also verification should be put in a while
   loop to go forever.

   In another terminal execute the command 'sar -B 1 1000' to observe for the page fault. This command should be
   started before the above program is put under execution. So, one can observe that the page faults are increasing,
   once the above program starts executing.

   The output of the program and the 'sar' command should be pasted as a comment at the beginning of the program file
   as indicated by the guidelines.
 *
 * ::------ INPUT DESCRIPTION ------::
   This program does not take any input.
 *
 * ::------ OUTPUT DESCRIPTION ------::
   The program checks values read and written to a given offset in a file. If the values are the same, the program
   keeps running, else it stops and prints and an error message. Press Ctrl+C/Cmd+C to stop.
 */

/** ::------ COMPILATION COMMAND ------::
    gcc 17_4.c -o 17_4 -Wall
 *
 * ::------ EXECUTION SEQUENCE ------::
 * In a terminal, run the command:  sar -B 1
   This will generate system activity information (paging statistics) every second.
   Let it run for a few seconds, and observe the page fault statistics under the labels:
   pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s.
   Now open a Linux terminal and run:   ./17_4
   Let the program run for a few seconds and observe the page fault statistics.
   For both terminals, press Ctrl+C to exit.
 */

/**
 * Sample Input: ./17_4
 * Sample Output:
    Setting up the files... Finished. The read/write process is about to start.

    Wrote -65 at offset 0x1ad737d7a
    Read -65 at offset 0x1ad737d7a

    Wrote -116 at offset 0xc2225e33
    Read -116 at offset 0xc2225e33

    Wrote 40 at offset 0x1ad7cb5b8
    Read 40 at offset 0x1ad7cb5b8

    Wrote 6 at offset 0x8cb5bf3a
    Read 6 at offset 0x8cb5bf3a

    Wrote -96 at offset 0x1c9f6b4ce
    Read -96 at offset 0x1c9f6b4ce
    ...

    Wrote -59 at offset 0x3e752b72
    Read -59 at offset 0x3e752b72

    ^C
    Cleaning up... Please wait.
    Unmapped memory and removed large file.
 */

/**
 * Output from the sar command:
 * <<TEAM17>> $ sar -B 1
Linux 5.15.0-79-generic (be21117) 	25/08/23 	_x86_64_	(8 CPU)

10:13:12 PM  pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
10:13:13 PM      0.00    180.00    129.00      0.00   9190.00      0.00      0.00      0.00      0.00
10:13:14 PM      0.00      0.00      7.00      0.00    365.00      0.00      0.00      0.00      0.00
10:13:15 PM      0.00     80.00      1.00      0.00     26.00      0.00      0.00      0.00      0.00
10:13:16 PM      0.00      0.00      0.00      0.00  10259.00      0.00      0.00      0.00      0.00
10:13:17 PM      0.00      0.00      1.00      0.00     14.00      0.00      0.00      0.00      0.00
10:13:18 PM      0.00      0.00      8.00      0.00     37.00      0.00      0.00      0.00      0.00
10:13:19 PM      0.00      0.00      2.00      0.00     37.00      0.00      0.00      0.00      0.00
10:13:20 PM      0.00      0.00      0.00      0.00     17.00      0.00      0.00      0.00      0.00
10:13:21 PM      0.00      0.00      0.00      0.00     24.00      0.00      0.00      0.00      0.00
10:13:22 PM      0.00      0.00      2.00      0.00     43.00      0.00      0.00      0.00      0.00
10:13:23 PM      0.00    228.00  37573.00      0.00    915.00      0.00      0.00      0.00      0.00
10:13:24 PM      0.00 356640.00 100716.00      0.00   8881.00      0.00      0.00      0.00      0.00
10:13:25 PM      0.00 149732.00  33037.00      0.00   2430.00      0.00      0.00      0.00      0.00
10:13:26 PM      0.00 140388.00  30207.00      0.00   2731.00      0.00      0.00      0.00      0.00
10:13:27 PM      0.00 145992.00  30540.00      0.00   2246.00      0.00      0.00      0.00      0.00
10:13:28 PM      0.00 158064.00  29753.00      0.00   2960.00      0.00      0.00      0.00      0.00
10:13:29 PM      0.00 102960.00  14079.00      0.00 288982.00      0.00      0.00      0.00      0.00
10:13:30 PM      0.00     12.00    127.00      0.00   1319.00      0.00      0.00      0.00      0.00
10:13:31 PM      0.00     36.00      1.00      0.00    129.00      0.00      0.00      0.00      0.00
10:13:32 PM      0.00      0.00      0.00      0.00     12.00      0.00      0.00      0.00      0.00
10:13:33 PM      0.00     10.00      0.00      0.00     14.00      0.00      0.00      0.00      0.00
^C

Average:         0.00  55490.11  14535.95      0.00  17400.26      0.00      0.00      0.00      0.00
 *
 */

#define _GNU_SOURCE /* for fallocate() */

#include <fcntl.h>    /* for fallocate() and O_RDWR */
#include <signal.h>   /* for signal() */
#include <stdlib.h>   /* for exit(), rand(), srand() */
#include <stdio.h>    /* for printf() */
#include <sys/mman.h> /* for mmap() */
#include <sys/types.h>
#include <time.h>   /* for time() */
#include <unistd.h> /* for open(), close(), lseek() */

#define FILENAME "/tmp/lfile.txt"
#define FILE_SIZE_ 8LL * 1024 * 1024 * 1024

char *file_map_ = NULL; /* defined globally for cleanup() to access */

/* utility function that performs cleanup tasks */
void cleanup()
{
    fprintf(stderr, "\nCleaning up... Please wait.\n");
    /* unmap virtual memory */
    if (file_map_ != NULL && munmap(file_map_, FILE_SIZE_) != 0)
        perror("munmap failed");
    /* remove large file */
    else if (remove(FILENAME) != 0)
        perror("remove failed");
    else
        fprintf(stderr, "Unmapped memory and removed large file.\n");
}

/* signal handler that handles SIGINT -
    when the user wants to stop the infinite loop */
void sighandler(int signum)
{
    cleanup(); /* perform cleanup tasks */
    exit(EXIT_SUCCESS);
}

/* external error handling */
void die(const char *message, const char *action)
{
    perror(message);
    if (action != NULL)
        fprintf(stderr, "Please %s.\n", action);
    else
        fprintf(stderr, "Please check the error message.\n");
    cleanup();
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int file_fd;
    int LOW = 0, HIGH = 1024;
    /* MAX_OFFSET indicates the maximum offset that a char can be written to */
    unsigned long long int FILE_SIZE = FILE_SIZE_,
                           MAX_OFFSET = FILE_SIZE_ - sizeof(char);
    off64_t offset;
    char *file_map;
    char X, X_prime;
    char command[100];

    /* seed the random number generator */
    srand(time(NULL));

    printf("Setting up the files... ");

    /* set the SIGINT signal to be handled by the cleanup function */
    if (signal(SIGINT, sighandler) == SIG_ERR)
    {
        perror("could not set signal handler properly");
        /* please ensure you remove the large file from your /tmp/
        directory if you stop the program using Ctrl+C */
    }
    /* create the file if it does not exist */
    else if (sprintf(command, "touch %s", FILENAME) == 0 || system(command) != 0)
        die("touch command failed", NULL);
    /* open the large the file */
    else if ((file_fd = open(FILENAME, O_RDWR)) < 0)
        die("open failed", "ensure that you have proper access for the file "
                           "and it is not opened by other processes");
    /* allocate 8GB to the large file */
    else if (fallocate(file_fd, 0, 0, FILE_SIZE) != 0)
    {
        perror("fallocate failed");
        fprintf(stderr, "Trying ftruncate... ");
        /* try ftruncate if fallocate fails/is not available */
        if (ftruncate64(file_fd, FILE_SIZE) != 0)
            die("ftruncate failed", "try in a Linux environment");
        else
            fprintf(stderr, "file allocated using ftruncate.\n");
    }
    /* map the file to virtual memory */
    else if ((file_map = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, file_fd, 0)) == MAP_FAILED)
    {
        close(file_fd);
        die("mmap failed", "ensure you have sufficient resources and proper access");
    }

    /* set the global file_map_ pointer to the mmap result
    so that the cleanup function can manipulate it */
    file_map_ = file_map;

    printf("Finished. The read/write process is about to start.\n\n");

    /* continue forever */
    while (1)
    {
        offset = (rand() * rand()) % (MAX_OFFSET + 1); /* generate 64-bit offset randomly */
        X = LOW + rand() % (HIGH + 1);                 /* generate the random number */

        /* reposition the write file offset */
        if (lseek64(file_fd, offset, SEEK_SET) < 0)
        {
            perror("lseek64 failed");
            fprintf(stderr, "at offset %#lx\n", offset);
            cleanup();
            exit(EXIT_FAILURE);
        }
        /* write the value at the offset */
        else if (write(file_fd, &X, sizeof X) < 0)
            die("write failed", NULL);
        /* display message */
        else
            printf("Wrote %d at offset %#lx\n", X, offset);

        /* read the value at the offset from the map */
        X_prime = file_map[offset];

        /* display message */
        printf("Read %d at offset %#lx\n\n", X_prime, offset);

        /* if read and written values are not same */
        if (X != X_prime)
        {
            printf("\x1b[31mIncorrect value at offset \x1b[37m%#lx\x1b[31m!\x1b[0m\n\n", offset);
            cleanup(); /* perform cleanup tasks */
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
