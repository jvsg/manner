// Copyright (c) 2022 Jaskaran Veer Singh
// MIT License

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include"windows.h"

// If -1, we calculate parameters at runtime
#define DEFAULT_MANPAGER_HEIGHT -1
#define DEFAULT_MANPAGER_WIDTH -1
#define DEFAULT_MANPAGER_STARTX 0
#define DEFAULT_MANPAGER_STARTY 0

#define DEFAULT_MANTREE_HEIGHT -1
#define DEFAULT_MANTREE_WIDTH 24
#define DEFAULT_MANTREE_STARTX -1
#define DEFAULT_MANTREE_STARTY 0


typedef struct config {
    manpager_box manpager;
    mantree_box mantree;
} config;

config* init_config();

#endif // __CONFIG_H__