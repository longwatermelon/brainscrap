#ifndef RUN_H
#define RUN_H

#include "util.h"
#include <stdbool.h>
#include <sys/types.h>

struct Prog
{
    char **lines;
    size_t n;

    vec2 pos, dir; // x
    char prev;

    // Brainfuck elements
    char array[30000];
    char *ptr;
};

struct Prog *prog_alloc(char **lines, size_t n);
void prog_free(struct Prog *p);

void prog_run(struct Prog *p);
// Return false if program should stop
bool prog_step(struct Prog *p);

vec2 prog_find_x(struct Prog *p);

#endif

