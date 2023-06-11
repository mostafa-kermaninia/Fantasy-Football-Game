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

void Forward::calculate_score(vector<Player *> scorers, MATCH_RESULT result, int num_of_og)
{
}

void Forward::print_info(int player_num)
{
}
