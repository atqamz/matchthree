#pragma once

#include "Player.h"
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

    vector<vector<Cell *>> *GetCells();

    int GetCounter();
    void IncrementCounter();
    void ResetCounter();

    void InitializeBoard();
    void PrintBoard();

    bool CheckSameCell(int _x, int _y, char _value);
    bool CanPopCell(string *callback, int _x, int _y, char _value);
    void PopCell(Player *_player, int _x, int _y, char _value);

    void UpdateBoard();

private:
    int width;
    int height;
    vector<vector<Cell *>> cells;

    int counter;
};