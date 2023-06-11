#include "Midfielder.hpp"

Midfielder::Midfielder(string _name_and_price)
    : Player(_name_and_price, MD)
{
}

Midfielder::~Midfielder()
{
}

Midfielder *Midfielder::clone()
{
    return new Midfielder(*this);
}

void Midfielder::calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result)
{
}

void Midfielder::print_info(int player_num)
{
}
