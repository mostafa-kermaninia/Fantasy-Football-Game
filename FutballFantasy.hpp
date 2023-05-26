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
    FutballFantasy(string weeks_folder_path, int count_of_weeks, string info_file_path);
    ~FutballFantasy();

    void run();
    void handle_commands();
    void print_week_team(int week_number = THIS_WEEK);
    void print_week_matches(int week_number = THIS_WEEK);

private:
    vector<User *> users;
    vector<Match *> matches;
    vector<Player *> players;
    vector<Team *> teams;
    vector<Team *> week_teams;
    Admin *admin;
    int week_num;
    bool available_transter;

    vector<string> string_splitter(string text, char splitter);
    vector<string> read_file(string file_path);
    void read_weeks_folder(string folder_path, int files_count);
    void read_info_file(string file_path);
    void add_week_team();
    vector<Player *> find_bests(ROLE r);
    bool better_than_chosen_players(vector<Player *> choosen_players, Player* new_player);
    vector<Player *> sort_by_score(vector<Player *> not_sorted_players);

};
