#include "Cell.h"

int Cell::get_number()
{
    return number;
}

void Cell::set_number(int n)
{
    number = n;
    contenders.clear();
    contender_count = 0;
}

void Cell::set_number_temp(int n)
{
    number = n;
}

int Cell::get_row()
{
    return row_pos;
}

int Cell::get_column()
{
    return col_pos;
}


void Cell::add_contender(int n)
{
    contenders.push_back(n);
    contender_count += 1;
};

void Cell::remove_contender(int n)
{
    int iterator;
    for (int i = 0; i < contender_count; ++i)
    {
        if (contenders.at(i) == n)
        {
            iterator = i;
            contenders.erase(contenders.begin() + i);
            contender_count -= 1;
            break;
        }
    }
}

int Cell::get_contender()
{
    assert(contenders.size() == 1);
    return contenders.at(0);
}

int Cell::get_temp_contender(int i)
{
    return contenders.at(i);
}

int Cell::get_contender_count()
{
    return contender_count;
}




