#ifndef RUN_H
#define RUN_H

#include "util.h"
#include <sys/types.h>

struct Prog
{
    char **lines;
    size_t n;
};

struct Prog *prog_alloc(char **lines, size_t n);
void prog_free(struct Prog *p);

void prog_run(struct Prog *p);
vec2 prog_find_x(struct Prog *p);

#endif

