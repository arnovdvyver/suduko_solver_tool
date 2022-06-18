#include <iostream>
#include "Grid.h"

using namespace std;

int main()
{
    //example of using solver

    int test_puzzle[9][9] = 
    {
        {0, 0, 5, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 1, 8, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 4, 1, 2, 0},

        {0, 0, 9, 0, 0, 0, 0, 0, 2},
        {0, 4, 0, 3, 0, 0, 5, 0, 0},
        {5, 0, 6, 0, 0, 7, 0, 8, 0},

        {6, 0, 0, 0, 9, 0, 0, 0, 1},
        {0, 2, 0, 0, 0, 5, 0, 0, 0},
        {0, 9, 0, 6, 0, 0, 7, 0, 0}
    };

    Grid my_grid(test_puzzle);
    my_grid.solver();
    my_grid.show_grid();
    cout << my_grid.get_filled_cells() << endl;

    return 0;
}