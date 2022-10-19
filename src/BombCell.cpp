#include "header/BombCell.h"

BombCell::BombCell(int _x, int _y, char _value) : Cell(_x, _y, _value){};

void BombCell::Pop(vector<vector<Cell *>> *_cells, int _x, int _y)
{
    _cells->at(_x).at(_y)->SetValue(' ');

    if (_x > 0)
        _cells->at(_x - 1).at(_y)->SetValue(' ');
    if (_x < _cells->size() - 1)
        _cells->at(_x + 1).at(_y)->SetValue(' ');
    if (_y > 0)
        _cells->at(_x).at(_y - 1)->SetValue(' ');
    if (_y < _cells->at(0).size() - 1)
        _cells->at(_x).at(_y + 1)->SetValue(' ');
    if (_x > 0 && _y > 0)
        _cells->at(_x - 1).at(_y - 1)->SetValue(' ');
    if (_x > 0 && _y < _cells->at(0).size() - 1)
        _cells->at(_x - 1).at(_y + 1)->SetValue(' ');
    if (_x < _cells->size() - 1 && _y > 0)
        _cells->at(_x + 1).at(_y - 1)->SetValue(' ');
    if (_x < _cells->size() - 1 && _y < _cells->at(0).size() - 1)
        _cells->at(_x + 1).at(_y + 1)->SetValue(' ');
};