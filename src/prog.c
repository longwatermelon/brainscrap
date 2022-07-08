#include "prog.h"
#include <stdio.h>
#include <stdlib.h>


struct Prog *prog_alloc(char **lines, size_t n)
{
    struct Prog *p = malloc(sizeof(struct Prog));
    p->lines = lines;
    p->n = n;

    return p;
}


void prog_free(struct Prog *p)
{
    free(p);
}


void prog_run(struct Prog *p)
{
    vec2 x = prog_find_x(p);
    printf("%d %d\n", x.x, x.y);
}


vec2 prog_find_x(struct Prog *p)
{
    for (size_t i = 0; i < p->n; ++i)
    {
        for (size_t j = 0; j < p->n; ++j)
        {
            if (p->lines[i][j] == 'x')
            {
                return (vec2){ j, i };
            }
        }
    }

    return (vec2){ -1, -1 };
}

