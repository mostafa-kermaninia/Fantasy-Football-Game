#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class Forward : public Player
{
private:
    
public:
    Forward(string _name_and_price);
    ~Forward();
};
