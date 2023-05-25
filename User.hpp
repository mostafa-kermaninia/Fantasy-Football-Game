#pragma once
#include "Team.hpp"
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
    int point;
    bool complete_team;
};
