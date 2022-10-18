#include "header/BombCell.h"

BombCell::BombCell() : Cell('*'){};

BombCell::BombCell(char _value) : Cell(_value)
{
    this->value = _value;
};

char BombCell::GetValue()
{
    return this->value;
};

void BombCell::SetValue(char _value)
{
    this->value = _value;
};

// void BombCell::Pop(Board *_board, int _x, int _y)
// {
//     _board->SetCell(_x, _y, new Cell(' '));
//     _board->SetCell(_x + 1, _y, new Cell(' '));
//     _board->SetCell(_x - 1, _y, new Cell(' '));
//     _board->SetCell(_x, _y + 1, new Cell(' '));
//     _board->SetCell(_x, _y - 1, new Cell(' '));
// };