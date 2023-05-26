#pragma once
#include <iostream>
#include <vector>
#include "ConstVariables.hpp"

using namespace std;

class Player
{

public:
    Player(string name, ROLE role);
    ~Player();

    string get_name() { return name; }
    ROLE get_role() { return role; }
    double get_score() { return score; }

    Player *clone();
    bool is_available();
    void set_when_injured(int week_num) { when_injured = week_num; }
    void add_to_yellow_cards() { yellow_cards_num += 1; }
    void add_to_red_cards() { red_cards_num += 1; }
    void add_to_score(double num) { score = num; }

private:
    string name;
    ROLE role;
    double score;
    int when_injured = 0;
    int yellow_cards_num;
    int red_cards_num;
};