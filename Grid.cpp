#include <iostream>
#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            grid[i][j] = Cell();
}

Grid::Grid(int puzzle[][9])
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            int n = puzzle[i][j];
            grid[i][j] = Cell(i, j, n);

            if (n == 0)
                open_cells.push_back(&(grid[i][j]));
        }
}

int Grid::get_filled_cells()
{
    int count = 0;

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if (grid[i][j].get_number() != 0)
                count += 1;

    return count;
}

void Grid::show_grid()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            std::cout << (grid[i][j]).get_number() << " ";
    std::cout << std::endl;
    }
}

void Grid::solver()
{
    contender_phase();
    backtracking_phase(0);
}


//Private 
//Helper Functions
bool Grid::open_cross(int target, int row, int col)
{
    for (int i = 0; i < 9; ++i)
    {
        int x_axis = (grid[i][col]).get_number();
        int y_axis = (grid[row][i]).get_number();

        if (x_axis == target || y_axis == target)
            return false;
    }
    return true;
};
        
bool Grid::open_block(int target, int row, int col)
{
    int x_bound = find_bound(row);
    int y_bound = find_bound(col);

    for (int i = x_bound; i < (x_bound + 3); ++i)
        for (int j = y_bound; j < (y_bound + 3); ++j)
            if ((grid[i][j]).get_number() == target)
                return false;
    return true;
};

int Grid::find_bound(int n)
{
    return (n / 3) * 3;
};

void Grid::find_contenders()
{
    for (int value = 1; value < 10; ++value)
        for (int i = 0; i < open_cells.size(); ++i)
        {
            int r = open_cells.at(i)->get_row();
            int c = open_cells.at(i)->get_column();

            if (open_block(value, r, c) && open_cross(value, r, c)) //if contender is valid for block, add to Cell's contender vector
                open_cells.at(i)->add_contender(value);
        }
};

bool Grid::fill_contenders()
{
    bool did_set_number = false;

    for (int i = 0; i < open_cells.size(); ++i)
    {
        Cell *main_cell;
        Cell *other_cell;
        main_cell = open_cells.at(i);

        int count = main_cell->get_contender_count();
        if (count == 1)
        {
            //fill single contender
            int n = main_cell->get_contender();
            main_cell->set_number(n);                  //assign only contender as cell's main number                
            open_cells.erase(open_cells.begin() + i);   //remove pointer to cell from open_cell vec
            did_set_number = true;                      //return true since a cell was filled

            //remove contenders from open cells in same block
            int c_row = main_cell->get_row();
            int c_col = main_cell->get_column();

            int r = find_bound(c_row);
            int c = find_bound(c_col);

            for (int row = r; row < (r + 3); ++row)
                for (int col = c; col < (c + 3); ++col)
                {
                    other_cell = &(this->grid[row][col]);

                    if (other_cell->get_number() == 0)
                        other_cell->remove_contender(n);
                }

            //remove contenders from open cells in same cross
            for (int k = 0; k < 9; ++k)
            {
                //iterate throught x_axis cells
                Cell *x = &(grid[c_row][k]);
                int a = x->get_number();

                if (a == 0)
                    x->remove_contender(n);

                //iterate through y_axis cells
                Cell *y = &(grid[k][c_col]);
                int b = x->get_number();

                if (b == 0)
                    y->remove_contender(n);
            }    
        }
    }
    return did_set_number;
};

//Phase functions
void Grid::contender_phase()
{
    find_contenders();
    bool flag = false;

    do
    {
        flag = fill_contenders();
    }
    while (flag == true);
};

bool Grid::backtracking_phase(int curr_pos)
{
    if (get_filled_cells() == 81)
        return true;

    else
    {
        Cell* curr_cell = open_cells.at(curr_pos);
        int ran = curr_cell->get_contender_count();
        for (int i = 0; i < ran; ++i)
        {
            int value = curr_cell->get_temp_contender(i);
            int row = curr_cell->get_row();
            int col = curr_cell->get_column();

            if (open_block(value, row, col) && open_cross(value, row, col))
            {
                curr_cell->set_number_temp(value);
                if (backtracking_phase((curr_pos + 1)))
                    return true;

                curr_cell->set_number_temp(0);
            }
        }
    }
    return false;
};