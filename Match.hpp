#pragma once

#include <iostream>
#include "ConstVariables.hpp"

using namespace std;

class Match
{

public:
    Match(int _week_num, string _team1_name, int _team1_goals, string _team2_name, int _team2_goals);

    void print_match_info();
    int get_week_num();
private:
    int week_num;
    string team1_name;
    int team1_goals;
    string team2_name;
    int team2_goals;
};
