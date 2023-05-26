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

const int LEAGUE_FILE_PATH_INDEX = 1;
const int LEAGUE_FILE_HEADERS_COUNT = 5;
const string WEEKS_FOLDER_PATH = "./weeks_state/";
const int COUNT_OF_WEEKS = 19;
const int WEEK_FILE_HEADERS_COUNT = 6;

const int WINNER_SCORE_INCREMENT = 3;
const int EQUALIZED_SCORE_INCREMENT = 1;
const int LOSER_SCORE_INCREMENT = 0;



class FutballFantasy
{

public:
    FutballFantasy(string league_file_path);
    ~FutballFantasy();

    void run();
    void handle_commands();

private:
    vector<User *> users;
    vector<Match *> matches;
    vector<Player *> players;
    vector<Team *> teams;
    Admin *admin;
    int week_num;
    bool available_transter;

    Player* find_player_by_name(string name);
    Team* find_team_by_name(string name);
    void update_winner_and_loser_team_info(Team*team1,  int team1_goals,Team* team2,int team2_goals);


    vector<string> string_splitter(string text, char splitter);
    vector<string> read_file(string file_path);

    void update_matches_vec(string team_names, string result);
    void update_teams_vec(string team_names, string result);
    void update_players_vec(string injured_players, string yellow_card_recievers, string red_card_recievers,string scores);
    void read_cur_week_file(string folder_path, int cur_week_num);
    void read_league_file(string file_path);
    void build_objects(vector<string> file_elements);
    void check_request_type(string request_type);


    void pass_week();
};
