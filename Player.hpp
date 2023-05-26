#pragma once
#include <iostream>
#include <vector>
#include "ConstVariables.hpp"

using namespace std;


class Player
{

public:
    Player(/* args */);
    ~Player();

    string get_name();
    ROLE get_role();
    double get_score();

    Player *clone();
    bool is_available();

private:
    string name;
    ROLE role;
    double score;
    int when_injured = 0;     // its injuring week and 0 means he is not injured
    int yellow_cards_num; // its week Num of yellow card
    int red_cards_num;    // its week Num of yellow card
};
