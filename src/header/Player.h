#pragma once

#include <iostream>
using namespace std;

class Player
{
public:
    Player(string _name);
    string GetName();
    int GetHealth();
    int GetScore();
    void ReduceHealth();
    void IncrementScore();

private:
    string name;
    int health;
    int score;
};
