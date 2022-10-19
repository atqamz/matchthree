#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Cell
{
public:
    Cell(int _x, int _y, char _value = ' ');

    int GetX();
    void SetX(int _value);
    int GetY();
    void SetY(int _value);
    char GetValue();
    void SetValue(char _value);

    virtual void Pop(vector<vector<Cell *>> *_cells, int _x, int _y);

protected:
    int x;
    int y;
    char value;
};