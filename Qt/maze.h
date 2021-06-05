#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include "cell.h"
using Matrix = std::vector<std::vector<Cell>>;

class Maze{
    public:
        Maze(int r,int c);
        void check_cell_neighbors();
        QWidget* render(const Cell*) const;
        Cell* find_nextCell();
        void remove_wall(Cell*, Cell*);
        void generate_maze();
        Matrix maze;
        int row, column;



    private:
        std::vector<Cell*> neighbor;
        Cell* current;
        std::stack<Cell*> path;
        QTableWidget* maze_widget;



};

#endif // MAZE_H
