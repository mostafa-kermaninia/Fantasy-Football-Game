#include "Match.hpp"


Match::Match(int _week_num, string _team1_name, int _team1_goals, string _team2_name,int _team2_goals)
{
    week_num = _week_num;
    team1_name = _team1_name;
    team1_goals=_team1_goals;
    team2_name = _team2_name;
    team2_goals = _team2_goals;
}

void Match::print_match_info()
{
    cout << team1_name << " " << team1_goals << OUTPUT_DELIMITER << team2_name << " " << team2_goals << endl;
}

int Match::get_week_num()
{
    return week_num;
}
