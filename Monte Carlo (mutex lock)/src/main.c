// 資工碩一 107598021 洪俊銘
// Problem 6.33
// Program to compute Pi using Monte Carlo method (mutex locks) 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long incircle = 0;
long points_per_thread;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *runner() 
{
    int incircle_thread = 0;

    unsigned int rand_state = rand();
    long i;
    for (i = 0; i < points_per_thread; i++) 
    {
        double x = rand_r(&rand_state) / ((double)RAND_MAX);
        double y = rand_r(&rand_state) / ((double)RAND_MAX);

        if ( (x * x) + (y * y) < 1) 
        {
            incircle_thread++;
        }
    }
    
    pthread_mutex_lock(&mutex);
    incircle += incircle_thread;
    pthread_mutex_unlock(&mutex);
}


int main(int argc, const char *argv[])
{
    if (argc != 3) 
    {
        fprintf(stderr, "usage: bin/mutex <total points> <threads>\n");
        exit(1);
    }

    long totalpoints = atol(argv[1]);
    int thread_count = atoi(argv[2]);
    points_per_thread = totalpoints / thread_count;

    pthread_t *threads = malloc(thread_count * sizeof(pthread_t));

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < thread_count; i++) 
    {
        pthread_create(&threads[i], &attr, runner, (void *) NULL);
    }

    for (int i = 0; i < thread_count; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    free(threads);

    printf("%ld points ; ", totalpoints);
    printf("PI : %f\n", (4. * (double)incircle) / ((double)points_per_thread * thread_count));

    return 0;
}