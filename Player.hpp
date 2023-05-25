#pragma once
#include <iostream>
#include <vector>
using namespace std;
enum ROLE
{
    GK,
    DF,
    MD,
    FW
};

class Player
{

public:
    Player(string name, ROLE role);
    ~Player();

    bool is_available();

private:
    string name;
    ROLE role;
    int score;
    int when_injured = 0; // its injuring week and 0 means he is not injured
    int yellow_cards_num; // its week Num of yellow card
    int red_cards_num;    // its week Num of yellow card
};
