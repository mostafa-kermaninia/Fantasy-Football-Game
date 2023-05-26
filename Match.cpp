#include "Match.hpp"

Match::Match(/* args */)
{
}

Match::~Match()
{
}

void Match::print_match_info()
{
    cout << team1_name << " " << team1_goals << OUTPUT_DELIMITER << team2_name << " " << team2_goals << endl;
}

int Match::get_week_num()
{
    return week_num;
}
