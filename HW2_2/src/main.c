// 資工碩一 107598021 洪俊銘
// Problem 4.18
// Program to compute Pi using Monte Carlo method (openmp)

#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
#define OMP 11

int main()
{
    int amtWanted = 0;
    int totalPts  = 0;
    
    do
	{
        printf("Please enter a positive number for the amount of points you would like to generate? \n");
        scanf("%d", &amtWanted);  	
	}while (amtWanted <= 0);
  
    #pragma omp parallel if(OMP>10) num_threads(10)
	{
        int i = 0;
		for (i = 0; i < amtWanted; i++)
        {	
            double x = (double)rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;
        
            if (((x * x) + (y * y)) < 1)
            {
                totalPts++;
            }
        }
	}
    
    double pi = 4.0 * totalPts / amtWanted;
    printf("The approximate value of pi for the desired amount of points (%d) is: %f \n", amtWanted, pi);
    printf("\n");  
    return 0;
}