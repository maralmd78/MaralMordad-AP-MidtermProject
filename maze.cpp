#include "maze.h"

Maze::Maze(int r, int c)
{
    this->row = r;
    this->column = c;
    

    for (int i{}; i < this->row; i++)
    {
        std::vector<Cell> temp;
        for(int j{}; j < this->column; j++)
        {
            temp.push_back(Cell{i, j});
        }
        maze.push_back(temp);
        
    }
    current = &maze[7][7];
    window = newwin(row * 2 + 10, column * 2 + 10, 0, 0);
       
}

void Maze::render()
{
    for (int i{}; i < this->row; i++)
    {
        for(int j{}; j < this->column; j++)
        {
           maze[i][j].show(window);
            
        }   
    }
    refresh();
    wrefresh(window);
    
}

void Maze::check_cell_neighbors()
{
    neighbor.clear();
    if(current->get_row() == 0 && current->get_column() == 0)
    {
        neighbor.push_back(maze[0][1]);
        neighbor.push_back(maze[1][0]);
    }
    else if(current->get_row() == 0 && current->get_column() == column-1)
    {
        neighbor.push_back(maze[0][column-2]);
        neighbor.push_back(maze[1][column-1]);
    }
    else if(current->get_row() == row - 1 && current->get_column() == 0)
    {
        neighbor.push_back(maze[row - 2][0]);
        neighbor.push_back(maze[row - 1][1]);
    }
    else if(current->get_row() == row - 1 && current->get_column() == column - 1 )
    {
        neighbor.push_back(maze[row - 2][column - 1]);
        neighbor.push_back(maze[row - 1][column - 2]);
    }
    else
    {
       // neighbor.push_back([maze[current->get_row()-1][current->get_column()]);
    }

    for(int i{}; i < neighbor.size(); i++)
    {
        neighbor[i].show(window);
    }
    refresh();
    wrefresh(window);
}



