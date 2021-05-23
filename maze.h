#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>     
#include <time.h> 
#include "cell.h"
#include "ncurses.h"
using Matrix = std::vector<std::vector<Cell>>;

class Maze{
    public:
    Maze(int r,int c);
    void check_cell_neighbors(); 
    void render();
    Cell* find_nextCell();
    void remove_wall(Cell*, Cell*);
    void generate_maze();
    Matrix maze;

    

    private:
    int row, column;
    WINDOW *window;
    std::vector<Cell*> neighbor;
    Cell* current;
    std::stack<Cell*> path;
    
};



#endif