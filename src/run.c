#include "run.h"
#include <stdio.h>


void run_program(char **lines, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%s", lines[i]);
}

