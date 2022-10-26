#include "header/Board.h"
#include "header/Player.h"

int main()
{
    srand(time(NULL));

    cout << "Welcome to Match Tree!" << endl;
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    Player *player = new Player(name);

    cout << "Hello, " << player->GetName() << "!" << endl;
    cout << "Are you ready to play? (y/n): ";
    char answer;
    cin >> answer;

    if (answer != 'y')
    {
        cout << "Goodbye!" << endl;
        cin.get();
        return 0;
    }

    string callback;
    Board *board = new Board(10, 10);
    board->InitializeBoard();

    while (true)
    {
        system("cls");

        cout << player->GetName() << endl;
        cout << "Score\t: " << player->GetScore() << endl;
        cout << "Health\t: " << player->GetHealth() << endl;

        cout << endl;

        if (callback != "")
        {
            cout << "     " << callback << "\n\n";
            callback = "";
        }

        board->PrintBoard();

        int x, y;
        char value;

        cout << "\nEnter coordinate (Y X): ";
        cin >>
            x >> y;

        x = x - 1;
        y = y - 1;

        value = board->GetCell(x, y)->GetValue();

        if (board->CanPopCell(&callback, x, y, value))
            board->PopCell(player, x, y, value);
        else
            player->ReduceHealth();

        if (player->GetHealth() <= 0)
        {
            system("cls");

            cout << "Game Over!" << endl;
            cout << "Your score is " << player->GetScore() << endl;

            cin.get();
            return 0;
        }

        board->UpdateBoard();
    }

    return 0;
}