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
    current = &maze[0][0];
    maze_widget = new QTableWidget;
    maze_widget->verticalHeader()->setVisible(false);
    maze_widget->horizontalHeader()->setVisible(false);
    maze_widget->setRowCount(r);
    maze_widget->setColumnCount(c);
    maze_widget->setContentsMargins(0, 0, 0, 0);
    maze_widget->setShowGrid(false);
    maze_widget->resizeColumnsToContents();
    maze_widget->resizeRowsToContents();
    maze_widget->setFocusPolicy(Qt::NoFocus);

    srand (time(NULL));

}

QWidget* Maze::render(const Cell* cell) const
{
    for (int i{}; i < this->row; i++)
    {
        for(int j{}; j < this->column; j++)
        {
            if(&maze[i][j] == cell)
                maze_widget->setCellWidget(i, j, maze[i][j].get_widget(true));
            else
                maze_widget->setCellWidget(i, j, maze[i][j].get_widget(false));

        }
    }
    return maze_widget;
}

void Maze::check_cell_neighbors()
{
    neighbor.clear();
    if(current->get_row() == 0 && current->get_column() == 0 )
    {

        if(!maze[0][1].check_visited()) neighbor.push_back(&maze[0][1]);
        if(!maze[1][0].check_visited()) neighbor.push_back(&maze[1][0]);
    }
    else if(current->get_row() == 0 && current->get_column() == column-1)
    {
        if(!maze[0][column - 2].check_visited()) neighbor.push_back(&maze[0][column-2]);
        if(!maze[1][column - 1].check_visited()) neighbor.push_back(&maze[1][column-1]);
    }
    else if(current->get_row() == row - 1 && current->get_column() == 0 )
    {
        if(!maze[row - 2][0].check_visited()) neighbor.push_back(&maze[row - 2][0]);
        if(!maze[row - 1][1].check_visited()) neighbor.push_back(&maze[row - 1][1]);
    }
    else if(current->get_row() == row - 1 && current->get_column() == column - 1 )
    {
        if(!maze[row - 2][column - 1].check_visited()) neighbor.push_back(&maze[row - 2][column - 1]);
        if(!maze[row - 1][column - 2].check_visited()) neighbor.push_back(&maze[row - 1][column - 2]);
    }
    else if(current->get_row() == 0)
    {
        if(!maze[current->get_row()][current->get_column() - 1].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() - 1]);
        if(!maze[current->get_row()][current->get_column() + 1].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() + 1 ]);
        if(!maze[current->get_row() + 1][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() + 1 ][current->get_column()]);
    }
    else if(current->get_row() == row - 1)
    {
        if(!maze[current->get_row() - 1 ][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() - 1 ][current->get_column()]);
        if(!maze[current->get_row()][current->get_column() - 1].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() - 1]);
        if(!maze[current->get_row()][current->get_column() + 1].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() + 1 ]);
    }
    else if(current->get_column() == 0)
    {
        if(!maze[current->get_row() - 1 ][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() - 1 ][current->get_column()]);
        if(!maze[current->get_row()][current->get_column() + 1].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() + 1 ]);
        if(!maze[current->get_row() + 1 ][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() + 1 ][current->get_column()]);
    }
    else if(current->get_column() == column - 1)
    {
        if(!maze[current->get_row() - 1][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() - 1 ][current->get_column()]);
        if(!maze[current->get_row()][current->get_column() - 1].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() - 1]);
        if(!maze[current->get_row() + 1][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() + 1 ][current->get_column()]);

    }
    else
    {
        if(!maze[current->get_row() - 1 ][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() - 1 ][current->get_column()]);
        if(!maze[current->get_row()][current->get_column() - 1 ].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() - 1]);
        if(!maze[current->get_row()][current->get_column() + 1 ].check_visited()) neighbor.push_back(&maze[current->get_row()][current->get_column() + 1 ]);
        if(!maze[current->get_row() + 1][current->get_column()].check_visited()) neighbor.push_back(&maze[current->get_row() + 1 ][current->get_column()]);
    }
}

Cell* Maze::find_nextCell()
{
    if(neighbor.size() == 0)
        return nullptr;
    int temp = rand() % neighbor.size();
    return neighbor[temp];
}

void Maze::remove_wall(Cell* c, Cell* n)
{
    if(c->get_row() == n->get_row() && c->get_column() < n->get_column())
    {
        c->remove_wall_right();
        n->remove_wall_left();
    }
    else if(c->get_row() == n->get_row() && c->get_column() > n->get_column())
    {
        c->remove_wall_left();
        n->remove_wall_right();
    }
    else if(c->get_column() == n->get_column() && c->get_row() < n->get_row())
    {
        c->remove_wall_down();
        n->remove_wall_up();
    }
    else if(c->get_column() == n->get_column() && c->get_row() > n->get_row())
    {
        c->remove_wall_up();
        n->remove_wall_down();
    }
}

void Maze::generate_maze()
{
    while (true) {
        current->set_visited(true);
        check_cell_neighbors();
        Cell* next = find_nextCell();

        if (next != nullptr) {
            next->set_visited(true);
            path.push(current);
            remove_wall(current, next);
            current = next;
        }
        else if (path.size() > 0) {
            current = path.top();
            path.pop();
        }
        else if (path.size() == 0) {
            break;
        }
    }
}









