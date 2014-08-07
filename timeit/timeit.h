#ifndef __TIMEIT_H
#define __TIMEIT_H 1

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void *( *function_t )( void * );

struct timespec t_timeit(function_t f, void *params, int number);

struct timespec *t_repeat(function_t f, void *params, int repeat, int number);

#endif /* end of timeit.h */
