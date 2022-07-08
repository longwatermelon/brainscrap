#ifndef UTIL_H
#define UTIL_H

#include <sys/types.h>

typedef struct
{
    int x, y;
} vec2;

char **util_readlines(const char *path, size_t *n);

#endif

