#include "cell.h"
Cell::Cell(int r, int c)
{
    this->row = r;
    this->column = c;
    this->is_visited = false;
    this->wall_up = true;
    this->wall_down = true;
    this->wall_left = true;
    this->wall_right = true;
}

bool Cell::check_visited()
{
    return this->is_visited;
}

void Cell::remove_wall_up()
{
    this->wall_up = false;
}

void Cell::remove_wall_down()
{
    this->wall_up = false;
}

void Cell::remove_wall_left()
{
    this->wall_left = false;
}

void Cell::remove_wall_right()
{
    this->wall_right = false;
}