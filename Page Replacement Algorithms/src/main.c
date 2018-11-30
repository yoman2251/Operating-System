// 資工碩一 107598021 洪俊銘
// Purpose :　Write a program that implements the FIFO, LRU, and optimal page-replacement algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int frameNumber;

int fifo(int prefs[], int size)
{
    int replace = 0, numOfPageFaults = 0, avail;
    int frames[100];
    
    for (int i = 0; i < frameNumber; i++)
    {
        frames[i] = -1;
    }
    int j = 0;
    for(int i = 1;i <= size; i++)
    {
        avail = 0;
        for(int k = 0; k < frameNumber; k++)
        {
            if(frames[k] == prefs[i])
                avail = 1;
        }
        if (avail==0)
        {
            frames[j] = prefs[i];
            j = (j + 1) % frameNumber;
            numOfPageFaults++;
        }
        
    }
    return numOfPageFaults;
}

int lru (int prefs[], int size)
{
    int frames[100],c=0,c1, k = 0,t,b[100],c2[100];
    int numOfPageFaults = 0;

    frames[k]=prefs[k];

    numOfPageFaults++;
    k++;
    for(int i = 1; i < size; i++)
    {
        c1 = 0;
        for(int j = 0; j < frameNumber; j++)
        {
            if(prefs[i] != frames[j])
                c1++;
        }
        if(c1 == frameNumber)
        {
            numOfPageFaults++;
            if(k < frameNumber)
            {
                frames[k] = prefs[i];
                k++;
            }
            else
            {
                for(int r = 0; r < frameNumber; r++)
                {
                    c2[r]=0;
                    for(int j = i-1; j < size; j--)
                    {
                        if(frames[r] != prefs[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for(int r = 0; r < frameNumber; r++)
                    b[r] = c2[r];
                    for(int r = 0; r < frameNumber;r++)
                    {
                        for(int j = r; j < frameNumber; j++)
                        {
                            if(b[r] < b[j])
                            {
                                t = b[r];
                                b[r] = b[j];
                                b[j]=t;
                            }
                        }
                    }
                    for(int r = 0; r < frameNumber; r++)
                    {
                        if(c2[r] == b[0])
                            frames[r] = prefs[i];
                    }
                }
            }

    }
    return numOfPageFaults;
}

int optimal(int prefs[], int size)
{
    int frames[100], pages[30], temp[10], flag1, flag2, flag3, pos, max;
    int numOfPageFaults = 0;
    
    for(int i = 0; i < frameNumber; ++i)
    {
        frames[i] = -1;
    }
    for(int i = 0; i < size; ++i)
    {
        flag1 = flag2 = 0;
        
        for(int j = 0; j < frameNumber; ++j)
        {
            if(frames[j] == prefs[i])
            {
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0)
        {
            for(int j = 0; j < frameNumber; ++j)
            {
                if(frames[j] == -1)
                {
                    numOfPageFaults++;
                    frames[j] = prefs[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
        {
            flag3 =0;
            
            for(int j = 0; j < frameNumber; ++j){
                temp[j] = -1;
                
                for(int k = i + 1; k < size; ++k)
                {
                    if(frames[j] == prefs[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            
            for(int j = 0; j < frameNumber; ++j)
            {
                if(temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            
            if(flag3 ==0)
            {
                max = temp[0];
                pos = 0;
                
                for(int j = 1; j < frameNumber; ++j)
                {
                    if(temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }                
            }
            
            frames[pos] = prefs[i];
            numOfPageFaults++;
        }
        
    }
    return numOfPageFaults;
}

int main(int argc, char *argv[])
{
    int pagingMode = 0;
    int prefs[100];
    int pageSize = 0;
    int check = 0;
    char input[100];
    int number;
    char *delim = " ";

    if (strcmp(argv[1], "FIFO") == 0)
    {
        pagingMode = 0;
    }
    else if(strcmp(argv[1], "LRU") == 0)
    {
        pagingMode = 1;
    }
    else if(strcmp(argv[1], "optimal") == 0)
    {
        pagingMode = 2;
    }
    
    frameNumber = atoi(argv[2]);
    if (frameNumber > 7) 
    {
         printf("Page frames can vary from 1 to 7.\n");
        exit(1);
    }
    if (pagingMode == 0)
    {
        printf("Algorithm: FIFO\nFrames Allocated: %d\n",frameNumber);
    }
    else if (pagingMode == 1)
    {
        printf("Algorithm: LRU\nFrames Allocated: %d\n",frameNumber);
    }
    else if (pagingMode == 2)
    {
        printf("Algorithm: optimal\nFrames Allocated: %d\n",frameNumber);
    }
    
    printf("Enter the page reference string:\n");
    fgets(input, sizeof input, stdin);
   
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(i%2 == 0) 
        {
            prefs[pageSize] = input[i] - '0';
            pageSize ++;
        }
    }
    
    if (pagingMode == 0)
    {
        printf("Number of faults: %d\n\n", fifo(prefs, pageSize));
    }
    else if (pagingMode == 1)
    {
        printf("Number of faults: %d\n\n", lru(prefs, pageSize));
    }
    else if (pagingMode == 2)
    {
        printf("Number of faults: %d\n\n", optimal(prefs, pageSize));
    }
    
    return 0;
}