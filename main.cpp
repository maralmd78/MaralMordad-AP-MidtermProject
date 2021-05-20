#include <iostream>
#include "cell.h"
#include "maze.h"
#include "ncurses.h"


int main()
{
    // initscr();
    // WINDOW *win;
    // win = newwin(1 * 2 + 10, 1 * 2 + 10, 0, 0);
    // wmove(win, 0, 0);
    // whline(win, '_', 1);
    // wmove(win, 1, 0);
    // whline(win, '_', 1);
    // wmove(win, 5, 5);
    // whline(win, '_', 1);
    // refresh();
    // wrefresh(win);
    // getch();
    // endwin();
    //


    // initscr();
    // Maze maze{8, 8};
    // maze.render();
    // getch();
    // endwin();
    initscr();
    Maze maze{8, 8};
    maze.check_cell_neighbors();
    getch();
    endwin();

    
 


    return 0;
}
