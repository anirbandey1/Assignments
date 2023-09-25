/** ::------ TEAM DETAILS ------::
 * Team No: 17
   Name: Manosrija Nasrin (L), Roll: 002111001117
   Name: Spandan Ghatak, Roll: 002111001106
   Name: Anirban Dey, Roll: 002111001108
   Name: Saptarshi Bhattacharya, Roll: 002111001113
 *
 * Date: 20-09-2023
 */

/** ::------ ASSIGNMENT DETAILS ------::
 * Assignment 6: Observing the OS through the /proc file system
 *
 * Problem Definition:
   The OS is a program that uses various data structures. Like all programs 
   in execution, you can determine the performance and other behaviour of the 
   OS by inspecting its state - the values stored in its data structures. In 
   this part of the assignment, we study some aspects of the organization and 
   behaviour of a Linux system by observing values of kernel data structures 
   exposed through the /proc virtual file system.
   
   The /proc virtual file system:
   
   Linux uses the /proc file system to collect information from kernel data 
   structures. The /proc implementation provided with Linux can read many 
   different kernel data structures. If you cd to /proc on a Linux machine, 
   you will see a number of files and directories at that location. Files in 
   this directory subtree each correspond to some kernel data structure. The 
   subdirectories with numeric names contain virtual files with information 
   about the process whose process ID is the same as the directory name. Files 
   in /proc can be read like ordinary ASCII files. You can open each file and 
   read it using library routines such as fgets() or fscanf(). The proc (5) 
   manual page explains the virtual files and their content available through 
   the /proc file system.
   
   Requirements in detail:
   
   You are supposed to write a C program which should run continuously and 
   print lists of the following dynamic values every seconds:
   
   Per second disk read/write in the systm
   Per second Timer Interrupts
   Currently executing kernel scheduling entities (processes, threads)
   Number of kernel scheduling entities that currently exist on the system
 *
 * ::------ INPUT DESCRIPTION ------::
   This program does not take any input.
 *
 * ::------ OUTPUT DESCRIPTION ------::
   The program reads the /proc/stat and /proc/diskstats to get information about disk read/writes per second.
   The files are parsed to get the required information and the statistics are printed every second.
*/

/** ::------ COMPILATION COMMAND ------::
	gcc 17_6.c -o 17_6 -Wall
 *
 * ::------ EXECUTION SEQUENCE ------::
 * In a terminal, run:  ./17_6
   Press Ctrl+C to exit.
 */

/**
 * Sample Input: ./17_6
   Sample Output:
    Disk read/s      Disk write/s    Timer interrupt/s       Running kernel entities        Total kernel entities

      0                0                    9854                       1                    2355
      0                0                    3613                       1                    2350
      0                0                    1123                       1                    2350
      0                0                    3385                       2                    2345
      0                0                    1459                       1                    2340
^C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
typedef unsigned long long int ull;

const char *DISK_FILE = "/proc/diskstats";
const char *STAT_FILE = "/proc/stat";
const char *LOADAVG_FILE = "/proc/loadavg";

/* utility function - external error handling */
void die(const char *message, const char *action)
{
    perror(message);
    if (action != NULL)
        fprintf(stderr, "Please %s.\n", action);
    exit(EXIT_FAILURE);
}

/* search for a line in file containing the substring search */
int search_for_line_in_file(const char *filename, const char *search, char *output) {
    char line[MAX_LINE_LENGTH], command[MAX_LINE_LENGTH/8];
    FILE *file_pointer;
    
	if ((file_pointer = fopen(filename, "r")) == NULL) {
		sprintf(command, "open %s", filename);
		die(command, NULL);		
	}

	while (fgets(line, sizeof(line), file_pointer) > 0)
	{
		if (strstr(line, search))
		{
			/* found the line containing the desired information */
			strcpy(output, line);
			fclose(file_pointer);
			return 1;
		}
	}

    /* line not found */
	fclose(file_pointer);       
	return 0;
}

/* read disk statistics */
void read_disk_stats(ull *num_reads, ull *num_writes) {
    const char *search_substr = "sda ";
    char output[MAX_LINE_LENGTH], *char_ptr;
    
    if (search_for_line_in_file(DISK_FILE, search_substr, output) == 1) {
        /* parse the line */
        char_ptr = strstr(output, search_substr);
        sscanf(char_ptr, "sda %llu %*u %llu %*s", num_reads, num_writes);
    }
}

/* read interrupt statistics */
void read_interrupt_stats(ull *num_interrupt) {
    const char *search_substr = "intr ";
    char output[MAX_LINE_LENGTH], *char_ptr;
    
    if (search_for_line_in_file(STAT_FILE, search_substr, output) == 1) {
        /* parse the line */
        char_ptr = strstr(output, search_substr);
        sscanf(char_ptr, "intr %llu %*s", num_interrupt);
    }
}

/* read process statistics */
void read_process_stats(ull *num_running_process, ull *num_curr_process) {
    const char *search_substr1 = "procs_running ", *search_substr2 = "/";
    char output[MAX_LINE_LENGTH], *char_ptr;
    
    if (search_for_line_in_file(STAT_FILE, search_substr1, output) == 1) {
        /* parse the line */
        char_ptr = strstr(output, search_substr1);
        sscanf(char_ptr, "procs_running %llu %*s", num_running_process);
    }
    
    if (search_for_line_in_file(LOADAVG_FILE, search_substr2, output) == 1) {
        /* parse the line */
        char_ptr = strstr(output, search_substr2);
        sscanf(char_ptr, "/%llu %*s", num_curr_process);
    }
    
}

int main(int argc, char **argv)
{
    ull num_reads, num_writes, num_interrupt;
    ull prev_interrupt = 0, prev_num_read = 0, prev_num_write = 0;
    ull num_curr_process, num_running_process;
    int flag_first = 1;

    printf("Disk read/s\t Disk write/s\t Timer interrupt/s\t Running kernel entities\tTotal kernel entities\n\n");
    
    while(1) {
        read_disk_stats(&num_reads, &num_writes);
        read_interrupt_stats(&num_interrupt);
        read_process_stats(&num_running_process, &num_curr_process);
        
        if (flag_first == 1) {
        	/* skip the first iteration */
            flag_first = 0;
        } else {
            /* print the statistics */
            printf("%7llu\t\t %7llu\t\t %7llu\t\t %7llu\t\t %7llu\n", (num_reads - prev_num_read), (num_writes - prev_num_write), (num_interrupt - prev_interrupt), num_running_process, num_curr_process);
        } 
        
        prev_num_read = num_reads;
        prev_num_write = num_writes;
        prev_interrupt = num_interrupt;
        
        sleep(1);
    }
	return 0;
}
