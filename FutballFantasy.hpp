#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "User.hpp"
#include "Match.hpp"
#include "Player.hpp"
#include "Team.hpp"
#include "Admin.hpp"
#include "ConstVariables.hpp"

class FutballFantasy
{

public:
    FutballFantasy(string league_file_path);
    ~FutballFantasy();

    void run();
    void handle_commands();
    void print_league_info();
    void print_week_team(int week_number);
    void print_week_matches(int week_number);
    void print_team_players();
    void print_users();
    void print_squad();

private:
    vector<User *> users;
    vector<Match *> matches;
    vector<Player *> players;
    vector<Team *> teams;
    vector<Team *> week_teams;
    Admin *admin;
    User *cur_user;
    int week_num;
    bool available_transter;

    Player *find_player_by_name(string name);
    Team *find_team_by_name(string name);
    User *find_logged_in_user();
    User*find_user_by_name(string name);
    ROLE find_role(string target_role);
    void update_winner_and_loser_team_info(Team *team1, int team1_goals, Team *team2, int team2_goals);

    vector<string> string_splitter(string text, char splitter);
    vector<string> read_file(string file_path);

    void sort_teams();
    void sort_users();
    bool is_better_team(Team *team1, Team *team2);

    string edit_entry_team_name(string name);

    void reset_players_score();
    void update_users_score();
    void update_matches_vec(string team_names, string result);
    void update_teams_vec(string team_names, string result);
    void update_players_vec(string injured_players, string yellow_card_recievers, string red_card_recievers, string scores);
    void read_cur_week_file(string folder_path, int cur_week_num);
    void read_league_file(string file_path);
    void add_week_team();

    void handle_get_requests();
    void handle_post_requests();
    void handle_put_requests();
    void handle_delete_requests();

    vector<Player *> find_bests(ROLE r);
    bool better_than_chosen_players(vector<Player *> choosen_players, Player *new_player);

    void build_objects(vector<string> file_elements);

    void signup(string name, string password);
    void login(string name, string password);
    void register_admin(string admin_name, string password);
    void sell_player(string player_name);
    void buy_player(string player_name);

    void pass_week();
    void open_transfer_window();
    void close_transfer_window();
};
