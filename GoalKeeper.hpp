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
    GoalKeeper(string _name_and_price);
    ~GoalKeeper();

    GoalKeeper *clone();
    void calculate_score(vector<Player *> scorers, MATCH_RESULT result, int num_of_og);
    void print_info(int player_num);

private:
    int num_of_clean_sheets;
};
