/**
 * ::------ TEAM DETAILS ------::
   Team No: 17
   Name: Manosrija Nasrin (L), Roll: 002111001117
   Name: Spandan Ghatak, Roll: 002111001106
   Name: Anirban Dey, Roll: 002111001108
   Name: Saptarshi Bhattacharya, Roll: 002111001113
 *
 * Date: 16-08-2023
 */

/**
 * ::------ ASSIGNMENT DETAILS ------::
 * Assignment 3: SOCKET Programming / IPC using SOCKET
 *
 * Problem Definition:
   Create two processes. Transfer 1GB file from process1 to
   process2 using a Socket. Now, transfer that file from process2
   to process1 using the same Socket. Now, compare the two files
   to make sure that the same file has returned back. Also, print
   the time required to do this double transfer. Attach this output
   to the source file as a comment.

   Please note that, you can see the socket which your program creates.
   There are also various bash shell commands available to see the
   sockets created by the program. So, once your program creates the
   socket, make sure you use proper command to see the socket info
   and paste that output as a comment in your source file.

 *
 * ::------ INPUT DESCRIPTION ------::
   This program does not take any input.
 *
 * ::------ OUTPUT DESCRIPTION ------::
   Any existing sockets or files with same name as the sockets are removed, and new ones are
   created. The program transfers a large file (1GB) through a socket from a process P1
   to a process P2. The transfer process is described through print statements that indicate
   when a process finishes transferring the file. The socket information is found out by using the
   ss command with the -x flag for Unix domain sockets. The total time for the double transfer
   from P1 to P2 and back to P1 is printed and the file contents are compared to see if they
   are same. Finally the "ls -lh" command is run via a system() call and the output is printed.
 */

/**
 * ::------ COMPILATION COMMAND ------::
    gcc 17_3.c -o 17_3 -Wall
 *
 * ::------ EXECUTION SEQUENCE ------::
 * To run the program, type in your terminal:
    ./17_3
 */
/**
 * Sample Input: ./17_3
 * Sample Output:
    <<TEAM 17>> $ dd if=/dev/urandom of=lfile_send.txt bs=1M count=1024 status=none
    Large file lfile_send.txt created. Socket created, P2 connected to the socket and P1
    accepted the connection.

    <<TEAM 17>> $ ss -xlp | head -n 1 && ss -xlp | grep %s ; -c 1
    Netid  State  Recv-Q  Send-Q   Local Address:Port   Peer Address:Port  Process
    u_str LISTEN    0      5       /tmp/socket 114748            * 0       users:(("ss",pid=13302,fd=5),("sh",pid=13301,fd=5),("17_3",pid=13293,fd=5))

    Begin transferring the files...
    Process P1 finished sending the large file to Process P2
    Process P2 finished sending the large file to Process P1
    Process P1 finished receiving the large file back from Process P2
    Transfer complete.

    Total time elapsed for double transfer: 14 seconds
    The files lfile_send.txt and lfile_recv.txt are the same.

    <<TEAM 17>> $ ls -lh /tmp/socket
    srwxr-xr-x 1 be21108 ugyr21 0 Aug 19 13:51 /tmp/socket

    <<TEAM 17>> $ ls -lh lfile_*
    -rwxrwxrwx 1 be21108 ugyr21 1.0G Aug 19 13:51 lfile_recv.txt
    -rwxrwxrwx 1 be21108 ugyr21 1.0G Aug 19 13:51 lfile_send.txt

 */

/**
 *  Total time elapsed for double transfer: 14 seconds
 *
 *  <<TEAM 17>> $ ls -lh /tmp/socket
    srwxr-xr-x 1 be21108 ugyr21 0 Aug 19 13:51 /tmp/socket
 *
 *  <<TEAM 17>> $ ls -lh lfile_*
    -rwxrwxrwx 1 be21108 ugyr21 1.0G Aug 19 13:51 lfile_recv.txt
    -rwxrwxrwx 1 be21108 ugyr21 1.0G Aug 19 13:51 lfile_send.txt

    <<TEAM 17>> $ ss -xlp | head -n 1 && ss -xlp | grep %s ; -c 1
    Netid  State  Recv-Q  Send-Q   Local Address:Port   Peer Address:Port  Process
    u_str LISTEN    0      5       /tmp/socket 114748            * 0       users:(("ss",pid=13302,fd=5),("sh",pid=13301,fd=5),("17_3",pid=13293,fd=5))
 */

#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/un.h>
#include <unistd.h>

#define MAXLEN 2000
#define MAX_CONN 5
#define SOCKET int

/* exit with error */
void die(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void sleep_with_error(int seconds)
{
    if (sleep(seconds) > 0)
    {
        errno = EINTR;
        perror("sleep failed");
    }
}

void close_and_die(const char *msg, SOCKET sockfd)
{
    perror(msg);
    if (close(sockfd) < 0)
        die("close");
    exit(EXIT_FAILURE);
}

/* compare two files using the diff command */
void compare_files(const char *file1, const char *file2)
{
    char command[MAXLEN];
    sprintf(command,
            "if diff -q \"%s\" \"%s\" >/dev/null; "
            "then echo \"The files %s and %s are the \x1b[32;1msame.\x1b[0m\"; else "
            "echo \"The files \x1b[3m%s\x1b[0m and \x1b[3m%s\x1b[0m are \x1b[31;1mdifferent.\x1b[0m\"; fi",
            file1, file2, file1, file2, file1, file2);
    if (system(command) < 0)
        die("system call failed on diff");
}

int main(int argc, char **argv)
{
    char *socket_path = "/tmp/socket";
    char *lfile_send = "lfile_send.txt";
    char *lfile_recv = "lfile_recv.txt";

    SOCKET sock_fd, listen_fd;
    SOCKET lfile_send_fd, lfile_recv_fd;
    struct sockaddr_un server_addr, client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    int process_id, status;
    char buffer1[MAXLEN], buffer2[MAXLEN], buffer3[MAXLEN];
    long read_bytes, elapsed_time;
    struct timeval t0, t1;
    char echo_command[150], command[100];

    sprintf(command, "dd if=/dev/urandom of=%s bs=1M count=%d status=none", lfile_send, 1024);
    sprintf(echo_command, "echo \"\x1b[32;1m<<TEAM 17>> $\x1b[0m dd if=/dev/urandom of=%s bs=1M"
                          " count=%d status=none\"",
            lfile_send, 1024);

    /* remove existing socket */
    if (remove(socket_path) > 0)
        printf("Removed existing socket");
    /* create the large file using the dd command */
    else if (system(echo_command) < 0 || system(command) < 0)
        die("system call failed on creating a large file");
    /* create the file which will receive the contents from P2 */
    else if (system("touch lfile_recv.txt") < 0)
        die("system call failed on creating the large receive file");

    /* create a child process */
    if ((process_id = fork()) < 0)
        die("fork failed");
    else if (process_id == 0)
    {
        /* we are in the child process - process P2 */

        /* set up the two sockets */
        memset(&server_addr, 0, sizeof server_addr);
        server_addr.sun_family = AF_UNIX;
        strncpy(server_addr.sun_path, socket_path, sizeof(server_addr.sun_path) - 1);

        sleep_with_error(3); /* wait for the time required for the server to set up */

        /* open the socket_path to receive data from process P1 */
        if ((sock_fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
            die("socket sock_fd");
        else if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof server_addr) < 0)
            close_and_die("connect sock_fd", sock_fd);

        while ((read_bytes = read(sock_fd, (void *)buffer2, MAXLEN)) > 0)
        {
            if (write(sock_fd, (void *)buffer2, read_bytes) < 0)
                die("write to socket_recv failed in P2");
            if (read_bytes < MAXLEN)
                break;
        }

        sleep_with_error(1);
        printf("\x1b[96mProcess P2\x1b[0m finished sending the large file to "
               "\x1b[93mProcess P1\x1b[0m\x1b[0m\n");
        _exit(EXIT_SUCCESS);
    }
    else
    {
        /* we are in the parent process - process P1 */

        /* print message */
        printf("Large file \x1b[3m%s\x1b[0m created. ", lfile_send);

        /* set up the server address */
        memset(&server_addr, 0, sizeof server_addr);
        server_addr.sun_family = AF_UNIX;
        strncpy(server_addr.sun_path, socket_path, sizeof(server_addr.sun_path) - 1);

        gettimeofday(&t0, NULL); /* get start time */

        /* open the large file in read-only mode */
        if ((lfile_send_fd = open(lfile_send, O_RDONLY)) < 0)
            die("lfile failed to open in P1");
        /* open a new large file for writing the data received from process P2 */
        else if ((lfile_recv_fd = open(lfile_recv, O_WRONLY)) < 0)
            die("lfile_recv failed to open in P1");
        /* create the socket */
        else if ((listen_fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
            die("socket listen_fd");
        else if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof server_addr) < 0)
            close_and_die("bind listen_fd", listen_fd);
        else if (listen(listen_fd, MAX_CONN) < 0)
            close_and_die("listen listen_fd", listen_fd);
        else if ((sock_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addrlen)) < 0)
            close_and_die("accept listen_fd", listen_fd);
        else
            printf("Socket created, P2 connected to the socket and P1 \naccepted the connection.\n\n");

        sprintf(command, "ss -xlp | head -n 1 && ss -xlp | grep %s ; -c 1", socket_path);
        sprintf(echo_command, "echo \"\x1b[32;1m<<TEAM 17>> $\x1b[0m %s\"", command);

        /* see socket information */
        if (system(echo_command) < 0 || system(command) < 0)
            close_and_die("ss failed", listen_fd);

        printf("\n");
        printf("Begin transferring the files...\n");

        gettimeofday(&t0, NULL); /* get start time */

        /* continously read from the large file and keep sending to socket_path */
        while ((read_bytes = read(lfile_send_fd, (void *)buffer1, MAXLEN)) > 0)
        {
            if (write(sock_fd, (void *)buffer1, read_bytes) < 0)
                die("write to socket_path failed in P1");
            /* continuously read from the receive FIFO and keep writing to the new large file */
            if ((read_bytes = read(sock_fd, (void *)buffer3, MAXLEN)) > 0)
            {
                if (write(lfile_recv_fd, (void *)buffer3, read_bytes) < 0)
                    die("write to lfile_recv failed in P1");
            }
        }
        printf("\x1b[93mProcess P1\x1b[0m finished sending the large file to \x1b[96mProcess P2\x1b[0m\x1b[0m\n");

        sleep_with_error(1);

        printf("\x1b[93mProcess P1\x1b[0m finished receiving the large file back from \x1b[96mProcess P2\x1b[0m\n");

        /* wait until the child processes exit/complete before going further */
        waitpid(process_id, &status, 0);

        /* transfer has completed */
        printf("Transfer complete.\n");

        gettimeofday(&t1, NULL); /* get end time */

        /* calculate the time elapsed for double transfer  */
        elapsed_time = (t1.tv_sec - t0.tv_sec);

        printf("\nTotal time elapsed for double transfer: \x1b[5m%ld\x1b[0m seconds\n", elapsed_time);

        /* compare the contents of the large file and the new large file */
        compare_files(lfile_send, lfile_recv);

        /* run the ls -lr command for the sockets */
        if (system("echo \"\n\x1b[32;1m<<TEAM 17>> $ \x1b[0mls -lh /tmp/socket\"") < 0 || system("ls -lh /tmp/socket") < 0)
            die("ls failed for SOCKETs");
        /* run the ls -lhr command for the large files */
        else if (system("echo \"\n\x1b[32;1m<<TEAM 17>> $ \x1b[0mls -lh lfile_*\"") < 0 || system("ls -lh lfile_*") < 0)
            die("ls failed for large files");
        else if (close(sock_fd) < 0)
            die("close sock_fd");
        else if (close(listen_fd) < 0)
            die("close listen_fd");
        else if (unlink(socket_path) < 0)
            die("unlink");
    }

    return 0;
}