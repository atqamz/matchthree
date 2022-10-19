#include "header/NormalCell.h"

NormalCell::NormalCell(int _x, int _y) : Cell(_x, _y)
{
    int randomNormal = rand() % 3;
    if (randomNormal == 0)
        this->value = 'A';
    else if (randomNormal == 1)
        this->value = 'S';
    else
        this->value = 'U';
};