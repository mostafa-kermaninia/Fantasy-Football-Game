#pragma once
#include "Player.hpp"

class Team
{

public:
    Team(string name, vector<Player *> players);
    ~Team();

    string get_name() { return team_name; }
    void add_to_goals_for(int num) { goals_for += num; }
    void add_to_goals_against(int num) { goals_against += num; }
    void add_to_total_score(int num) { total_score += num; }

private:
    string team_name;
    vector<Player *> team_players;
    int goals_for;
    int goals_against;
    int total_score;
};
