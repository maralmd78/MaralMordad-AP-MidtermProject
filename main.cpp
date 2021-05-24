#include <iostream>
#include "cell.h"
#include "maze.h"
#include "ncurses.h"
#include "bfssolver.h"


int main()
{
    


    
    initscr();
    Maze maze{30, 50};
    maze.generate_maze();
    //const Cell cell{3,2};
   // maze.render(&cell);
    
    BFSSolver bfs{maze};
    bfs.render();
    getch();
    endwin();
    // auto path = bfs.bfs_maze_solver();
    // for(auto cell : path)
    //     std::cout << cell->get_row() << "   " << cell->get_column() << std::endl;
    

    // std::cout << bfs.level[&bfs.maze->maze[5][5]] << std::endl;

    
    


    
 


    return 0;
}
