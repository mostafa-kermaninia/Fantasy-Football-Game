#include "User.hpp"

User::User(string _name, string _password)
{
    name = _name;
    password = _password;
    sell_coupons = 2;
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
    for (Player *player : team->get_players())
    {
        if (player->get_name() == player_name)
        {
            return player;
        }
    }
    return nullptr;
}

void User::delete_player(string player_name)
{
    if (Player *selected_player = find_player_in_team(player_name))
    {
        if (complete_team)
        {
            if (sell_coupons == 0)
                throw runtime_error(PERMISSION_ER);
            sell_coupons--;
        }
        team->delete_player(player_name);
    }
    else
        throw runtime_error(NOT_FOUND_ER);
}

