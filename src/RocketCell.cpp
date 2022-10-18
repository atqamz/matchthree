#include "header/RocketCell.h"

RocketCell::RocketCell() : Cell('^'){};

RocketCell::RocketCell(char _value) : Cell(_value)
{
    this->value = _value;
};

char RocketCell::GetValue()
{
    return this->value;
};

void RocketCell::SetValue(char _value)
{
    this->value = _value;
};