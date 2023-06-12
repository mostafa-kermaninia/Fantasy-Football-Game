#include "GoalKeeper.hpp"

GoalKeeper::GoalKeeper(string _name_and_price, string team_name)
    : Player(_name_and_price, team_name, GK)
{
}

GoalKeeper::~GoalKeeper()
{
}

GoalKeeper *GoalKeeper::clone()
{
    return new GoalKeeper(*this);
}

void GoalKeeper::calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters,
                                     vector<Player *> goal_scorers, MATCH_RESULT result)
{
    raw_point = INITIAL_GK_POINT;
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
        if (p->get_team_name() != team_name)
            gained_goals++;
    if (gained_goals == 0)
    {
        num_of_clean_sheets++;
        raw_point += 5;
    }
    else
        raw_point -= gained_goals;
    add_to_score(calculate_final_score(raw_point));
}

void GoalKeeper::print_info(int player_num)
{
    cout << fixed;
    cout << player_num << ". name: " << name << OUTPUT_DELIMITER << "role: " << ROLES[role]
         << OUTPUT_DELIMITER << "score: " << setprecision(1) << calculate_avarage_score() << OUTPUT_DELIMITER
         << "cost: " << (int)price << OUTPUT_DELIMITER << "clean sheets: " << num_of_clean_sheets << endl;
}
