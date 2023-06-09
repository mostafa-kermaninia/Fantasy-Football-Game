#include "Player.hpp"

Player::Player(string _name, ROLE _role)
{
    name = _name;
    role = _role;
    injured_weeks = 0;
    yellow_cards_num = 0;
    red_cards_num = 0;
    available = true;
}

double Player::get_score()
{
    if (scores.size() == 0)
        return 0;
    return scores.back();
}

Player *Player::clone()
{
    return new Player(*this);
}

double Player::calculate_avarage_score()
{
    double score_sum = 0;
    int played_match_num = 0;
    for (auto s : scores)
    {
        if (s > 0)
        {
            score_sum += s;
            played_match_num++;
        }
    }
    if (played_match_num == 0)
        return 0;
    return round_to(score_sum / played_match_num);
}

void Player::reset_for_new_week()
{
    scores.push_back(0);
    if (red_cards_num == 1)
    {
        red_cards_num = 0;
        yellow_cards_num = 0;
        available = false;
    }
    else if (injured_weeks > 0)
    {
        injured_weeks--;
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

double Player::round_to(double value)
{
    return round(value * 10) / 10;
}
