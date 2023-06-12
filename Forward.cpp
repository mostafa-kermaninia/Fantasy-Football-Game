#include "Forward.hpp"

Forward::Forward(string _name_and_price, string team_name)
    : Player(_name_and_price, team_name, FW)
{
}

Forward::~Forward()
{
}

Forward *Forward::clone()
{
    return new Forward(*this);
}

void Forward::calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters,
                                  vector<Player *> goal_scorers, MATCH_RESULT result)
{
    raw_point = INITIAL_FW_POINT;
    raw_point += result;
    int scored_goals = 0;
    for (auto p : own_goalers)
        if (p->get_name() == name)
            raw_point -= OWN_GOAL_PENALTY;
    for (auto p : goal_scorers)
        if (p->get_name() == name)
        {
            scored_goals++;
            num_of_scored_goals++;
        }
    for (auto p : assisters)
        if (p->get_name() == name)
        {
            raw_point += 1;
            num_of_assists++;
        }
    if (scored_goals == 0)
        raw_point--;
    else
        raw_point += (3 * scored_goals);
    add_to_score(calculate_final_score(raw_point));
}

void Forward::print_info(int player_num)
{
    cout << fixed;
    cout << player_num << ". name: " << name << OUTPUT_DELIMITER << "role: " << ROLES[role]
         << OUTPUT_DELIMITER << "score: " << setprecision(1) << calculate_avarage_score()
         << OUTPUT_DELIMITER << "cost: " << (int)price << OUTPUT_DELIMITER
         << "goals: " << num_of_scored_goals << OUTPUT_DELIMITER
         << "assists: " << num_of_assists << endl;
}
