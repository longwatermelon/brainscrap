#include "util.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        fprintf(stderr, "No file provided; exiting.\n");
        exit(1);
    }

    size_t n;
    char **lines = util_readlines(argv[1], &n);

    printf("%zu\n", n);

    for (size_t i = 0; i < n; ++i)
        free(lines[i]);

    free(lines);

    return 0;
}

