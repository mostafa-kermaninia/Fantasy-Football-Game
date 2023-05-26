#pragma once

#include <string>
#include "ConstVariables.hpp"

using namespace std;

class Admin
{
public:
    Admin(string un, string pw);

    bool is_logged_in();
    void log_in(string pw);
    void log_out();
private:
    string username;
    string password;
    bool is_in_account;
};