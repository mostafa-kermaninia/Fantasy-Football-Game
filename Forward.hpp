#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class Forward : public Player
{
public:
    Forward(string _name_and_price);
    ~Forward();

    Forward *clone();
    void calculate_score(vector<Player *> scorers, MATCH_RESULT result, int num_of_og);
    void print_info(int player_num);

private:
};
