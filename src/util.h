#ifndef UTIL_H
#define UTIL_H

#include <sys/types.h>

typedef struct
{
    int x, y;
} vec2;

vec2 vec2_add(vec2 a, vec2 b);

char **util_readlines(const char *path, size_t *n);

#endif

