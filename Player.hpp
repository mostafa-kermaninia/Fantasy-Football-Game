#pragma once
#include <iostream>
#include <vector>
using namespace std;
enum ROLE
{
    gk,
    df,
    md,
    fw
};

class Player
{

public:
    Player(/* args */);
    Player (const Player &p);
    ~Player();

    bool is_available();

private:
    string name;
    ROLE role;
    int score;
    int when_injured = 0;     // its injuring week and 0 means he is not injured
    int yellow_cards_num; // its week Num of yellow card
    int red_cards_num;    // its week Num of yellow card
};
