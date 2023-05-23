#pragma once
#include "Player.hpp"

class Team
{
private:
    string team_name;
    vector<Player*> team_players;
    int total_score;

public:
    Team(/* args */);
    ~Team();
};
