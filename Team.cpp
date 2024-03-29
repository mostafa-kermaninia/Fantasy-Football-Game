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
    cout << "list of players:" << endl;
    for (auto p : showing_players)
    {
        p->print_info(player_num);
        player_num++;
    }
}

void Team::print_team_info()
{
    cout << team_name << ": "
         << "score: " << total_score << OUTPUT_DELIMITER
         << "GF: " << goals_for << OUTPUT_DELIMITER << "GA: " << goals_against << endl;
}

double Team::calculate_total_players_score()
{
    double total_score = 0;
    for (auto p : team_players)
        total_score += p->get_score();
    return total_score;
}

void Team::free_players()
{
    for (auto p : team_players)
        delete p;
}

void Team::add_match_result(int scored_goals, int gained_goals)
{
    if (scored_goals > gained_goals)
        last_match_result = WIN;
    else if (scored_goals == gained_goals)
        last_match_result = DRAW;
    else
        last_match_result = LOSE;
}

void Team::delete_player(string player_name)
{
    for (int i = 0; i < team_players.size(); i++)
        if (team_players[i]->get_name() == player_name)
            team_players.erase(team_players.begin() + i);
}

int Team::count_of_players_in_selected_post(ROLE role)
{
    int counter = 0;
    for (Player *player : team_players)
        if (player->get_role() == role)
            counter++;
    return counter;
}

int Team::calculate_cost()
{
    double team_value = 0;
    for (auto p : team_players)
        team_value += p->get_price();
    return team_value;
}

void Team::update_week_lineup(vector<Player *> lineup)
{
    week_lineup = lineup;
    update_players_fields();
}

void Team::update_players_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers)
{
    for (auto p : week_lineup)
        p->calculate_raw_score(own_goalers, assisters, goal_scorers, last_match_result);
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
        for (int j = i + 1; j < not_sorted_players.size(); j++)
            if (not_sorted_players[i]->calculate_avarage_score() < not_sorted_players[j]->calculate_avarage_score() ||
                (not_sorted_players[i]->calculate_avarage_score() == not_sorted_players[j]->calculate_avarage_score() &&
                 not_sorted_players[i]->get_name() > not_sorted_players[j]->get_name()))
            {
                Player *swaped_player = not_sorted_players[i];
                not_sorted_players[i] = not_sorted_players[j];
                not_sorted_players[j] = swaped_player;
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

void Team::update_players_fields()
{
    week_lineup[1]->set_field(LEFT);
    week_lineup[2]->set_field(MIDDLE);
    week_lineup[3]->set_field(MIDDLE);
    week_lineup[4]->set_field(RIGHT);
    week_lineup[8]->set_field(LEFT);
    week_lineup[9]->set_field(MIDDLE);
    week_lineup[10]->set_field(RIGHT);
}
