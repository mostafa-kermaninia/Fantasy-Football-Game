#include "Defender.hpp"

Defender::Defender(string _name_and_price,string team_name)
    : Player(_name_and_price, team_name ,DF)
{
}
Defender::~Defender()
{
}

Defender *Defender::clone()
{
    return new Defender(*this);
}

void Defender::calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result)
{
}

void Defender::print_info(int player_num)
{
}
