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

void Admin::log_in()
{
    is_in_account = true;
    cout << SUCCESSFUL_RESPONSE;
}

void Admin::log_out()
{
    is_in_account = false;
    cout << SUCCESSFUL_RESPONSE;
}

bool Admin::check_info_validity(string input_username, string input_password)
{
    return input_username == username && input_password == password;
}
