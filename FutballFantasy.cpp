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
}

void FutballFantasy::run()
{
    handle_commands();
}

void FutballFantasy::read_cur_week_file(string folder_path, int cur_week_num)
{
    string cur_week_file_path = folder_path + "week_" + to_string(cur_week_num) + ".csv";
    vector<string> cur_week_info = read_file(cur_week_file_path);
    update_matches_vec(cur_week_info);
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

void FutballFantasy::pass_week()
{
    week_num++;
    read_cur_week_file(WEEKS_FOLDER_PATH, week_num);
}

void FutballFantasy::handle_commands()
{
    string request_type, command;
    while (cin >> request_type)
    {
        try
        {
            check_request_type(request_type);
            cin >> command;
            if (admin->is_logged_in())
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

void FutballFantasy::update_matches_vec(vector<string> file_elements)
{
    // level,base_salary,salary_per_hour,salary_per_extra_hour,official_working_hours,tax_percentage
    // vector<SalaryConfig *> salConfigs;
    // for (int i = 0; i < readFile.size() / SAL_CONFIGS_ATTR_COUNT; i++)
    // {
    //     string level = readFile[SAL_CONFIGS_ATTR_COUNT * i];
    //     int base_salary = stoi(readFile[SAL_CONFIGS_ATTR_COUNT * i + 1]);
    //     int salary_per_hour = stoi(readFile[SAL_CONFIGS_ATTR_COUNT * i + 2]);
    //     int salary_per_extra_hour = stoi(readFile[SAL_CONFIGS_ATTR_COUNT * i + 3]);
    //     int official_working_hours = stoi(readFile[SAL_CONFIGS_ATTR_COUNT * i + 4]);
    //     int tax_percentage = stoi(readFile[SAL_CONFIGS_ATTR_COUNT * i + 5]);
    //     salConfigs.push_back(new SalaryConfig(level, base_salary, salary_per_hour, salary_per_extra_hour, official_working_hours, tax_percentage));
    // }
    // return salConfigs;
}
