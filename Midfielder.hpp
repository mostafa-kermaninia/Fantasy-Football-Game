#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class Midfielder : public Player
{
public:
    Midfielder(string _name_and_price, string team_name);
    ~Midfielder();

    void set_field(FIELD f) {}

    Midfielder *clone();
    void calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result);
    void print_info(int player_num);

private:
};
