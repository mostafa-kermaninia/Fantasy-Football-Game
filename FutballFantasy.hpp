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

const int WEEKS_FOLDER_PATH_INDEX = 1;
const int INFO_FILE_PATH_INDEX = 2;
const int COUNT_OF_WEEKS = 19;

class FutballFantasy
{

public:
    FutballFantasy(string weeks_folder_path, int count_of_weeks, string info_file_path);
    ~FutballFantasy();

    void run();
    void handle_commands();

private:
    vector<User *> users;
    vector<Match *> matches;
    vector<Player *> players;
    vector<Team *> teams;
    int week_num;
    bool available_transter;

    vector<string> string_splitter(string text, char splitter);
    vector<string> read_file(string file_path);
    void read_weeks_folder(string folder_path, int files_count);
    void read_info_file(string file_path);
};
