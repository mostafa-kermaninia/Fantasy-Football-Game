#include "Forward.hpp"

Forward::Forward(string _name)
    : Player(_name, FW)
{
}

Forward::~Forward()
{
}

Forward *Forward::clone()
{
    return new Forward(*this);
}
