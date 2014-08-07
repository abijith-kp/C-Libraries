#timeit

Header file: timeit.h

Definitions: timeit.c

### t_timeit()

Purpose: Find the running time of any functions of the form void* <name>(void *).

Arguments: Function pointer, argument to the function, number of repetitions.

Return Value: A struct timespec gives the cumulative running time.

### t_repeat()

Purpose: Find the running time of any functions of the form void* <name>(void *) for N given repetitions.

Arguements: Function pointer, argument to the function, number of repetitions.

Return Value: A struct timespec gives the cumulative running time.


Credit: The diff function in the program was initially taken from
[here](http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/)
