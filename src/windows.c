// Copyright (c) 2022 Jaskaran Veer Singh
// MIT License

#include"windows.h"
#include"config.h"

#include<stdlib.h>

void calculate_win_parameters(WINDOW* stdscr, manner_box* b, win_type t)
{
    int x, y;
    getmaxyx(stdscr, y, x);

    switch (t)
    {
    case TYPE_MANPAGER:
        b->height = (b->height == -1) ? y : b->height;
        b->width = (b->width == -1 ) ? x - DEFAULT_MANTREE_WIDTH : b->width;
        b->startx = (b->startx == -1) ? 0 : b->startx;
        b->starty = (b->starty == -1) ? 0 : b->starty;
        break;
    
    case TYPE_MANTREE:
        b->height = (b->height == -1) ? y : b->height;
        b->width = (b->width == -1 ) ? x/2 : b->width;
        b->startx = (b->startx == -1) ? x - DEFAULT_MANTREE_WIDTH: b->startx;
        b->starty = (b->starty == -1) ? 0 : b->starty;
    default:
        break;
    }    
}

window *create_win(WINDOW* stdscr, manner_box* b, win_type t)
{
    switch (t)
    {
    case TYPE_MANPAGER:
        calculate_win_parameters(stdscr, b, TYPE_MANPAGER);
        break;
    case TYPE_MANTREE:
        calculate_win_parameters(stdscr, b, TYPE_MANTREE);
    default:
        break;
    }
    
    window* w = (window*) malloc(sizeof(window));
    w->win = subwin(stdscr, b->height, b->width, b->starty, b->startx);
    box(w->win, 0 , 0);
    wrefresh(w->win);

    return w;
}

void destroy_win(window * w)
{	
    wborder(w->win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(w->win);
    delwin(w->win);

    free(w);
}

void draw_borders(window* w)
{
    int x, y, i;
    getmaxyx(w->win, y, x);

    mvwprintw(w->win, 5, 5, "+");
    mvwprintw(w->win, y - 1, 0, "+");
    mvwprintw(w->win, 0, x - 1, "+");
    mvwprintw(w->win, y - 1, x - 1, "+");

    for (i = 1; i < (y - 1); i++)
    {
        mvwprintw(w->win, i, 0, "|");
        mvwprintw(w->win, i, x - 1, "|");
    }
    
    for (i = 1; i < (x - 1); i++)
    {
        mvwprintw(w->win, 0, i, "-");
        mvwprintw(w->win, y - 1, i, "-");
    }
}
