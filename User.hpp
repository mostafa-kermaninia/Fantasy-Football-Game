#pragma once
#include "Team.hpp"
#include "ConstVariables.hpp"

class User
{
public:
    User(string name, string password);
    ~User();

    string get_name() { return name; }
    double get_point() { return point; }
    int get_buy_copouns() { return buy_coupons; }
    bool is_team_completed() { return complete_team; }

    bool check_password_validity(string input_pass) { return password == input_pass; }
    bool is_logged_in();
    void log_in() { is_in_account = true; }
    void log_out();
    Player *find_player_in_team(string player_name);
    void delete_player(string player_name);

    void add_player(Player *selected_player);
    void set_captain(string player_name);
    void reset_coupons();
    void update_score();
    void show_budget();
    void print_fantasy_team();
    void print_team_info();
    void print_player_name(string name);

private:
    string name;
    int sell_coupons;
    int buy_coupons;
    Team *team;
    Team *last_week_team;
    Player *capitan;
    Player *last_week_cap;
    string password;
    double point;
    bool complete_team;
    bool is_in_account;
    double budget;

    bool player_post_is_not_full(Player *selected_player);
    vector<Player *> find_players_by_role(ROLE r);
    void sort_players_by_name(vector<Player *> &players);
};
