#include "header/NormalCell.h"

NormalCell::NormalCell() : Cell(' '){};

NormalCell::NormalCell(char _value) : Cell(_value)
{
    this->value = _value;
};

char NormalCell::GetValue()
{
    return this->value;
};

void NormalCell::SetValue(char _value)
{
    this->value = _value;
};