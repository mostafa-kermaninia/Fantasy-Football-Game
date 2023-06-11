#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class Midfielder : public Player
{
public:
    Midfielder(string _name_and_price);
    ~Midfielder();

    Midfielder *clone();
    void calculate_score(vector<Player *> scorers, MATCH_RESULT result, int num_of_og);
    void print_info(int player_num);

private:
};
