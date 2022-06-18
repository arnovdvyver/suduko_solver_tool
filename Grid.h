#include "Cell.h"

#ifndef GRID_H
#define GRID_H

class Grid
{
    public:
        Grid();
        //Default Constructor

        Grid(int puzzle[][9]);
        //Argument constructor

        int get_filled_cells();
        //Counts and returns filled cells

        void show_grid();
        //Ouput grid to display

        void solver();
        //Solves the puzzle

    private:
        Cell grid[9][9];
        std::vector<Cell*> open_cells;

        //helper functions
        bool open_cross(int n, int row, int col);
        bool open_block(int n, int row, int col);
        int find_bound(int n);
        void find_contenders();
        bool fill_contenders();

        //solution phases
        void contender_phase();
        bool backtracking_phase(int curr_pos);
};

#endif