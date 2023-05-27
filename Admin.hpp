#pragma once

#include <string>
#include <iostream>
#include "ConstVariables.hpp"
using namespace std;

class Admin
{
public:
    Admin(string un, string pw);

    bool is_logged_in();
    void log_in();
    void log_out();

    bool check_info_validity(string input_username, string input_password);

private:
    string username;
    string password;
    bool is_in_account;
};