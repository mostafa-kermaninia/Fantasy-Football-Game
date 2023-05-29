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
    bool check_password_validity(string input_pass) { return password == input_pass; }
    bool is_logged_in();
    void log_in() { is_in_account = true; }
    void log_out();
    Player *find_player_in_team(string player_name);
    void delete_player(string player_name);

    bool is_player_buyable(Player *selected_player);
    void add_player_to_team(Player *selected_player);

    void reset_coupons();
    void update_score();
    void print_fantasy_team();
    void print_team_info();

private:
    string name;
    int sell_coupons;
    int buy_coupons; // maybe ziadie
    Team *team;
    string password;
    double point;
    bool complete_team;
    bool is_in_account;

    vector<Player *> find_players_by_role(ROLE r);
    vector<Player *> sort_players_by_name(vector<Player *> players);
};
