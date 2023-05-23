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
private:
    string name;
    ROLE role;
    int score;
    int when_injured = 0; // its injuring week and 0 means he is not injured
    vector<int> yellow_cards; // its week Num of yellow card
    vector<int> red_cards;    // its week Num of yellow card

public:
    Player(/* args */);
    ~Player();
};
