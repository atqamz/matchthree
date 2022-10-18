#include "header/Cell.h"

using namespace std;

Cell::Cell(char _value)
{
    this->value = _value;
};

char Cell::GetValue()
{
    return this->value;
};

void Cell::SetValue(char _value)
{
    this->value = _value;
};

void Cell::Pop()
{
    SetValue(' ');
};