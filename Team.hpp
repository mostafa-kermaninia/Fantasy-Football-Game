#pragma once
#include "Player.hpp"
#include "ConstVariables.hpp"

class Team
{

public:
    Team(vector<Player *> p);
    ~Team();

    vector<Player *> get_players();

    void print_team(ROLE r, bool show_sorted = false);
    double calculate_total_players_score();

private:
    string team_name;
    vector<Player *> team_players;
    int goals_for;
    int goals_against;
    int total_score;

    vector<Player *> find_players_by_role(ROLE r, vector<Player *> players);
    vector<Player *> sort_by_score(vector<Player *> not_sorted_players);

};
