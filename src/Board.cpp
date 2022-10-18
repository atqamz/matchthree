#include "header/Board.h"

using namespace std;

Board::Board(int _width, int _height)
{
    this->width = _width;
    this->height = _height;
}

int Board::GetWidth()
{
    return this->width;
}

int Board::GetHeight()
{
    return this->height;
}

Cell *Board::GetCell(int _x, int _y)
{
    return this->cells[_x][_y];
}

void Board::SetCell(int _x, int _y, Cell *_cell)
{
    cells[_x][_y] = _cell;
}

void Board::InitializeBoard()
{
    for (int i = 0; i < this->width; i++)
    {
        vector<Cell *> row;
        for (int j = 0; j < this->height; j++)
        {
            if (rand() % 10 == 0)
            {
                row.push_back(new RocketCell());
            }
            else if (rand() % 10 == 0)
            {
                row.push_back(new BombCell());
            }
            else
            {
                int randomNormal = rand() % 3;
                if (randomNormal == 0)
                    row.push_back(new NormalCell('A'));
                else if (randomNormal == 1)
                    row.push_back(new NormalCell('S'));
                else
                    row.push_back(new NormalCell('U'));
            }
        }
        cells.push_back(row);
    }
}

void Board::PrintBoard()
{
    cout << "      01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10\n\n";

    for (int i = 0; i < GetWidth(); i++)
    {
        int row = i + 1;
        if (row < 10)
            cout << " 0" << row << "  ";
        else
            cout << " " << row << "  ";

        cout << " ";
        for (int j = 0; j < GetHeight(); j++)
        {
            if (j != 10 - 1)
                cout << " " << GetCell(i, j)->GetValue() << " | ";
            else
                cout << " " << GetCell(i, j)->GetValue();
        }
        cout << " ";

        cout << endl;
        if (i != GetWidth() - 1)
        {
            cout << "     ";
            for (int j = 0; j < GetHeight(); j++)
            {
                if (j != GetHeight() - 1)
                    cout << "----+";
                else
                    cout << "----";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::CanPopCell(string *callback, int _x, int _y, char _value)
{
    // if ((_x - 1 >= 0 &&
    //      GetCell(_x - 1, _y)->GetValue() != _value) ||
    //     (_x + 1 < GetWidth() &&
    //      GetCell(_x + 1, _y)->GetValue() != _value) ||
    //     (_y - 1 >= 0 &&
    //      GetCell(_x, _y - 1)->GetValue() != _value) ||
    //     (_y + 1 < GetHeight() &&
    //      GetCell(_x, _y + 1)->GetValue() != _value))
    // {
    //     *callback = "No adjacent cell with the same value";
    //     return false;
    // }

    if (GetCell(_x, _y)->GetValue() == ' ')
    {
        *callback = "Cell is empty";
        return false;
    }

    return true;
}

void Board::PopCell(int _x, int _y, char _value)
{
    if (_x < 0 || _x >= GetWidth() || _y < 0 || _y >= GetHeight())
        return;

    if (GetCell(_x, _y)->GetValue() != _value)
        return;

    GetCell(_x, _y)->Pop();

    PopCell(_x - 1, _y, _value);
    PopCell(_x + 1, _y, _value);
    PopCell(_x, _y - 1, _value);
    PopCell(_x, _y + 1, _value);
}

void Board::UpdateBoard()
{
    // relocate all empty cells with the cells above them
    for (int i = 0; i < GetWidth(); i++)
    {
        for (int j = 0; j < GetHeight(); j++)
        {
            if (GetCell(i, j)->GetValue() == ' ')
            {
                for (int k = i; k >= 0; k--)
                {
                    if (k != 0)
                    {
                        SetCell(k, j, GetCell(k - 1, j));
                        SetCell(k - 1, j, new NormalCell(' '));
                    }
                }
            }
        }
    }
}