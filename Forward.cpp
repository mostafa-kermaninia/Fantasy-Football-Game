#include "Forward.hpp"

Forward::Forward(string _name_and_price)
    : Player(_name_and_price, FW)
{
}

Forward::~Forward()
{
}

Forward *Forward::clone()
{
    return new Forward(*this);
}

void Forward::calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result)
{
}

void Forward::print_info(int player_num)
{
}
