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

void Midfielder::calculate_score(vector<Player *> scorers, MATCH_RESULT result, int num_of_og)
{
}

void Midfielder::print_info(int player_num)
{
}
