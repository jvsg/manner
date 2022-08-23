// Copyright (c) 2022 Jaskaran Veer Singh
// MIT License

#include<stdlib.h>
#include"config.h"

config* init_config() {
    config* cfg = malloc(sizeof(config));

    cfg->manpager.height = DEFAULT_MANPAGER_HEIGHT;
    cfg->manpager.width = DEFAULT_MANPAGER_WIDTH;
    cfg->manpager.starty = DEFAULT_MANPAGER_STARTY;
    cfg->manpager.startx = DEFAULT_MANPAGER_STARTX;

    cfg->mantree.height = DEFAULT_MANTREE_HEIGHT;
    cfg->mantree.width = DEFAULT_MANTREE_WIDTH;
    cfg->mantree.starty = DEFAULT_MANTREE_STARTY;
    cfg->mantree.startx = DEFAULT_MANTREE_STARTX;

    cfg->manbar.height = DEFAULT_MANBAR_HEIGHT;
    cfg->manbar.width = DEFAULT_MANBAR_WIDTH;
    cfg->manbar.starty = DEFAULT_MANBAR_STARTY;
    cfg->manbar.startx = DEFAULT_MANBAR_STARTX;
    
    return cfg;
}

