#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class GoalKeeper : public Player
{
private:
    
public:
    GoalKeeper(string _name);
    ~GoalKeeper();
};
