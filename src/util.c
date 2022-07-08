#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


vec2 vec2_add(vec2 a, vec2 b)
{
    return (vec2){
        a.x + b.x,
        a.y + b.y
    };
}


char **util_readlines(const char *path, size_t *n)
{
    char **lines = 0;
    *n = 0;

    FILE *fp = fopen(path, "r");
    char *line = 0;
    size_t len = 0;
    ssize_t read;

    if (!fp)
    {
        fprintf(stderr, "Couldn't read file %s\n", path);
        return 0;
    }

    while ((read = getline(&line, &len, fp)) != -1)
    {
        lines = realloc(lines, sizeof(char*) * ++*n);
        lines[*n - 1] = malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(lines[*n - 1], line);
    }

    free(line);
    fclose(fp);

    return lines;
}

