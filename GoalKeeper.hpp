#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class GoalKeeper : public Player
{
public:
    GoalKeeper(string _name_and_price,string team_name);
    ~GoalKeeper();

    void set_field(FIELD f) {}

    GoalKeeper *clone();
    void calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result);
    void print_info(int player_num);

private:
    int num_of_clean_sheets;
};
