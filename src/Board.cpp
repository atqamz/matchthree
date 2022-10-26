#include "header/Board.h"

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

vector<vector<Cell *>> *Board::GetCells()
{
    return &this->cells;
}

int Board::GetCounter()
{
    return this->counter;
}

void Board::IncrementCounter()
{
    this->counter++;
}

void Board::ResetCounter()
{
    this->counter = 0;
}

void Board::InitializeBoard()
{
    for (int i = 0; i < this->width; i++)
    {
        vector<Cell *> row;
        for (int j = 0; j < this->height; j++)
        {
            if (rand() % 50 == 0)
            {
                row.push_back(new RocketCell(i, j));
            }
            else if (rand() % 50 == 0)
            {
                row.push_back(new BombCell(i, j));
            }
            else
            {
                row.push_back(new NormalCell(i, j));
            }
        }
        cells.push_back(row);
    }
}

void Board::PrintBoard()
{
    cout << "      01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10   X\n\n";

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
    cout << "  Y" << endl;
}

bool Board::CheckSameCell(int _x, int _y, char _value)
{
    if (_x < 0 || _x >= GetWidth() || _y < 0 || _y >= GetHeight())
        return false;

    char value = GetCell(_x, _y)->GetValue();
    if (value == ' ')
        return false;
    else if (value != _value)
        return false;
    else
    {
        if (GetCounter() >= 3)
            return true;
        else
            IncrementCounter();
    }

    return CheckSameCell(_x + 1, _y, _value) || CheckSameCell(_x - 1, _y, _value) || CheckSameCell(_x, _y + 1, _value) || CheckSameCell(_x, _y - 1, _value);
}

bool Board::CanPopCell(string *callback, int _x, int _y, char _value)
{
    if (GetCell(_x, _y)->GetValue() == ' ')
    {
        *callback = "Cell is empty";

        return false;
    }

    if (!CheckSameCell(_x, _y, _value))
    {
        *callback = "No same cell";

        return false;
    }

    ResetCounter();
    return true;
}

void Board::PopCell(Player *_player, int _x, int _y, char _value)
{
    if (_x < 0 || _x >= GetWidth() || _y < 0 || _y >= GetHeight())
        return;

    char value = GetCell(_x, _y)->GetValue();
    if (value == ' ')
        return;
    else if (value != _value)
    {
        // there is two way to approach this, check the latest is a bomb or rocket or using counter

        // this method is using lastest cell
        if (value == '*')
            GetCell(_x, _y)->Pop(GetCells(), _x, _y, _player);
        else if (value == '^')
            GetCell(_x, _y)->Pop(GetCells(), _x, _y, _player);

        // and this method is using counter
        if (GetCounter() >= 5)
        {
            SetCell(_x, _y, new BombCell(_x, _y));
            GetCell(_x, _y)->Pop(GetCells(), _x, _y, _player);
        }
        else if (GetCounter() >= 6)
        {
            SetCell(_x, _y, new RocketCell(_x, _y));
            GetCell(_x, _y)->Pop(GetCells(), _x, _y, _player);
        }

        ResetCounter();
        return;
    }
    else
    {
        GetCell(_x, _y)->Pop(GetCells(), _x, _y, _player);
        IncrementCounter();
    }

    PopCell(_player, _x - 1, _y, _value);
    PopCell(_player, _x + 1, _y, _value);
    PopCell(_player, _x, _y - 1, _value);
    PopCell(_player, _x, _y + 1, _value);
}

void Board::UpdateBoard()
{
    bool isEmpty = true;
    while (isEmpty)
    {
        // add new cell to the top of the board
        for (int i = 0; i < GetWidth(); i++)
        {
            if (GetCell(0, i)->GetValue() == ' ')
            {
                if (rand() % 50 == 0)
                {
                    SetCell(0, i, new RocketCell(0, i));
                }
                else if (rand() % 50 == 0)
                {
                    SetCell(0, i, new BombCell(0, i));
                }
                else
                {
                    SetCell(0, i, new NormalCell(0, i));
                }
            }
        }

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
                            SetCell(k - 1, j, new Cell(k - 1, j));
                        }
                    }
                }
            }
        }

        // check if there is any empty cell
        for (int j = 0; j < GetHeight(); j++)
        {
            if (GetCell(0, j)->GetValue() == ' ')
            {
                isEmpty = true;
                break;
            }
            else
            {
                isEmpty = false;
            }
        }
    }
}