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
    cell_button = new QPushButton;
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
    cell_button = new QPushButton;

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
    cell_button = new QPushButton;

}

Cell::Cell()
{
    cell_button = new QPushButton;

}

bool Cell::check_visited() const
{
    return this->is_visited;
}

void Cell::remove_wall_up()
{
    this->wall_up = false;
}

void Cell::remove_wall_down()
{
    this->wall_down = false;
}

void Cell::remove_wall_left()
{
    this->wall_left = false;
}

void Cell::remove_wall_right()
{
    this->wall_right = false;
}
bool Cell::check_wall_up() const
{
    return this->wall_up;
}
bool Cell::check_wall_down() const
{
    return this->wall_down;
}
bool Cell::check_wall_left() const
{
    return this->wall_left;
}
bool Cell::check_wall_right() const
{
    return this->wall_right;
}

void Cell::set_visited(bool v)
{
    is_visited = v;
}

int Cell::get_column() const
{
    return this->column;
}

int Cell::get_row() const
{
    return this->row;
}

QPushButton* Cell::get_widget() const
{
    cell_button->setText("");
    cell_button->setDisabled(true);
    std::string wall = "5px solid #ff0000;";
    std::string wallTop = "border-top:" + wall;
    std::string wallBottom = "border-bottom:" + wall;
    std::string wallLeft = "border-left:" + wall;
    std::string wallRight = "border-right:" + wall;
    std::string styleSheet = "";

    if(this->check_wall_up())
        styleSheet += wallTop;
    else
        styleSheet += "border-top:5px solid #ffffff;";
    if(this->check_wall_down())
        styleSheet += wallBottom;
    if(this->check_wall_left())
        styleSheet += wallLeft;
    if(this->check_wall_right())
        styleSheet += wallRight;

    cell_button->setStyleSheet(QString::fromStdString(styleSheet));
    return cell_button;

}
