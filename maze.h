#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include <stack>
#include "cell.h"
#include "ncurses.h"
using Matrix = std::vector<std::vector<Cell>>;
class Maze{
    public:
    Maze(int r,int c);
    void check_cell_neighbors(); 
    void render();
    std::vector<Cell> neighbor;
    Cell* current;

    private:
    int row, column;
    WINDOW *window;
    Matrix maze;
    
    
};



#endif