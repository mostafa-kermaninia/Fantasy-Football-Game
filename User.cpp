#include "User.hpp"

User::User(string _name, string _password)
{
    name = _name;
    password = _password;
    sell_limit = 2;
    buy_limit = 2;
    point = 0;
    complete_team = false;
    is_in_account = true;
}

User::~User()
{
}

bool User::is_logged_in()
{
    return is_in_account;
}

void User::log_out()
{
    is_in_account = false;
    cout << SUCCESSFUL_RESPONSE;
}

Player *User::find_player_in_team(string player_name)
{
    for (Player* player:team->get_players())
    {
        /* code */
    }
    
}
