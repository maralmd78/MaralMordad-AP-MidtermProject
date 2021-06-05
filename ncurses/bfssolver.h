#ifndef BFSSOLVER_H
#define BFSSOLVER_H
#include <iostream>
#include <map>
#include <algorithm>
#include <chrono>
#include <thread>
#include "maze.h"
#include "cell.h"

class BFSSolver{
    public:
        BFSSolver(const Maze&);
        std::vector<const Cell*> adjacency(const Cell*);
        std::vector<const Cell*> bfs_maze_solver();
        void render();


    private:
        void execute();
        std::map<const Cell*, int> level;
        std::map<const Cell*, const Cell*> parent;
        const Maze* maze;

};


#endif