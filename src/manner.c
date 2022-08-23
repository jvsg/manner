// Copyright (c) 2022 Jaskaran Veer Singh
// MIT License

#include<ncurses.h>
#include<stdlib.h>

#include"windows.h"
#include"manner.h"
#include"config.h"

void cleanup(config* cfg, WINDOW** windows, int n)
{
	for(int i = 0; i < n; i++)
		destroy_win(windows[i]);

	free(windows);
	free(cfg);
	endwin();
}

int main()
{
	config* cfg = init_config();
	window *manpager, *mantree, *manbar;
	window** windows = malloc(sizeof(window*) * 2);

	initscr();

	manpager = create_win(stdscr, &cfg->manpager, TYPE_MANPAGER);
	mantree = create_win(stdscr, &cfg->mantree, TYPE_MANTREE);
	manbar = create_win(stdscr, &cfg->manbar, TYPE_MANBAR);

	windows[0] = manpager;
	windows[1] = mantree;
	windows[2] = manbar;

	wrefresh(manpager->win);	
	wrefresh(mantree->win);	
	wrefresh(manbar->win);
	
	getch();

	cleanup(cfg, windows, 3);
}
