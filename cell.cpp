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

Cell::Cell(const Cell& c)
{
    this->row = c.row;
    this->column = c.column;
    this->is_visited = c.is_visited;
    this->wall_up = c.wall_up;
    this->wall_down = c.wall_down;
    this->wall_left = c.wall_left;
    this->wall_right = c.wall_right;
}



Cell::Cell(Cell&& c)
{
    this->row = c.row;
    this->column = c.column;
    this->is_visited = c.is_visited;
    this->wall_up = c.wall_up;
    this->wall_down = c.wall_down;
    this->wall_left = c.wall_left;
    this->wall_right = c.wall_right;
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
bool Cell::check_wall_up()
{
    return this->wall_up;
}
bool Cell::check_wall_down()
{
    return this->wall_down;
}
bool Cell::check_wall_left()
{
    return this->wall_left;
}
bool Cell::check_wall_right()
{
    return this->wall_right;
}

void Cell::set_visited(bool v)
{
    is_visited = v;
}

int Cell::get_column()
{
    return this->column;
}

int Cell::get_row()
{
    return this->row;
}



void Cell::show(WINDOW* win) {
  if (wall_up) {
    wmove(win, row, (column + 2) + (column));
    whline(win, '_', 1);
  }

  if (wall_right) {
    wmove(win, row + 1, (column + 3) + (column));
    wvline(win, '|', 1);
  }

  if (wall_down) {
    wmove(win, row + 1, (column + 2) + (column));
    whline(win, '_', 1);
  }

  if (wall_left) {
    wmove(win, row + 1, (column + 1) + (column));
    wvline(win, '|', 1);
  }
}
