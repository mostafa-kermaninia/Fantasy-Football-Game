#include "Defender.hpp"

Defender::Defender(string _name_and_price, string team_name)
    : Player(_name_and_price, team_name, DF)
{
    num_of_clean_sheets = 0;
}
Defender::~Defender()
{
}

Defender *Defender::clone()
{
    return new Defender(*this);
}

void Defender::calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters,
                                   vector<Player *> goal_scorers, MATCH_RESULT result)
{
    raw_point = INITIAL_DF_POINT;
    raw_point += result;
    int gained_goals = 0;
    for (auto p : own_goalers)
    {
        if (p->get_team_name() == team_name)
            gained_goals++;
        if (p->get_name() == name)
            raw_point -= OWN_GOAL_PENALTY;
    }
    for (auto p : goal_scorers)
    {
        if (p->get_team_name() != team_name)
        {
            gained_goals++;
            if (p->get_field() == -player_field)
                raw_point -= 1;
        }
        if (p->get_name() == name)
        {
            raw_point += 4;
            num_of_scored_goals++;
        }
    }
    for (auto p : assisters)
        if (p->get_name() == name)
        {
            raw_point += 3;
            num_of_assists++;
        }
    if (gained_goals == 0)
    {
        num_of_clean_sheets++;
        raw_point += 2;
    }
    add_to_score(calculate_final_score(raw_point));
}

void Defender::print_info(int player_num)
{
    cout << fixed;
    cout << player_num << ". name: " << name << OUTPUT_DELIMITER << "role: " << ROLES[role]
         << OUTPUT_DELIMITER << "score: " << setprecision(1) << round_to(calculate_avarage_score())
         << OUTPUT_DELIMITER << "cost: " << (int)price << OUTPUT_DELIMITER
         << "goals: " << num_of_scored_goals << OUTPUT_DELIMITER
         << "assists: " << num_of_assists << OUTPUT_DELIMITER
         << "clean sheets: " << num_of_clean_sheets << endl;
}
