#include "Team.hpp"

Team::Team(vector<Player *> p)
{
    team_players = p;
}

Team::Team(string name, vector<Player *> players)
{
    team_name = name;
    team_players = players;
    goals_for = 0;
    goals_against = 0;
    total_score = 0;
}

Team::~Team()
{
}

vector<Player *> Team::get_players()
{
    return team_players;
}

void Team::add_new_player(Player *new_player)
{
    team_players.push_back(new_player);
}

void Team::print_team(ROLE r, bool show_sorted)
{
    vector<Player *> showing_players = team_players;
    int player_num = 1;
    if (r != NO_ROLE)
        find_players_by_role(r, showing_players);
    if (show_sorted)
        sort_by_score(showing_players);
    else
        sort_by_name(showing_players);
    for (auto p : showing_players)
    {
        cout << fixed;
        cout << player_num << ". name: " << p->get_name() << OUTPUT_DELIMITER << "role: " << ROLES[p->get_role()]
             << OUTPUT_DELIMITER << "score: " << setprecision(1) << round_to(0.1, p->calculate_avarage_score()) << endl;
        player_num++;
    }
}

void Team::print_team_info()
{
    cout << team_name << ": " << total_score << OUTPUT_DELIMITER << "GF: " << goals_for << OUTPUT_DELIMITER << "GA: " << goals_against << endl;
}

double Team::calculate_total_players_score()
{
    double total_score = 0;
    for (auto p : team_players)
        total_score += p->get_score();
    return total_score;
}

void Team::delete_player(string player_name)
{
    for (int i = 0; i < team_players.size(); i++)
    {
        if (team_players[i]->get_name() == player_name)
        {
            team_players.erase(team_players.begin() + i);
        }
    }
}

int Team::count_of_players_in_selected_post(ROLE role)
{
    int counter = 0;
    for (Player *player : team_players)
        if (player->get_role() == role)
            counter++;
    return counter;
}

void Team::find_players_by_role(ROLE r, vector<Player *> &players)
{
    for (int i = 0; i < players.size(); i++)
        if (players[i]->get_role() != r)
        {
            players.erase(players.begin() + i);
            i--;
        }
}

void Team::sort_by_score(vector<Player *> &not_sorted_players)
{
    for (int i = 0; i < not_sorted_players.size() - 1; i++)
    {
        for (int j = i + 1; j < not_sorted_players.size(); j++)
        {
            if (not_sorted_players[i]->get_score() < not_sorted_players[j]->get_score() ||
                (not_sorted_players[i]->get_score() == not_sorted_players[j]->get_score() &&
                 not_sorted_players[i]->get_name() > not_sorted_players[j]->get_name()))
            {
                Player *swaped_player = not_sorted_players[i];
                not_sorted_players[i] = not_sorted_players[j];
                not_sorted_players[j] = swaped_player;
            }
        }
    }
}

void Team::sort_by_name(vector<Player *> &not_sorted_players)
{
    for (int i = 0; i < not_sorted_players.size() - 1; i++)
        for (int j = i + 1; j < not_sorted_players.size(); j++)
            if (not_sorted_players[i]->get_name() > not_sorted_players[j]->get_name())
            {
                Player *swaping_player = not_sorted_players[i];
                not_sorted_players[i] = not_sorted_players[j];
                not_sorted_players[j] = swaping_player;
            }
}

double Team::round_to(double pre, double value)
{
    return round(value / pre) * pre;
}
