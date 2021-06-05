#ifndef MAZESOLVER_H
#define MAZESOLVER_H
#include "maze.h"
#include "cell.h"
#include <map>
#include <vector>

class MazeSolver
{
    public:
        MazeSolver(const Maze& maze);
        std::vector<const Cell*> adjacency(const Cell*);
        //BFS
        void BFS_algorithm();
        std::vector<const Cell*> BFS_path();
        //DFS
        void DFS_algorithm(const Cell* cell);
        std::vector<const Cell*> DFS_path();





    private:
        const Maze* maze;
        const Cell* start;
        const Cell* end;
        //BFS
        std::map<const Cell*, int> level;
        std::map<const Cell*, const Cell*> parent;
        //DFS
        std::vector<const Cell*> visit;
        std::vector<std::vector<bool>> marked;

};

#endif // MAZESOLVER_H
