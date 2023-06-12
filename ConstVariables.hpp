#pragma once
#include <string>
#include <vector>
using namespace std;

const vector<string> ROLES = {"gk", "df", "md", "fw"};
enum ROLE
{
    GK,
    DF,
    MD,
    FW,
    NO_ROLE
};

enum MATCH_RESULT
{
    WIN = 5,
    DRAW = 1,
    LOSE = -1
};

enum FIELD
{
    LEFT = -1,
    MIDDLE = 0,
    RIGHT = 1,
    NO_FIELD
};

const string BAD_REQUEST_ER = "Bad Request";
const string PERMISSION_ER = "Permission Denied";
const string SUCCESSFUL_RESPONSE = "OK";
const string NOT_FOUND_ER = "Not Found";
const string EMPTY_ER = "Empty";

const string WEEKS_FOLDER_PATH = "data/weeks_stats/";
const string LEAGUE_INFO_FILE_PATH = "data/premier_league.csv";

const string OUTPUT_DELIMITER = " | ";
const string QUESTION_MARK = "?";
const string TEAM_NAME = "team_name";
const string PASSWORD = "password";
const string USERNAME = "username";
const string NAME = "name";
const string OWN_GOALER_SIGN = "OWN_GOAL";

const int COUNT_OF_WEEKS = 19;
const int THIS_WEEK = -1;
const int LEAGUE_FILE_HEADERS_COUNT = 5;
const int WEEK_FILE_HEADERS_COUNT = 8;

const int WINNER_SCORE_INCREMENT = 3;
const int EQUALIZED_SCORE_INCREMENT = 1;
const int LOSER_SCORE_INCREMENT = 0;

const int INITIAL_BUDGET = 2600;

const int INITIAL_GK_POINT = 3;
const int INITIAL_DF_POINT = 1;
const int INITIAL_MD_POINT = 0;
const int INITIAL_FW_POINT = 0;
const int PLAYER_PRICE_LEN = 3;
const int OWN_GOAL_PENALTY = 3;