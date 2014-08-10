#include "progressbar.h"

static char *create_pattern(char *pattern)
{
    char *pat_str = (char *)calloc(PATTERN_LEN, sizeof(char));
    int i=0;

    strcpy(pat_str, "");
    memset(pat_str, 0, sizeof(pat_str));
    for(i=0; i<CENT; i++)
        strcat(pat_str, pattern);

    return pat_str;
}

int progress_bar(bar_t *new_bar, int cur_val)
{
    static bar_t *saved_bar;
    int update;
    static char *pat_str;

    if(!new_bar)
    {
        saved_bar = new_bar;
        pat_str = create_pattern(saved_bar->pattern);
    }

    update = (cur_val * CENT) / saved_bar->max_val;
    printf("\r[%-*.*s] %d%%", CENT, update, pat_str, update);
    fflush(stdout);

    return update;
}
