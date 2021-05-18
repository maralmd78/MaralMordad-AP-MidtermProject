#ifndef CELL_H
#define CELL_H
#include<iostream>

class Cell {
    public:
        Cell(int r, int c);
        bool check_visited();
        void remove_wall_up();
        void remove_wall_down();
        void remove_wall_right();
        void remove_wall_left();

        

        


        



    private:
        bool is_visited;
        int row, column;
        bool wall_up;
        bool wall_down;
        bool wall_right;
        bool wall_left;
    


};





#endif