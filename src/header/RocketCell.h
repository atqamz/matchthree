#pragma once

#include "Cell.h"
#include <iostream>

class RocketCell : public Cell
{
public:
    RocketCell();
    RocketCell(char _value);

    char GetValue();
    void SetValue(char _value);
};