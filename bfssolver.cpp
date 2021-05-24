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

void BFSSolver::execute()
{
    const Cell* start = &maze->maze[0][0];
    std::vector<const Cell*> frontier;
    level[start] = 0;
    parent[start] = nullptr;
    int i = 1;
    frontier.push_back(start);
    while(!frontier.empty())
    {
        std::vector<const Cell*> next;
        for(auto u : frontier)
        {
            for(auto v: adjacency(u))
            {
                if(level.find(v) == level.end())
                {
                    level[v] = i;
                    parent[v] = u;
                    next.push_back(v);
                }
            }
        }
        frontier.clear();
        frontier = next;
        i += 1;
    }


}

std::vector<const Cell*> BFSSolver::bfs_maze_solver()
{
    execute();
    const Cell* end = &maze->maze[maze->maze.size() - 1 ][maze->maze[0].size() - 1 ];
    std::vector<const Cell*> solve_path;
    solve_path.push_back(end);
    while(parent[end] != nullptr)
    {
        end = parent[end];
        solve_path.push_back(end);

    }

    std::reverse(solve_path.begin(), solve_path.end());
    return solve_path;


}

void BFSSolver::render()
{
    auto path = bfs_maze_solver();
    for(auto cell : path){
        this->maze->render(cell);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}