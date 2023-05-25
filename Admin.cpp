#include "Admin.hpp"

Admin::Admin(string un, string pw)
{
    username = un;
    password = pw;
}

bool Admin::is_logged_in()
{
    return is_in_account;
}

void Admin::log_in(string pw)
{
    if (pw == password)
        is_in_account = true;
}

void Admin::log_out()
{
    is_in_account = false;
}
