#ifndef DFSSOLVER_H
#define DFSSOLVER_H
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <chrono>
#include <thread>
#include "cell.h"
#include "maze.h"

class DFSSolver{
    public:
        DFSSolver(const Maze&);
        std::vector<const Cell*> adjacency(const Cell*);
        void dfs(const Cell*);
        void dfs_solver();
        

    private:
        std::vector<const Cell*> visit;
        std::vector<std::vector<bool>> marked;
        const Maze* maze;
        const Cell* end;
        const Cell* start;
        std::vector<const Cell*> path;





        
};



#endif