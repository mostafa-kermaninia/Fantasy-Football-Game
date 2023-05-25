#pragma once
#include "Player.hpp"

class Team
{

public:
    Team(string name, vector<Player *> players);
    ~Team();

private:
    string team_name;
    vector<Player *> team_players;
    int goals_for;
    int goals_against;
    int total_score;
};
