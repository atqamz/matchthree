#pragma once

#include "NormalCell.h"
#include "BombCell.h"
#include "RocketCell.h"
#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
    Board(int _width, int _height);

    int GetWidth();
    int GetHeight();

    Cell *GetCell(int _x, int _y);
    void SetCell(int _x, int _y, Cell *_cell);

    void InitializeBoard();
    void PrintBoard();

    bool CanPopCell(string *callback, int _x, int _y, char _value);
    void PopCell(int _x, int _y, char _value);

    void UpdateBoard();

private:
    int width;
    int height;
    vector<vector<Cell *>> cells;
};