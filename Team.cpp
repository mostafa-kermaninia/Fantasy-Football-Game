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

void Team::print_team(ROLE r, bool show_sorted)
{
    vector<Player *> showing_players = team_players;
    int player_num = 1;
    if (r != NO_ROLE)
        showing_players = find_players_by_role(r, showing_players);
    if (show_sorted)
        showing_players = sort_by_score(showing_players);
    for (auto p : showing_players)
    {
        cout << player_num << ". name: " << p->get_name() << OUTPUT_DELIMITER <<
             "role: " << ROLES[p->get_role()] << OUTPUT_DELIMITER << "score: " << p->get_score() << endl;
        player_num++;
    }
}

double Team::calculate_total_players_score()
{
    double total_score = 0;
    for (auto p : team_players)
        total_score += p->get_score();
    return total_score;
}

vector<Player *> Team::find_players_by_role(ROLE r, vector<Player *> players)
{
    for (int i = 0; i < players.size(); i++)
        if (players[i]->get_role() != r)
        {
            players.erase(players.begin() + i);
            i--;
        }
    return players;
}

vector<Player *> Team::sort_by_score(vector<Player *> not_sorted_players)
{
    for (int i = 0; i < not_sorted_players.size() - 1; i++)
    {
        for (int j = i + 1; j < i < not_sorted_players.size(); j++)
        {
            if (not_sorted_players[i]->get_score() > not_sorted_players[j]->get_score())
            {
                Player *swaped_player = not_sorted_players[i];
                not_sorted_players[i] = not_sorted_players[j];
                not_sorted_players[j] = swaped_player;
            }
        }
    }
    return not_sorted_players;
}