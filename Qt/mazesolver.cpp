#include "mazesolver.h"

MazeSolver::MazeSolver(const Maze& maze)
{
    this->maze = &maze;
    start = &this->maze->maze[0][0];
    end = &this->maze->maze[this->maze->row - 1][this->maze->column - 1];

    //DFS
    for(int i{}; i < maze.row; i++)
    {
        std::vector<bool> temp;
        for(int j{}; j < maze.column; j++)
            temp.push_back(false);

        marked.push_back(temp);
    }


}

std::vector<const Cell*> MazeSolver::adjacency(const Cell* cell)
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

void MazeSolver::BFS_algorithm()
{
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

std::vector<const Cell*> MazeSolver::BFS_path()
{
    BFS_algorithm();
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


void MazeSolver::DFS_algorithm(const Cell* cell)
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
            DFS_algorithm(c);
            visit.push_back(cell);

        }
    }
}

std::vector<const Cell*> MazeSolver::DFS_path()
{
    std::vector<const Cell*> solve_path;
    DFS_algorithm(start);
    for(auto cell : visit){
        solve_path.push_back(cell);
        if(cell == end)
            break;

    }

    return solve_path;
}






