#include "dfssolver.h"

DFSSolver::DFSSolver(const Maze& maze)
{
    this->maze = &maze;

    for(int i{}; i < maze.row; i++)
    {
        std::vector<bool> temp;
        for(int j{}; j < maze.column; j++)
            temp.push_back(false);

        marked.push_back(temp);
    }

    start = &this->maze->maze[0][0];
    end = &this->maze->maze[this->maze->maze.size() - 1 ][this->maze->maze[0].size() - 1 ];
}

std::vector<const Cell*> DFSSolver::adjacency(const Cell* cell)
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

void DFSSolver::dfs(const Cell* cell)
{
    visit.push_back(cell);
    marked[cell->get_row()][cell->get_column()] = true;
    if(cell == end)
        return;
    std::vector<const Cell*> neighbors = adjacency(cell);
    for(const auto  c : neighbors)
    {
        
        if( marked[c->get_row()][c->get_column()] == false)
        {
            dfs(c);
            visit.push_back(cell);

        }
    }
}

void DFSSolver::dfs_solver()
{
    dfs(start);
    for(auto cell : visit){
        this->maze->render(cell);
        if(cell == end)
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

    }
}



