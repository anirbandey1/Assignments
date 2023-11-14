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
 * Assignment 2B: IPC using Named Pipe (FIFO)
 *
 * Problem Definition:
   Create two processes. Transfer 1GB file from process1 to process2 using a
   FIFO. Now, transfer the same file from process2 to process1 using another
   FIFO. Now, compare the two files to make sure that the same file has returned
   back. Also, print the time required to do this double transfer. Attach this output
   to the source file as a comment.
   To create FIFO, you can either use shell command or system call.
   To create a large file you can use the relevant command.
   Use 'ls –l' command to show the FIFO and the large file. Attach this output to
   the source file as a comment.
 *
 * ::------ INPUT DESCRIPTION ------::
   This program does not take any input.
 *
 * ::------ OUTPUT DESCRIPTION ------::
   Any existing FIFOs or files with same name as the FIFOs are removed, and new ones are created.
   The program transfers a large file (1GB) through a named pipe (FIFO) from a process P1
   to a process P2. The transfer process is described through print statements that indicate
   when a process finishes transferring the file. The total time for the double transfer
   from P1 to P2 and back to P1 is printed and the file contents are compared to see if they
   are same. Finally the "ls -l" command is run via a system() call and the output is printed.
 */

/**
 * ::------ COMPILATION COMMAND ------::
    gcc 17_2B.c -o 17_2B -Wall
 *
 * ::------ EXECUTION SEQUENCE ------::
    In your Linux terminal, type: ./17_2B
    The program creates and deletes the large files on its own using system calls.
 */

/**
 * Sample Input: ./17_2B
 * Sample Output:
   <<TEAM 17>> $ dd if=/dev/urandom of=lfile_send.txt bs=1M count=1024 status=none
   Large file lfile_send.txt created

   Existing FIFOs removed and new FIFOs created: /tmp/fifo_send, /tmp/fifo_recv

   Begin transferring the files...
   Process P1 finished sending the large file to Process P2
   Process P2 finished sending the large file to Process P1
   Process P1 finished receiving the large file back from Process P2
   Transfer complete.

   Total time elapsed for double transfer: 44 seconds
   The files lfile_send.txt and lfile_recv.txt are the same.

   <<TEAM 17>> $ ls -lh /tmp/fifo_*
   prw-r--r-- 1 be21117 ugyr21 0 Aug 12 14:34 /tmp/fifo_recv
   prw-r--r-- 1 be21117 ugyr21 0 Aug 12 14:34 /tmp/fifo_send

   <<TEAM 17>> $ ls -lh lfile_*
   -rwxrwxrwx 1 be21117 ugyr21 1.0G Aug 12 14:34 lfile_recv.txt
   -rwxrwxrwx 1 be21117 ugyr21 1.0G Aug 12 14:34 lfile_send.txt

 */

/**
 * Total time elapsed for double transfer: 44 seconds
 *
 * <<TEAM 17>> $ ls -lh /tmp/fifo_*
   prw-r--r-- 1 be21117 ugyr21 0 Aug 12 14:34 /tmp/fifo_recv
   prw-r--r-- 1 be21117 ugyr21 0 Aug 12 14:34 /tmp/fifo_send
 *
 * <<TEAM 17>> $ ls -lh lfile_*
   -rwxrwxrwx 1 be21117 ugyr21 1.0G Aug 12 14:34 lfile_recv.txt
   -rwxrwxrwx 1 be21117 ugyr21 1.0G Aug 12 14:34 lfile_send.txt
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>

#define MAXLEN 16000 /* transfer 16K bytes at a time */

/* exit with error */
void die(const char *msg)
{
    unsigned int ERRNO = errno;
    perror(msg);
    exit(ERRNO);
}

/* compare two files using the diff command */
void compare_files(const char *file1, const char *file2)
{
    char command[MAXLEN];
    sprintf(command,
            "if cmp \"%s\" \"%s\" >/dev/null; "
            "then echo \"The files %s and %s are the \x1b[32;1msame.\x1b[0m\"; else "
            "echo \"The files \x1b[3m%s\x1b[0m and \x1b[3m%s\x1b[0m are \x1b[31;1mdifferent.\x1b[0m\"; fi",
            file1, file2, file1, file2, file1, file2);
    if (system(command) < 0)
        die("system call failed on cmp");
}

int main(int argc, char **argv)
{
    char *fifo_send = "/tmp/fifo_send";
    char *fifo_recv = "/tmp/fifo_recv";
    char *lfile_send = "/tmp/lfile_send.txt";
    char *lfile_recv = "/tmp/lfile_recv.txt";
    int fifo_send_fd, fifo_recv_fd, lfile_send_fd, lfile_recv_fd;
    int process_id, status;
    char buffer1[MAXLEN], buffer2[MAXLEN], buffer3[MAXLEN];
    long read_bytes, elapsed_time;
    struct timeval t0, t1;
    char echo_command[150], command[100];

    sprintf(command, "dd if=/dev/urandom of=%s bs=1M count=%d status=none", lfile_send, 1024);
    sprintf(echo_command, "echo \"%s %s\"", "\x1b[32;1m<<TEAM17>> $\x1b[0m", command);

    /* create the large file using the dd command */
    if (system(echo_command) < 0 || system(command) < 0)
        die("system call failed on creating a large file");
    /* create the file which will receive the contents from P2 */
    else if (sprintf(command, "touch %s", lfile_recv) == 0 || system(command) < 0)
        die("system call failed on creating the large receive file");
    else
        printf("Large file \x1b[3m%s\x1b[0m created\n\n", lfile_send);

    /* remove any existing FIFOs with the same name to avoid error on mkfifo */
    if (!(remove(fifo_send) < 0 || remove(fifo_recv) < 0))
        printf("Existing FIFOs removed and ");

    /* make two FIFOs*/
    if (mkfifo(fifo_send, 0666) < 0) /* FIFO to send data from P1 to P2 */
        die("mkfifo fifo_send");
    else if (mkfifo(fifo_recv, 0666) < 0) /* FIFO to send data from P2 to P1 */
        die("mkfifo fifo_recv");
    else
        printf("New FIFOs created: \x1b[3m%s\x1b[0m, \x1b[3m%s\x1b[0m\n\n", fifo_send, fifo_recv);

    printf("Begin transferring the files...\n");

    /* create a child process */
    if ((process_id = fork()) < 0)
        die("fork failed");
    else if (process_id == 0)
    {
        /* we are in the child process - process P2 */

        /* open the fifo_send to receive data from process P1 */
        if ((fifo_send_fd = open(fifo_send, O_RDONLY)) < 0)
            die("fifo_send failed to open in P2");
        /* open the fifo_recv to send data to process P1 */
        else if ((fifo_recv_fd = open(fifo_recv, O_WRONLY)) < 0)
            die("fifo_recv failed to open in P1");

        /* read from fifo_send and write to fifo_recv */
        while ((read_bytes = read(fifo_send_fd, (void *)buffer2, MAXLEN)) > 0)
        {
            if (write(fifo_recv_fd, (void *)buffer2, read_bytes) < 0)
                die("write to fifo_recv failed in P2");
            if (read_bytes < MAXLEN) /* reached the end of file */
                break;
        }

        printf("\x1b[96mProcess P2\x1b[0m finished sending the large file to \x1b[93mProcess P1\x1b[0m\x1b[0m\n");
        exit(1);
    }
    else
    {
        /* we are in the parent process - process P1 */

        /* open the large file in read-only mode */
        if ((lfile_send_fd = open(lfile_send, O_RDONLY)) < 0)
            die("lfile failed to open in P1");
        /* open the fifo to send the large file to process P2*/
        else if ((fifo_send_fd = open(fifo_send, O_WRONLY)) < 0)
            die("fifo_send failed to open in P1");
        /* open the fifo_recv to read the data sent by process P2 */
        else if ((fifo_recv_fd = open(fifo_recv, O_RDONLY)) < 0)
            die("fifo_recv failed to open in P1");
        /* open a new large file for writing the data received from process P2 */
        else if ((lfile_recv_fd = open(lfile_recv, O_WRONLY)) < 0)
            die("lfile_recv failed to open in P1");

        gettimeofday(&t0, NULL); /* get start time of transfer */

        /* continously read from the large file and keep sending to fifo_send */
        while ((read_bytes = read(lfile_send_fd, (void *)buffer1, MAXLEN)) > 0)
        {
            if (write(fifo_send_fd, (void *)buffer1, read_bytes) < 0)
                die("write to fifo_send failed in P1");
            /* continuously read from the receive FIFO and keep writing to the new large file */
            if ((read_bytes = read(fifo_recv_fd, (void *)buffer3, MAXLEN)) > 0)
            {
                if (write(lfile_recv_fd, (void *)buffer3, read_bytes) < 0)
                    die("write to lfile_recv failed in P1");
            }
            if (read_bytes < MAXLEN) /* reached the end of file */
                break;
        }

        printf("\x1b[93mProcess P1\x1b[0m finished sending the large file to \x1b[96mProcess P2\x1b[0m\x1b[0m\n");

        /* wait until the child processes exit/complete before going further */
        waitpid(process_id, &status, 0);

        printf("\x1b[93mProcess P1\x1b[0m finished receiving the large file back from \x1b[96mProcess P2\x1b[0m\n");

        /* transfer has completed */
        printf("Transfer complete.\n");

        gettimeofday(&t1, NULL); /* get end time of transfer */

        /* calculate the time elapsed for double transfer  */
        elapsed_time = (t1.tv_sec - t0.tv_sec);

        printf("\nTotal time elapsed for double transfer: \x1b[5m%ld\x1b[0m seconds\n", elapsed_time);

        /* compare the contents of the large file and the new large file */
        compare_files(lfile_send, lfile_recv);

        /* run the ls -lr command for the FIFOs */
        if (system("echo \"\n\x1b[32;1m<<TEAM 17>> $ \x1b[0mls -lh /tmp/fifo_*\"") < 0 || system("ls -lh /tmp/fifo_*") < 0)
            die("ls failed for FIFOs");
        /* run the ls -lhr command for the large files */
        else if (system("echo \"\n\x1b[32;1m<<TEAM 17>> $ \x1b[0mls -lh /tmp/lfile_*\"") < 0 || system("ls -lh /tmp/lfile_*") < 0)
            die("ls failed for large files");
        else if (unlink(fifo_send) < 0 || unlink(fifo_recv))
            die("unlink error on fifo");
        else if (remove(lfile_send) < 0 || remove(lfile_recv) < 0)
            die("remove error on lfile");
    }

    return 0;
}
