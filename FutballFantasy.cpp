#include "FutballFantasy.hpp"

FutballFantasy::FutballFantasy(string weeks_folder_path, int count_of_weeks, string info_file_path)
{
    read_weeks_folder(weeks_folder_path, count_of_weeks);
    read_info_file(info_file_path);
}

FutballFantasy::~FutballFantasy()
{
}

void FutballFantasy::run()
{
    handle_commands();
}

void FutballFantasy::read_weeks_folder(string folder_path, int files_count)
{
}

void FutballFantasy::read_info_file(string file_path)
{
}

void FutballFantasy::add_week_team()
{
    vector<Player *> best_players;
    vector<Player *> goal_keeper = find_bests(GK);
    vector<Player *> defenders = find_bests(DF);
    vector<Player *> midfielder = find_bests(MD);
    vector<Player *> forward = find_bests(FW);
    for (auto g : goal_keeper)
        best_players.push_back(g);
    for (auto d : defenders)
        best_players.push_back(d);
    for (auto m : midfielder)
        best_players.push_back(m);
    for (auto f : forward)
        best_players.push_back(f);
    Team *new_week_team = new Team(best_players);
    week_teams.push_back(new_week_team);
}

vector<Player *> FutballFantasy::find_bests(ROLE r)
{
    vector<Player *> chosen_players;
    int choose_limit = 1;
    if (r == DF)
        choose_limit++;
    for (int i = 0; i < players.size(); i++)
    {
        if (r == players[i]->get_role())
        {
            if (chosen_players.size() < choose_limit)
            {
                Player *adding_player = players[i]->clone();
                chosen_players.push_back(adding_player);
            }
            else if (better_than_chosen_players(chosen_players, players[i]))
            {
                Player *adding_player = players[i]->clone();
                chosen_players.pop_back();
                chosen_players.push_back(adding_player);
            }
        }
        if (r == DF && chosen_players.size() == choose_limit && chosen_players[0]->get_score() > chosen_players[1]->get_score())
        {
            Player *swaped_player = chosen_players[0];
            chosen_players[0] = chosen_players[1];
            chosen_players[1] = swaped_player;
        }
    }
    return chosen_players;
}

bool FutballFantasy::better_than_chosen_players(vector<Player *> choosen_players, Player *new_player)
{
    for (auto p : choosen_players)
    {
        if (p->get_score() < new_player->get_score())
            return true;
    }
    return false;
}

void FutballFantasy::handle_commands()
{
    string command;
    int a, b;
    while (cin >> command)
    {
        try
        {
            if (command == "add_time_mission")
            {
                // cin >> missionId >> startTimestamp >> endTimestamp >> targetTimeInMinutes >> rewardAmount;
                // if (cin.fail())
                //     throw runtime_error("INVALID_ARGUMENTS");
                // addTimeMission(missionId, startTimestamp, endTimestamp, targetTimeInMinutes, rewardAmount);
            }
            else if (command == "add_distance_mission")
            {
                // cin >> missionId >> startTimestamp >> endTimestamp >> targetDistanceInMeters >> rewardAmount;
                // if (cin.fail())
                //     throw runtime_error("INVALID_ARGUMENTS");
                // addDistanceMission(missionId, startTimestamp, endTimestamp, targetDistanceInMeters, rewardAmount);
            }
            else if (command == "add_count_mission")
            {
                // cin >> missionId >> startTimestamp >> endTimestamp >> targetNumber >> rewardAmount;
                // if (cin.fail())
                //     throw runtime_error("INVALID_ARGUMENTS");
                // addCountMission(missionId, startTimestamp, endTimestamp, targetNumber, rewardAmount);
            }
            else if (command == "assign_mission")
            {
                // cin >> missionId >> driverId;
                // if (cin.fail())
                //     throw runtime_error("INVALID_ARGUMENTS");
                // assignMission(missionId, driverId);
            }
            else if (command == "record_ride")
            {
                // cin >> startTimestamp >> endTimestamp >> driverId >> distance;
                // if (cin.fail())
                //     throw runtime_error("INVALID_ARGUMENTS");
                // recordRide(startTimestamp, endTimestamp, driverId, distance);
            }
            else if (command == "show_missions_status")
            {
                // cin >> driverId;
                // if (cin.fail())
                //     throw runtime_error("INVALID_ARGUMENTS");
                // showMissionsStatus(driverId);
            }
            else
                throw runtime_error("INVALID COMMAND");
        }
        catch (const std::runtime_error &e)
        {
            cout << e.what() << '\n';
        }
        cin.clear();
    }
}

void FutballFantasy::print_week_team(int week_number)
{
    int showing_week_num = week_num - 1;
    if (week_number != THIS_WEEK)
        showing_week_num = week_number - 1;
    vector<Player *> week_team_players = week_teams[showing_week_num]->get_players();
    cout << "GoalKeeper: " << week_team_players[0]->get_name() << OUTPUT_DELIMITER << "score: " << week_team_players[0]->get_score() << endl;
    cout << "Defender 1: " << week_team_players[0]->get_name() << OUTPUT_DELIMITER << "score: " << week_team_players[0]->get_score() << endl;
    cout << "Defender 2: " << week_team_players[0]->get_name() << OUTPUT_DELIMITER << "score: " << week_team_players[0]->get_score() << endl;
    cout << "Midfielder: " << week_team_players[0]->get_name() << OUTPUT_DELIMITER << "score: " << week_team_players[0]->get_score() << endl;
    cout << "Forward: " << week_team_players[0]->get_name() << OUTPUT_DELIMITER << "score: " << week_team_players[0]->get_score() << endl;
}

void FutballFantasy::print_week_matches(int week_number)
{
    int showing_week_num = week_num;
    if (week_number != THIS_WEEK)
        showing_week_num = week_number;
    for (auto m : matches)
        if(m->get_week_num() == showing_week_num)
            m->print_match_info();
}

vector<string> FutballFantasy::string_splitter(string text, char splitter)
{
    string word = "";
    vector<string> words;
    for (int i = 0; i <= text.size(); i++)
    {
        if (text[i] == splitter || text[i] == '\0' || text[i] == '\n')
        {
            words.push_back(word);
            word = "";
        }
        else
            word += text[i];
    }
    return words;
}

vector<string> FutballFantasy::read_file(string filePath)
{
    vector<string> readFile;
    ifstream inputFile(filePath);
    string lineOfFile;
    getline(inputFile, lineOfFile);
    while (getline(inputFile, lineOfFile))
    {
        // if (lineOfFile[lineOfFile.size() - 1] == '\r')
        //     lineOfFile = lineOfFile.substr(0, lineOfFile.size() - 1);
        istringstream line(lineOfFile);
        string fileElement;
        while (getline(line, fileElement, ','))
            readFile.push_back(fileElement);
    }
    inputFile.close();
    return readFile;
}
