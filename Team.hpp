#pragma once
#include <cmath>
#include <iomanip>
#include "Player.hpp"
#include "ConstVariables.hpp"

class Team
{

public:
    Team() {}
    Team(vector<Player *> p);
    Team(string name, vector<Player *> players);

    vector<Player *> get_players();
    void add_new_player(Player *new_player);

    void print_team(ROLE r, bool show_sorted = false);
    void print_team_info();
    double calculate_total_players_score();

    int calculate_goal_difrence() { return goals_for - goals_against; }
    int get_goals_for() { return goals_for; }
    string get_name() { return team_name; }
    int get_total_score() { return total_score; }
    void add_to_goals_for(int num) { goals_for += num; }
    void add_to_goals_against(int num) { goals_against += num; }
    void add_to_total_score(int num) { total_score += num; }
    void delete_player(string player_name);
    int count_of_players_in_selected_post(ROLE role);
    int calculate_cost();

private:
    string team_name;
    vector<Player *> team_players;
    int goals_for;
    int goals_against;
    int total_score;

    void find_players_by_role(ROLE r, vector<Player *> &players);
    void sort_by_score(vector<Player *> &not_sorted_players);
    void sort_by_name(vector<Player *> &not_sorted_players);
};
