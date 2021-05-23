#ifndef BFSSOLVER_H
#define BFSSOLVER_H
#include <iostream>
#include <map>
#include "maze.h"
#include "cell.h"

class BFSSolver{
    public:
        BFSSolver(const Maze&);
        std::vector<const Cell*> adjacency(const Cell*);




    private:
        std::map<Cell*, int> level;
        std::map<Cell*, Cell*> parent;
        const Maze* maze;


    


};






#endif