#include "Player.hpp"

Player::Player(string _name, ROLE _role)
{
    name = _name;
    role = _role;
    score = 0;
    when_injured = 0;
    yellow_cards_num = 0;
    red_cards_num = 0;
    available = true;
}

Player::~Player()
{
}

Player *Player::clone()
{
    return new Player(*this);
}

void Player::reset_for_new_week()
{
    score = 0;
    if (red_cards_num == 1)
    {
        red_cards_num = 0;
        available = false;
    }
    else if (when_injured > 0)
    {
        when_injured--;
        available = false;
    }
    else if (yellow_cards_num == 3)
    {
        yellow_cards_num = 0;
        available = false;
    }
    else
        available = true;
}
