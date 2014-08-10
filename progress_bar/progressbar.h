#ifndef __PROGRESS_BAR_H
#define __PROGRESS_BAR_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CENT 100

#define PATTERN_LEN 100

typedef struct {
    char *pattern;
    int max_val;
} bar_t;

int progress_bar(bar_t *new_bar, int cur_val);

#endif
