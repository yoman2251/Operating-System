// 資工碩一 107598021 洪俊銘
// Problem 4.17
// Program to compute Pi using Monte Carlo method (pthread)

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

	
int amtWanted = 0;
int totalPts  = 0;

void *count(void *X);

int main()
{
    srand(time(NULL));
    pthread_t thread;

    do
	{
        printf("Please enter a positive number for the amount of points you would like to generate? \n");
        scanf("%d", &amtWanted);  	
	}while (amtWanted <= 0);
  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double pi = 4.0 * totalPts / amtWanted;
    printf("The approximate value of pi for the desired amount of points (%d) is: %f \n", amtWanted, pi);
    printf("\n");  
    return 0;
}

void *count(void *X)
{
    int i = 0;

    /* initialize random numbers */
    for (i=0; i < amtWanted; i++)
    {	
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        
        if (((x * x) + (y * y)) < 1)
        {
            totalPts++;
        }
    }
    return NULL;
}