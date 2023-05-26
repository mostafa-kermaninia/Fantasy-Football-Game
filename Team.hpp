#pragma once
#include "Player.hpp"
#include "ConstVariables.hpp"

class Team
{

public:
    Team(vector<Player *> p);
    Team(string name, vector<Player *> players);
    ~Team();

    vector<Player *> get_players();

    void print_team(ROLE r, bool show_sorted = false);
    double calculate_total_players_score();

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

    vector<Player *> find_players_by_role(ROLE r, vector<Player *> players);
    vector<Player *> sort_by_score(vector<Player *> not_sorted_players);

};
