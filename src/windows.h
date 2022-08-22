// Copyright (C) 2022 Jaskaran Veer Singh
// MIT License

#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include<ncurses.h>

typedef enum win_type {
    TYPE_MANPAGER,
    TYPE_MANTREE
    // will probably add a search box later too
} win_type;

typedef struct manner_box {
    int height;
    int width;
    int starty;
    int startx;
} manner_box;

typedef manner_box manpager_box;
typedef manner_box mantree_box;

typedef struct window {
    WINDOW* win;
    win_type type;
} window;

window* create_win(WINDOW*, manner_box*, win_type);
void draw_borders(window*);
void destroy_win(window*);

#endif // __WINDOWS_H__