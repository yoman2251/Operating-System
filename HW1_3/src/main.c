#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 2048

int main (int argc, char** argv) 
{

    char readBuffer[BUFFER_SIZE];
    char writeBuffer[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
 
    if (argc < 3)
    {
        printf("At least need 2 parameters\n");
        exit(1);
    }

    int inputFile = open(argv[1], O_RDONLY);                    // input the input.txt
    int copyFile = open(argv[2], O_WRONLY | O_CREAT, 0644);     // input the copy.txt
     
    if ( inputFile == -1 || copyFile == -1 )
    {
        printf("Opening file failed\n");
        exit(1);
    }

    if (pipe(fd) == -1)         // Create the pipe
    {
        fprintf(stderr, "Create pipe failed\n");
        exit(1);
    }

    pid = fork();               // fork a child process

    if (pid < 0)                // error occurred
    {
        fprintf(stderr, "Error in fork!\n");
        exit(1);
    }

    else if (pid == 0)          // child prcocess
    {
        close(fd[1]);           // close the usused end of the pipe

        ssize_t length = read(fd[0], writeBuffer, sizeof(readBuffer));        // read from the pipe
        write(copyFile, writeBuffer, length);
        
        close(fd[0]);           // close the write end of the pipe
        
    }

    else if (pid > 0)           // parent process
    {
        close(fd[0]);           // close the unused end of the pipe
        
        ssize_t length = read(inputFile, readBuffer, sizeof(readBuffer));        // read from the pipe
        write(fd[1], readBuffer, length);

        close(fd[1]);           // close the write end of the pipe
        
    }

    close(inputFile);
    close(copyFile);

    return 0;
}
