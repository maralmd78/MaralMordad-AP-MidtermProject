#include "bfssolver.h"

BFSSolver::BFSSolver(const Maze& maze)
{
   this->maze = &maze; 
}

std::vector<const Cell*> BFSSolver::adjacency(const Cell* cell)
{
    std::vector<const Cell*> adj;
    if(!cell->check_wall_up())
        adj.push_back(&(maze->maze[cell->get_row() - 1][cell->get_column()]));

    if(!cell->check_wall_down())
        adj.push_back(&(maze->maze[cell->get_row() + 1][cell->get_column()]));
    
    if(!cell->check_wall_left())
        adj.push_back(&(maze->maze[cell->get_row()][cell->get_column() - 1]));
    
    if(!cell->check_wall_right())
        adj.push_back(&(maze->maze[cell->get_row()][cell->get_column() + 1]));

    
    return adj;

}