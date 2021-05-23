#ifndef CELL_H
#define CELL_H
#include<iostream>
#include "ncurses.h"

class Cell {
    public:
        Cell(int r, int c);
        Cell(const Cell&);
        Cell(Cell&& c);
        Cell() = default;
        bool check_visited() const;
        void remove_wall_up();
        void remove_wall_down();
        void remove_wall_right();
        void remove_wall_left();
        bool check_wall_up() const;
        bool check_wall_down() const;
        bool check_wall_left() const;
        bool check_wall_right() const;
        void set_visited(bool);
        int get_row() const;
        int get_column() const;
        void show(WINDOW* win);
        
        
   

    private:
        bool is_visited;
        int row, column;
        bool wall_up;
        bool wall_down;
        bool wall_right;
        bool wall_left;
    


};





#endif