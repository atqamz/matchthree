#pragma once

#include "Cell.h"
#include <iostream>

class NormalCell : public Cell
{
public:
    NormalCell();
    NormalCell(char _value);

    char GetValue();
    void SetValue(char _value);
};