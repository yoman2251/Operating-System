#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MIN_PID 300
#define MAX_PID 5000

int allocate_map();             // Creates and initializes a data structure for representing pids; returns —1 if unsuccessful, 1 if successful
int allocate_pid();             // Allocates and returns a pid; returns -1 if unable to allocate a pid (all pids are in use)
void release_pid(int pid);      // Releases a pid

struct pid_tab
{
    int pid;
    bool bitmap;
}pidArray[4700];

int main(int agrc, char** agrv) 
{
    int map = allocate_map();
    if (map == 1)
    {
        printf("Data Structure initialized.\n");

        int i = 0;
        while (i < 15)
        {
            int val = allocate_pid();
            printf("Process %d : Pid = %d\n", i + 1, val);
            i++;
        }

        release_pid(503);

        release_pid(505);

        release_pid(302);                       
        printf("pid 302 released.\n");

        release_pid(311);                       
        printf("pid 311 released.\n");
        
        int pid_1 = allocate_pid();                        // this pid will be 302
        printf("Process: %d; Pid: %d\n", i + 1, pid_1);

        int pid_2 = allocate_pid();                        // this pid will be 311
        printf("Process: %d; Pid: %d\n", i + 1, pid_2);

        int pid_3 = allocate_pid();                        // this pid will be 315
        printf("Process: %d; Pid: %d\n", i + 1, pid_3);
    }
    else
    {
        printf("Failed to initialize data structure.\n");
    }

    return 0;
}


int allocate_map() 
{
    int i = 0, j = 0;
    for (i = MIN_PID, j = 0; i < MAX_PID; i++, j++)
    {
        pidArray[j].pid = i;
        pidArray[j].bitmap = 0;
    }
    if (i == MAX_PID && j == 4700) return 1;
    else return -1;
}

int allocate_pid() 
{
    for (int i = MIN_PID, j = 0; i <= MAX_PID; i++, j++)
    {
        if(pidArray[j].bitmap == 0)
        {
            pidArray[j].pid = i;
            pidArray[j].bitmap = 1;
            return i;
            break;
        }
    }

    return -1;
}

void release_pid(int pid) 
{
    for(int i = 0; i <= 4700; i++)
    {
        if(pidArray[i].pid == pid)
        {
            pidArray[i].bitmap = 0;
        }
    }
}
