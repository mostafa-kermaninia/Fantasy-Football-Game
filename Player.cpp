#include "Player.hpp"

Player::Player(/* args */)
{
}

Player::Player(const Player &p)
{
    name = p.name;
    role = p.role;
    score = p.score;
    when_injured = p.when_injured;
    yellow_cards_num = p.yellow_cards_num;
    red_cards_num = p.red_cards_num;
}

Player::~Player()
{
}

bool Player::is_available()
{
    if (red_cards_num == 1 || when_injured > 0 || yellow_cards_num == 3)
        return false;
    return true;
}
