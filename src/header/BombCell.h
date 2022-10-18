#pragma once

#include "Cell.h"
#include <iostream>

class BombCell : public Cell
{
public:
    BombCell();
    BombCell(char _value);

    char GetValue();
    void SetValue(char _value);
};
