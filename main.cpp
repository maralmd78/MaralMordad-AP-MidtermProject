#include <iostream>
#include <string>
#include "cell.h"
#include "maze.h"
#include "ncurses.h"
#include "bfssolver.h"
#include "dfssolver.h"


int main()
{
    int row, column;
    std::string algorithm_name; 
    std::cout << "please enter row and column of maze" << std::endl;
    std::cin >> row >> column;
    std::cout << "please select an algorithm between BFS and DFS" << std::endl;
    std::cin >> algorithm_name;
    initscr();
    Maze maze{row, column};
    maze.generate_maze();
    if(algorithm_name == "BFS")
    {
        BFSSolver bfs{maze};
        bfs.render();
    }
    else if(algorithm_name == "DFS")
    {
        DFSSolver dfs{maze};
        dfs.dfs_solver();

    }
    else{
        std::cout << "invalid!" << std::endl;
    }
 
    getch();
    endwin();
    
    return 0;
}
