#include "Player.hpp"

Player::Player(/* args */)
{
}

Player::~Player()
{
}

string Player::get_name()
{
    return name;
}

ROLE Player::get_role()
{
    return role;
}

double Player::get_score()
{
    return score;
}

Player *Player::clone()
{
    return new Player(*this);
}

bool Player::is_available()
{
    if (red_cards_num == 1 || when_injured > 0 || yellow_cards_num == 3)
        return false;
    return true;
}
