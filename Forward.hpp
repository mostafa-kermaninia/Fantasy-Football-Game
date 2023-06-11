#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class Forward : public Player
{
public:
    Forward(string _name_and_price,string team_name);
    ~Forward();

    void set_field(FIELD f) { player_field = f; }

    Forward *clone();
    void calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result);
    void print_info(int player_num);

private:
    FIELD player_field;
};
