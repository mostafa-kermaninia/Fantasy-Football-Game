#include "User.hpp"

User::User(string _name, string _password)
{
    team = new Team();
    last_week_team = new Team();
    name = _name;
    password = _password;
    sell_coupons = 2;
    buy_coupons = 0;
    point = 0;
    complete_team = false;
    is_in_account = true;
}

User::~User()
{
    delete team;
    delete last_week_team;
}

bool User::is_logged_in()
{
    return is_in_account;
}

void User::log_out()
{
    is_in_account = false;
}

Player *User::find_player_in_team(string player_name)
{
    for (Player *player : team->get_players())
        if (player->get_name() == player_name)
            return player;
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
            buy_coupons++;
        }
        team->delete_player(player_name);
    }
    else
        throw runtime_error(NOT_FOUND_ER);
}

void User::add_player(Player *selected_player)
{
    if (!player_post_is_not_full(selected_player))
        throw runtime_error(BAD_REQUEST_ER);

    if (selected_player->is_available())
    {
        team->add_new_player(selected_player);
        buy_coupons--;
    }
    else
        cout << "This player is not available for next week" << endl;
}

void User::reset_coupons()
{
    delete last_week_team;
    last_week_team = new Team(*team);
    if (!complete_team && team->get_players().size() == 5)
        complete_team = true;
    sell_coupons = 2;
    buy_coupons = 0;
}

void User::update_score()
{
    if (team->get_players().size() == 5)
        point += team->calculate_total_players_score();
}

void User::print_fantasy_team()
{
    cout << fixed;
    cout << "team_name: " << name << OUTPUT_DELIMITER << "point: " << setprecision(1) << point << endl;
}

void User::print_team_info()
{
    if (last_week_team->get_players().size() != 5)
        throw runtime_error(EMPTY_ER);
    vector<Player *> goalkeeper = find_players_by_role(GK);
    vector<Player *> defender = find_players_by_role(DF);
    vector<Player *> midfielder = find_players_by_role(MD);
    vector<Player *> striker = find_players_by_role(FW);
    cout << "fantasy_team: " << name << endl;
    cout << "Goalkeeper: " << goalkeeper[0]->get_name() << endl;
    cout << "Defender1: " << defender[0]->get_name() << endl;
    cout << "Defender2: " << defender[1]->get_name() << endl;
    cout << "Midfielder: " << midfielder[0]->get_name() << endl;
    cout << "Striker: " << striker[0]->get_name() << endl;
    cout << "Total Points: " << point << endl;
}

bool User::player_post_is_not_full(Player *selected_player)
{
    ROLE role = selected_player->get_role();
    return ((role == DF && team->count_of_players_in_selected_post(role) < 2) ||
            (role != DF && team->count_of_players_in_selected_post(role) < 1));
}

vector<Player *> User::find_players_by_role(ROLE r)
{
    vector<Player *> target_players, sorce_players = team->get_players();
    for (auto sp : sorce_players)
        if (sp->get_role() == r)
            target_players.push_back(sp);
    sort_players_by_name(target_players);
    return target_players;
}

void User::sort_players_by_name(vector<Player *> &players)
{
    for (int i = 0; i < players.size() - 1; i++)
        for (int j = i + 1; j < players.size(); j++)
            if (players[i]->get_name() < players[j]->get_name())
            {
                Player *swaping_player = players[i];
                players[i] = players[j];
                players[j] = swaping_player;
            }
}
