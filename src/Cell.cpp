#include "header/Cell.h"

Cell::Cell(int _x, int _y, char _value)
{
    this->x = _x;
    this->y = _y;
    this->value = _value;
};

int Cell::GetX()
{
    return this->x;
}

void Cell::SetX(int _value)
{
    this->x = _value;
}

int Cell::GetY()
{
    return this->y;
}

void Cell::SetY(int _value)
{
    this->y = _value;
}

char Cell::GetValue()
{
    return this->value;
};

void Cell::SetValue(char _value)
{
    this->value = _value;
};

void Cell::Pop(vector<vector<Cell *>> *_cells, int _x, int _y)
{
    SetValue(' ');
};