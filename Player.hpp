#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include "ConstVariables.hpp"

using namespace std;

class Player
{

public:
    Player(string name, string team_name, ROLE role);
    Player() {}

    string get_name() { return name; }
    ROLE get_role() { return role; }
    int get_yellow_cards() { return yellow_cards_num; }
    int get_red_cards() { return red_cards_num; }
    double get_price() { return price; }
    double get_score();
    string get_team_name();
    virtual FIELD get_field() = 0;

    virtual Player *clone() = 0;
    double calculate_avarage_score();
    double calculate_capitan_score();
    void reset_for_new_week();
    void update_avalability_condition();
    void set_when_injured() { injured_weeks = 3; }
    bool is_available() { return available; }
    void add_to_yellow_cards() { yellow_cards_num += 1; }
    void add_to_red_cards() { red_cards_num += 1; }
    void add_to_score(double num) { scores.back() = num; }
    virtual void calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result) = 0;
    virtual void print_info(int player_num) = 0;
    virtual void set_field(FIELD f) = 0;

protected:
    string name;
    ROLE role;
    vector<double> scores;
    bool available;
    int injured_weeks;
    int yellow_cards_num;
    int red_cards_num;
    int num_of_clean_sheets;
    int num_of_scored_goals;
    int num_of_assists;
    double price;
    double raw_point;
    string team_name;

    double round_to(double value);
    double calculate_final_score(double score);
};