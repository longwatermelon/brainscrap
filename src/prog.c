#include "prog.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>


struct Prog *prog_alloc(char **lines, size_t n)
{
    struct Prog *p = malloc(sizeof(struct Prog));
    p->lines = lines;
    p->n = n;

    p->pos = prog_find_x(p);
    p->dir = (vec2){ 1, 0 };

    p->prev = ' ';

    for (int i = 0; i < 30000; ++i)
        p->array[i] = 0;

    p->ptr = p->array;

    return p;
}


void prog_free(struct Prog *p)
{
    free(p);
}


void prog_run(struct Prog *p)
{
    while (prog_step(p))
        ;
}


void prog_debug(struct Prog *p)
{
    initscr();
    noecho();
    curs_set(FALSE);

    bool running = true;
    while (running)
    {
        clear();

        mvprintw(0, 0, "Current char: '%c'", p->prev);
        mvprintw(1, 0, "Cell value: %d", *p->ptr);

        for (size_t i = 0; i < p->n; ++i)
            mvprintw(i + 3, 0, "%s\n", p->lines[i]);

        refresh();
        usleep(1000);

        int ch = getch();

        switch (ch)
        {
        case 'q':
            running = false;
            break;
        case 'n':
            if (!prog_step(p))
                running = false;
            break;
        }
    }

    endwin();
}


bool prog_step(struct Prog *p)
{
    /* for (size_t i = 0; i < p->n; ++i) */
    /*     printf("%s", p->lines[i]); */

    vec2 select = vec2_add(p->pos, p->dir);
    char c = p->lines[select.y][select.x];

    switch (c)
    {
    case 'w':
        p->dir = (vec2){ 0, -1 };
        break;
    case 'a':
        p->dir = (vec2){ -1, 0 };
        break;
    case 's':
        p->dir = (vec2){ 0, 1 };
        break;
    case 'd':
        p->dir = (vec2){ 1, 0 };
        break;
    case '?':
    {
        float angle = *p->ptr ? M_PI / 2.f : -M_PI / 2.f;

        vec2 new = {
            p->dir.x * cosf(angle) - p->dir.y * sinf(angle),
            p->dir.x * sinf(angle) + p->dir.y * cosf(angle)
        };

        p->dir = new;
    } break;
    case 'e':
        return false;
    case '#':
        printf("\n==========\nRan into a wall, exiting.\n");
        printf("Position: %d %d\nDirection: %d %d\n==========\n\n", p->pos.x, p->pos.y, p->dir.x, p->dir.y);
        exit(0);
    }

    switch (p->prev)
    {
    case ',':
        *p->ptr = getchar();
        break;
    case '.':
        putchar(*p->ptr);
        break;
    case '<':
        --p->ptr;
        break;
    case '>':
        ++p->ptr;
        break;
    case '+':
        ++*p->ptr;
        break;
    case '-':
        --*p->ptr;
        break;
    }

    p->lines[p->pos.y][p->pos.x] = p->prev;
    p->pos = vec2_add(p->pos, p->dir);

    p->prev = p->lines[p->pos.y][p->pos.x];
    p->lines[p->pos.y][p->pos.x] = 'x';

    return true;
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

