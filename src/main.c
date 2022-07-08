#include "util.h"
#include "prog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: ./a.out [command] [command args]\n");
        exit(1);
    }

    if (strcmp(argv[1], "make") == 0)
    {
        int size = atoi(argv[2]);
        char *line = malloc(sizeof(char) * (size + 1));
        memset(line, ' ', size);
        line[size] = '\0';

        line[0] = '#';
        line[size - 1] = '#';

        char *full_line = malloc(sizeof(char) * (size + 1));
        memset(full_line, '#', size);

        FILE *fp = fopen(argv[3], "w");
        fprintf(fp, "%s\n", full_line);

        for (int i = 1; i < size - 1; ++i)
            fprintf(fp, "%s\n", line);

        fprintf(fp, "%s", full_line);
        fclose(fp);

        free(line);
        free(full_line);
    }
    else if (strcmp(argv[1], "run") == 0)
    {
        size_t n;
        char **lines = util_readlines(argv[2], &n);

        struct Prog *p = prog_alloc(lines, n);
        prog_run(p);
        prog_free(p);

        for (size_t i = 0; i < n; ++i)
            free(lines[i]);

        free(lines);
    }
    else
    {
        fprintf(stderr, "Command '%s' not recognized.\n", argv[1]);
        exit(1);
    }

    return 0;
}

