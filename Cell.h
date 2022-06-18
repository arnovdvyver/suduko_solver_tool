#include <iostream>
#include <vector>
#include <cassert>

#ifndef CELL_H
#define CELL_H

class Cell 
{
    public:
        Cell() : number(0), contender_count(0) {}
        //Default Constructor

        Cell(int row, int col, int num) : row_pos(row), col_pos(col), number(num), contender_count(0) {}
        //Argument Constructor

        int get_number();
        //returns main number value of cell

        void set_number(int n);
        //sets main number value of cell

        void set_number_temp(int n);
        //Sets main number value of cell without clearing contender list

        int get_row();
        //returns row_pos of cell

        int get_column();
        //returns col_pos of cell

        void add_contender(int n);
        //add argument to contender vector of Cell

        void remove_contender(int n);
        //remove argument to contender vector of Cell

        int get_contender();
        //returns contender if only one is available

        int get_temp_contender(int i);
        //returns contender of spesific position

        int get_contender_count();
        //returns number of contenders of cell

    private:
        int number;
        int row_pos;
        int col_pos;
        std::vector<int> contenders;
        int contender_count;
};


#endif