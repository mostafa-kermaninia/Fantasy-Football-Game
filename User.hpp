#pragma once
#include "Team.hpp"
#include "ConstVariables.hpp"

class User
{
public:
    User(string name, string password);
    ~User();

    string get_name() { return name; }
    bool check_password_validity(string input_pass) { return password == input_pass; }
    bool is_logged_in();
    void log_in() { is_in_account = true; }
    void log_out();

private:
    string name;
    int sell_limit;
    int buy_limit; // maybe ziadie
    Team *team;
    string password;
    double point;
    bool complete_team;
    bool is_in_account;
};
