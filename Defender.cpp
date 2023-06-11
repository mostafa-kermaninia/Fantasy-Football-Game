#include "Defender.hpp"

Defender::Defender(string _name)
    : Player(_name, DF)
{
}

Defender::~Defender()
{
}

Defender *Defender::clone()
{
    return new Defender(*this);
}
