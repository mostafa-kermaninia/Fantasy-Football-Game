#pragma once
#include "Team.hpp"
#include "ConstVariables.hpp"

class User
{
public:
    User(/* args */);
    ~User();

private:
    string name;
    int sell_limit;
    int buy_limit; //maybe ziadie
    Team *team;
    string password;
    double point;
    bool complete_team;
};
