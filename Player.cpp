#include "Player.hpp"

Player::Player(string _name, ROLE _role)
{
    name = _name;
    role = _role;
    score = 0;
    when_injured = 0;
    yellow_cards_num = 0;
    red_cards_num = 0;
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
