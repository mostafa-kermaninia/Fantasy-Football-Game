#pragma once
#include <iostream>
#include <vector>
#include "ConstVariables.hpp"

using namespace std;

class Player
{

public:
    Player(string name, ROLE role);

    string get_name() { return name; }
    ROLE get_role() { return role; }
    double get_score() { return scores.back(); }
    int get_yellow_cards() { return yellow_cards_num; }
    int get_red_cards() { return red_cards_num; }

    Player *clone();
    double calculate_avarage_score();
    void reset_for_new_week();
    void set_when_injured() { injured_weeks = 3; }
    bool is_available() { return available; }
    void add_to_yellow_cards() { yellow_cards_num += 1; }
    void add_to_red_cards() { red_cards_num += 1; }
    void add_to_score(double num) { scores.back() = num; }

private:
    string name;
    ROLE role;
    vector<double> scores;
    bool available;
    int injured_weeks = 0;
    int yellow_cards_num;
    int red_cards_num;
};