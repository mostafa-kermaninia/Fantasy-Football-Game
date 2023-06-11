#include "Midfielder.hpp"

Midfielder::Midfielder(string _name)
    : Player(_name, MD)
{
}

Midfielder::~Midfielder()
{
}

Midfielder *Midfielder::clone()
{
    return new Midfielder(*this);
}
