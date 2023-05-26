#pragma once
#include <string>

using namespace std;

enum ROLE
{
    GK,
    DF,
    MD,
    FW,
    NO_ROLE
};

vector<string> ROLES = {"gk", "df", "md", "fw"};

const string OUTPUT_DELIMITER = " | ";
const string REQUEST_ER = "Bad Request";
const string PERMISSION_ER = "Permission Denied";
const string SUCCESSFUL_MASSAGE = "OK";
const string FINDING_ER = "Not Found";
const string EMPTY_ER = "Empty";

const int WEEKS_FOLDER_PATH_INDEX = 1;
const int INFO_FILE_PATH_INDEX = 2;
const int COUNT_OF_WEEKS = 19;
const int THIS_WEEK = -1;
const int LEAGUE_FILE_PATH_INDEX = 1;
const int LEAGUE_FILE_HEADERS_COUNT = 5;
const string WEEKS_FOLDER_PATH = "./weeks_state/";
const int WEEK_FILE_HEADERS_COUNT = 6;

const int WINNER_SCORE_INCREMENT = 3;
const int EQUALIZED_SCORE_INCREMENT = 1;
const int LOSER_SCORE_INCREMENT = 0;