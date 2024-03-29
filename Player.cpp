#include "Player.hpp"

Player::Player(string name_and_price, string team, ROLE _role)
{
    name = name_and_price.substr(0, name_and_price.find(':'));
    price = stod(name_and_price.substr(name_and_price.find(':') + 1, PLAYER_PRICE_LEN));
    role = _role;
    team_name = team;
    injured_weeks = 0;
    yellow_cards_num = 0;
    red_cards_num = 0;
    num_of_clean_sheets = 0;
    num_of_scored_goals = 0;
    num_of_assists = 0;
    available = true;
}

double Player::get_score()
{
    if (scores.size() == 0)
        return 0;
    return scores.back();
}

string Player::get_team_name()
{
    return team_name;
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
    return score_sum / played_match_num;
}

double Player::calculate_capitan_score()
{
    return calculate_final_score(2 * raw_point);
}

void Player::reset_for_new_week()
{
    scores.push_back(0);
}

void Player::update_avalability_condition()
{
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
    return floor(value * 10) / 10;
}

double Player::calculate_final_score(double score)
{
    return (10 / (exp(-score / 6) + 1));
}