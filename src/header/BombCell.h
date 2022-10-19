#pragma once

#include "Cell.h"
#include <iostream>
#include <vector>
using namespace std;

class BombCell : public Cell
{
public:
    BombCell(int _x, int _y, char _value = '*');

    void Pop(vector<vector<Cell *>> *_cells, int _x, int _y) override;
};
