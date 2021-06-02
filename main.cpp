#include <iostream>
#include "cell.h"
#include "maze.h"
#include "ncurses.h"
#include "bfssolver.h"
#include "dfssolver.h"


int main()
{
    initscr();
    Maze maze{10, 10};
    maze.generate_maze();
    //const Cell cell{3,2};
   // maze.render(&cell);
    
    BFSSolver bfs{maze};
    DFSSolver dfs{maze};
    // bfs.render();
    dfs.dfs_solver();
    getch();
    endwin();
    // auto path = bfs.bfs_maze_solver();
    // for(auto cell : path)
    //     std::cout << cell->get_row() << "   " << cell->get_column() << std::endl;
    

    // std::cout << bfs.level[&bfs.maze->maze[5][5]] << std::endl;

    
    


    
 


    return 0;
}
