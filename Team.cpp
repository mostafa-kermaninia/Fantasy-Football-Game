#include "Team.hpp"

Team::Team(string name, vector<Player *> players)
{
    team_name = name;
    team_players = players;
    goals_for = 0;
    goals_against = 0;
    total_score = 0;
}

Team::~Team()
{
}