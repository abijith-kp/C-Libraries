#include "timeit.h"

struct timespec diff(struct timespec start, struct timespec end)
{
    struct timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0)
    {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    }
    else
    {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }

    return temp;
}

struct timespec t_timeit(function_t f, void *params, int number)
{
    struct timespec time1, time2;
    int i;

    memset(&time1, 0, sizeof(time1));
    memset(&time2, 0, sizeof(time2));

    if(number <= 0)
        return time1;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    for(i=0; i<number; i++)
        ( *f )( params );
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);

    return diff(time1, time2);
}

struct timespec *t_repeat(function_t f, void *params, int repeat, int number)
{
    struct timespec time1, time2;
    struct timespec *result = calloc(repeat, sizeof(struct timespec));
    int i, j;

    if((repeat <= 0) || (number <= 0))
    {   free(result);
        return NULL;
    }

    for(i=0; i<repeat; i++)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
        for(j=0; j<number; j++)
            ( *f )( params );
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
        time1 = diff(time1, time2);
        result[i].tv_sec = time1.tv_sec;
        result[i].tv_nsec = time1.tv_nsec;
    }

    free(result);
    return result;
}
