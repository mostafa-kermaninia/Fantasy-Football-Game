#include "FutballFantasy.hpp"

FutballFantasy::FutballFantasy(string weeks_folder_path, int count_of_weeks, string info_file_path)
{
    read_weeks_folder(weeks_folder_path,count_of_weeks);
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
