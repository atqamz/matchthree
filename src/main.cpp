#include "header/Board.h"

int main()
{
    srand(time(NULL));

    string callback;

    Board *board = new Board(10, 10);

    board->InitializeBoard();

    while (true)
    {
        system("cls");
        if (callback != "")
        {
            cout << "     " << callback << "\n\n";
            callback = "";
        }

        board->PrintBoard();

        int x, y;
        char value;

        cin >>
            x >> y;

        x = x - 1;
        y = y - 1;

        value = board->GetCell(x, y)->GetValue();

        if (board->CanPopCell(&callback, x, y, value))
        {
            board->PopCell(x, y, value);
        }

        board->UpdateBoard();
    }

    return 0;
}