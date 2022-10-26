#include "header/Player.h"

Player::Player(string _name)
{
    this->name = _name;
    this->health = 3;
    this->score = 0;
}

string Player::GetName()
{
    return this->name;
}

int Player::GetHealth()
{
    return this->health;
}

int Player::GetScore()
{
    return this->score;
}

void Player::ReduceHealth()
{
    this->health--;
}

void Player::IncrementScore()
{
    this->score++;
}