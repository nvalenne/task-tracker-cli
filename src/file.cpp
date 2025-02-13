#include "../include/file.h"

using namespace std;

string Task::getValuePropertyFromTask(string taskObj, string attr)
{
    size_t firstIndex = taskObj.find(attr);
    size_t lastIndex = taskObj.find(",", firstIndex);

    // if it's last one property (no comma found), last index is at the last quote
    if (lastIndex == string::npos) lastIndex = taskObj.size()-1;
    int sizeKey = 2 + attr.size();

    string attrValue;
    // case which "id" value has not quotes
    if (attr == "id") attrValue = taskObj.substr(firstIndex + sizeKey, lastIndex - firstIndex - sizeKey);
    else attrValue = taskObj.substr(firstIndex + sizeKey + 2, lastIndex - firstIndex - sizeKey - 3);

    return attrValue;
};

vector<Task> JSON::parseJsonData(const string& statusFilter)
{
    ifstream jsonFile(PATH_FILE);
    vector<Task> tasks;

    string line, f_text;
    while (getline(jsonFile, line))
    {
        f_text.append(line);
    }

    // Work with the content of the json array
    size_t firstBracketIndex = f_text.find("[");
    size_t lastBracketIndex = f_text.find_last_of("]");

    for (int i = firstBracketIndex; i < lastBracketIndex; i++)
    {
        // For each task found
        if (f_text[i] == '{')
        {
            size_t nextBrace = f_text.find('}', i);
            string taskObj = f_text.substr(i, nextBrace - i); // Get the task object

            Task t;

            // Get all the values to store in a Task object
            t.id = stoi(t.getValuePropertyFromTask(taskObj, "id"));
            t.description = t.getValuePropertyFromTask(taskObj, "description");
            t.status = t.getValuePropertyFromTask(taskObj, "status");
            t.createdAt = t.getValuePropertyFromTask(taskObj, "createdAt");
            t.updatedAt = t.getValuePropertyFromTask(taskObj, "updatedAt");

            // Filtering tasks (or not)
            if (statusFilter.empty()) tasks.push_back(t);
            else if (t.status == statusFilter) tasks.push_back(t);
        }
    }

    jsonFile.close();
    return tasks;
}

void JSON::writeToJsonFile(vector<Task> tasksArr)
{
    // Rewrite all the tasks in the file PATH_FILE
    ofstream file(PATH_FILE);
    
    string new_content = "[\n";
    for (int i = 0; i < tasksArr.size(); i++) {
        Task t = tasksArr[i];
        new_content.append(
            "\t{\n"
            "\t\t\"id\": " + to_string(t.id) + ",\n"
            "\t\t\"description\": \"" + t.description + "\",\n"
            "\t\t\"status\": \"" + t.status + "\",\n"
            "\t\t\"createdAt\": \"" + t.createdAt + "\",\n"
            "\t\t\"updatedAt\": \"" + t.updatedAt + "\"\n"
            "\t}"
        );
        if (i+1 != tasksArr.size()) new_content.append(",\n");
        else new_content.append("\n]");
    }
    file << new_content;
    file.close();
}   

int Task::generateId()
{
    // Get the higher ID existing, return ID + 1
    JSON json;
    vector<Task> tasks = json.parseJsonData();
    int idMax = 0;
    if (tasks.empty()) return 1; // If no task exists

    // Maximum search algorithm
    for (Task t : tasks) {
        if (idMax < t.id) idMax = t.id;
    }
    return idMax+1;
}