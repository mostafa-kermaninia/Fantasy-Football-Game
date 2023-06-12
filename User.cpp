#include "User.hpp"

User::User(string _name, string _password)
{
    team = new Team();
    last_week_team = new Team();
    last_week_cap = nullptr;
    name = _name;
    password = _password;
    sell_coupons = 2;
    buy_coupons = 0;
    point = 0;
    budget = INITIAL_BUDGET;
    capitan = NULL;
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
    if (capitan != nullptr && capitan->get_name() == player_name)
        capitan = nullptr;
    if (Player *selected_player = find_player_in_team(player_name))
    {
        if (complete_team)
        {
            if (sell_coupons == 0)
                throw runtime_error(PERMISSION_ER);
            sell_coupons--;
            buy_coupons++;
        }
        budget += selected_player->get_price();
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
        if (budget > selected_player->get_price())
        {
            team->add_new_player(selected_player);
            buy_coupons--;
            budget -= selected_player->get_price();
        }
        else
            throw runtime_error(BAD_REQUEST_ER);
    }
    else
        cout << "This player is not available for next week" << endl;
}

void User::set_captain(string player_name)
{
    Player *new_capitan = find_player_in_team(player_name);
    if (new_capitan == nullptr)
        throw runtime_error(NOT_FOUND_ER);
    else
        capitan = new_capitan;
}

void User::reset_coupons()
{
    delete last_week_team;
    last_week_team = new Team(*team);
    if (last_week_cap != nullptr)
        delete last_week_cap;
    if (capitan != nullptr)
        last_week_cap = capitan->clone();
    else
        last_week_cap = nullptr;
    if (!complete_team && team->get_players().size() == 5)
        complete_team = true;
    sell_coupons = 2;
    buy_coupons = 0;
}

void User::update_score()
{
    if (team->get_players().size() == 5)
    {
        point += team->calculate_total_players_score();
        if (capitan != nullptr && capitan->get_score() != 0)
        {
            point -= capitan->get_score();
            point += capitan->calculate_capitan_score();
        }
    }
}

void User::show_budget()
{
    cout << budget << endl;
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
    cout << "Goalkeeper: ";
    print_player_name(goalkeeper[0]->get_name());
    cout << "Defender1: ";
    print_player_name(defender[0]->get_name());
    cout << "Defender2: ";
    print_player_name(defender[1]->get_name());
    cout << "Midfielder: ";
    print_player_name(midfielder[0]->get_name());
    cout << "Striker: ";
    print_player_name(striker[0]->get_name());
    cout << fixed;
    cout << "Total Points: " << setprecision(1) << point << endl;
    cout << "Team Cost: " << last_week_team->calculate_cost() << endl;
}

void User::print_player_name(string name)
{
    cout << name;
    if (last_week_cap != nullptr && last_week_cap->get_name() == name)
        cout << " (CAPTAIN)";
    cout << endl;
}

bool User::player_post_is_not_full(Player *selected_player)
{
    ROLE role = selected_player->get_role();
    if (find_player_in_team(selected_player->get_name()) != NULL)
        throw runtime_error(BAD_REQUEST_ER);
    return ((role == DF && team->count_of_players_in_selected_post(role) < 2) ||
            (role != DF && team->count_of_players_in_selected_post(role) < 1));
}

vector<Player *> User::find_players_by_role(ROLE r)
{
    vector<Player *> target_players, sorce_players = last_week_team->get_players();
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
            if (players[i]->get_name() > players[j]->get_name())
            {
                Player *swaping_player = players[i];
                players[i] = players[j];
                players[j] = swaping_player;
            }
}
