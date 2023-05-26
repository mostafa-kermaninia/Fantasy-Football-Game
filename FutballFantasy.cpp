#include "FutballFantasy.hpp"

FutballFantasy::FutballFantasy(string league_file_path)
{
    read_league_file(league_file_path);
    admin = new Admin("admin", "123456");
    week_num = 0;
}

FutballFantasy::~FutballFantasy()
{
    for (User *user : users)
        delete user;
    for (Match *match : matches)
        delete match;
    for (Player *player : players)
        delete player;
    for (Team *team : teams)
        delete team;
    for (Team *week_team : week_teams)
        delete week_team;
}

void FutballFantasy::run()
{
    handle_commands();
}

void FutballFantasy::read_cur_week_file(string folder_path, int cur_week_num)
{
    string cur_week_file_path = folder_path + "week_" + to_string(cur_week_num) + ".csv";
    vector<string> cur_week_info = read_file(cur_week_file_path);
    for (int i = 0; i < cur_week_info.size() / WEEK_FILE_HEADERS_COUNT; i++)
    {
        update_matches_vec(cur_week_info[WEEK_FILE_HEADERS_COUNT * i], cur_week_info[WEEK_FILE_HEADERS_COUNT * i + 1]);
        update_teams_vec(cur_week_info[WEEK_FILE_HEADERS_COUNT * i], cur_week_info[WEEK_FILE_HEADERS_COUNT * i + 1]);
        update_players_vec(cur_week_info[WEEK_FILE_HEADERS_COUNT * i + 2], cur_week_info[WEEK_FILE_HEADERS_COUNT * i + 3],
                           cur_week_info[WEEK_FILE_HEADERS_COUNT * i + 4], cur_week_info[WEEK_FILE_HEADERS_COUNT * i + 5]);
    }
}

void FutballFantasy::read_league_file(string file_path)
{
    vector<string> file_info = read_file(file_path);
    build_objects(file_info);
}

void FutballFantasy::build_objects(vector<string> elements)
{
    for (int i = 0; i < elements.size() / LEAGUE_FILE_HEADERS_COUNT; i++)
    {
        string team_name = elements[LEAGUE_FILE_HEADERS_COUNT * i];

        vector<Player *> team_players;
        for (string player_name : string_splitter(elements[LEAGUE_FILE_HEADERS_COUNT * i + 1], ';'))
            team_players.push_back(new Player(player_name, GK));
        for (string player_name : string_splitter(elements[LEAGUE_FILE_HEADERS_COUNT * i + 2], ';'))
            team_players.push_back(new Player(player_name, DF));
        for (string player_name : string_splitter(elements[LEAGUE_FILE_HEADERS_COUNT * i + 3], ';'))
            team_players.push_back(new Player(player_name, MD));
        for (string player_name : string_splitter(elements[LEAGUE_FILE_HEADERS_COUNT * i + 4], ';'))
            team_players.push_back(new Player(player_name, FW));

        teams.push_back(new Team(team_name, team_players));
    }
}

void FutballFantasy::check_request_type(string request_type)
{
    if (request_type != "GET" && request_type != "POST" && request_type != "PUT" && request_type != "DELETE")
        throw runtime_error("Bad Request");
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

void FutballFantasy::pass_week()
{
    week_num++;
    if (week_num > COUNT_OF_WEEKS)
        throw runtime_error("out of timmmmmmme");
    read_cur_week_file(WEEKS_FOLDER_PATH, week_num);
}

void FutballFantasy::handle_commands()
{
    for (auto t : teams)
        t->print_team(NO_ROLE);
    cout << teams.size() << endl;
    string request_type, command;
    while (cin >> request_type)
    {
        try
        {
            check_request_type(request_type);
            cin >> command;
            if (!admin->is_logged_in())
            {
                if (command == "pass_week")
                {
                    pass_week();
                }
                else if (command == "add_distance_mission")
                {
                    // cin >> missionId >> startTimestamp >> endTimestamp >> targetDistanceInMeters >> rewardAmount;
                    // if (cin.fail())
                    //     throw runtime_error("INVALID_ARGUMENTS");
                    // addDistanceMission(missionId, startTimestamp, endTimestamp, targetDistanceInMeters, rewardAmount);
                }
                else
                {
                    throw runtime_error("Bad Request");
                }
            }
            else
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
                else
                {
                    throw runtime_error("Bad Request");
                }
            }
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
        if (m->get_week_num() == showing_week_num)
            m->print_match_info();
}

Player *FutballFantasy::find_player_by_name(string name)
{
    for (int i = 0; i < players.size(); i++)
        if (players[i]->get_name() == name)
            return players[i];
    return nullptr;
}

Team *FutballFantasy::find_team_by_name(string name)
{
    for (int i = 0; i < teams.size(); i++)
        if (teams[i]->get_name() == name)
            return teams[i];
    return nullptr;
}

void FutballFantasy::update_winner_and_loser_team_info(Team *team1, int team1_goals, Team *team2, int team2_goals)
{
    if (team1_goals > team2_goals)
    {
        team1->add_to_total_score(WINNER_SCORE_INCREMENT);
        team2->add_to_total_score(LOSER_SCORE_INCREMENT);
    }
    else if (team1_goals == team2_goals)
    {
        team1->add_to_total_score(EQUALIZED_SCORE_INCREMENT);
        team2->add_to_total_score(EQUALIZED_SCORE_INCREMENT);
    }
    else if (team1_goals < team2_goals)
    {
        team1->add_to_total_score(LOSER_SCORE_INCREMENT);
        team2->add_to_total_score(WINNER_SCORE_INCREMENT);
    }
    team1->add_to_goals_for(team1_goals);
    team2->add_to_goals_for(team2_goals);
    team1->add_to_goals_against(team2_goals);
    team2->add_to_goals_against(team1_goals);
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
        if (lineOfFile[lineOfFile.size() - 1] == '\r')
            lineOfFile = lineOfFile.substr(0, lineOfFile.size() - 1);
        istringstream line(lineOfFile);
        string fileElement;
        while (getline(line, fileElement, ','))
            readFile.push_back(fileElement);
    }
    inputFile.close();
    return readFile;
}

void FutballFantasy::update_matches_vec(string team_names, string result)
{
    vector<string> teams_names = string_splitter(team_names, ':');
    string team1_name = teams_names[0];
    string team2_name = teams_names[1];
    vector<string> teams_goals = string_splitter(result, ':');
    int team1_goals = stoi(teams_goals[0]);
    int team2_goals = stoi(teams_goals[1]);
    matches.push_back(new Match(week_num, team1_name, team1_goals, team2_name, team2_goals));
}

void FutballFantasy::update_teams_vec(string team_names, string result)
{
    string team1_name = string_splitter(team_names, ':')[0];
    string team2_name = string_splitter(team_names, ':')[1];
    Team *team1 = find_team_by_name(team1_name);
    Team *team2 = find_team_by_name(team2_name);
    int team1_goals = stoi(string_splitter(result, ':')[0]);
    int team2_goals = stoi(string_splitter(result, ':')[1]);
    update_winner_and_loser_team_info(team1, team1_goals, team2, team2_goals);
}

void FutballFantasy::update_players_vec(string injureds, string yellow_cards, string red_cards, string scores)
{
    vector<string> injured_players = string_splitter(injureds, ';');
    vector<string> yellow_card_reciever_players = string_splitter(yellow_cards, ';');
    vector<string> red_card_reciever_players = string_splitter(red_cards, ';');
    vector<string> score_of_players = string_splitter(red_cards, ';');

    for (int i = 0; i < injured_players.size(); i++)
        find_player_by_name(injured_players[i])->set_when_injured(week_num);
    for (int i = 0; i < yellow_card_reciever_players.size(); i++)
        find_player_by_name(yellow_card_reciever_players[i])->add_to_yellow_cards();
    for (int i = 0; i < red_card_reciever_players.size(); i++)
        find_player_by_name(red_card_reciever_players[i])->add_to_red_cards();
    for (int i = 0; i < score_of_players.size(); i++)
    {
        vector<string> name_and_score;
        find_player_by_name((name_and_score[0]))->add_to_score(stoi(name_and_score[1]));
    }
}
