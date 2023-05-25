#pragma once
#include "Player.hpp"

class Team
{

public:
    Team(/* args */);
    ~Team();

private:
    string team_name;
    vector<Player *> team_players;
    int goals_for;
    int goals_against;
    int total_score;
};
