#pragma once
#include "Team.hpp"
class User
{
private:
    Team* team;
    string password;
    int point;
public:
    User(/* args */);
    ~User();
};

