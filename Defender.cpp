#include "Defender.hpp"

Defender::Defender(string _name_and_price)
    : Player(_name_and_price, DF)
{
}
Defender::~Defender()
{
}

Defender *Defender::clone()
{
    return new Defender(*this);
}

void Defender::calculate_score(vector<Player *> scorers, MATCH_RESULT result, int num_of_og)
{
}

void Defender::print_info(int player_num)
{
}
