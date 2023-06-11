#pragma once
#include <iostream>
#include <vector>

#include "Player.hpp"
#include "ConstVariables.hpp"
using namespace std;

class Defender : public Player
{
private:
    
public:
    Defender(string _name_and_price);
    ~Defender();
};
