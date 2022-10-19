#include "header/RocketCell.h"

RocketCell::RocketCell(int _x, int _y, char _value) : Cell(_x, _y, _value){};

void RocketCell::Pop(vector<vector<Cell *>> *_cells, int _x, int _y)
{
    if (rand() % 2 == 0)
    {
        // pop horizontal
        for (int i = 0; i < _cells->size(); i++)
        {
            _cells->at(i).at(_y)->SetValue(' ');
        }
    }
    else
    {
        // pop vertical
        for (int i = 0; i < _cells->at(0).size(); i++)
        {
            _cells->at(_x).at(i)->SetValue(' ');
        }
    }
};