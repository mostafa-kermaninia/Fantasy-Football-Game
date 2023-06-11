#include "GoalKeeper.hpp"

GoalKeeper::GoalKeeper(string _name_and_price)
    : Player(_name_and_price, GK)
{
}

GoalKeeper::~GoalKeeper()
{
}

GoalKeeper *GoalKeeper::clone()
{
    return new GoalKeeper(*this);
}

void GoalKeeper::calculate_raw_score(vector<Player *> own_goalers, vector<Player *> assisters, vector<Player *> goal_scorers, MATCH_RESULT result)
{
    raw_point = INITIAL_GK_POINT;
    raw_point += result;
    
    
}

void GoalKeeper::print_info(int player_num)
{
    cout << fixed;
    cout << player_num << ". name: " << name << OUTPUT_DELIMITER << "role: " << ROLES[role]
         << OUTPUT_DELIMITER << "score: " << setprecision(1) << calculate_avarage_score() << endl
         << OUTPUT_DELIMITER << "cost: " << price << OUTPUT_DELIMITER << "clean sheets: " << num_of_clean_sheets << endl;
}
