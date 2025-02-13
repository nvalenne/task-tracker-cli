#include "../include/file.h"

using namespace std;

/**
 * Extract value of a property given by attr
 *
 * @param taskObj stringified task object
 * @param attr property key
 *
 * @return Value of the property
 */
string getValuePropertyFromTask(string taskObj, string attr)
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

/**
 * Parsing tasks.json content to store into a container
 *
 * @returns Container (std::vector) of all the tasks in JSON file
 */
vector<Task> JSON::parseJsonData(const string& statusFilter)
{
    ifstream jsonFile(PATH_FILE);
    vector<Task> tasks;

    string line, f_text;
    while (getline(jsonFile, line))
    {
        f_text.append(line);
    }

    size_t firstBracketIndex = f_text.find("[");
    size_t lastBracketIndex = f_text.find_last_of("]");

    for (int i = firstBracketIndex; i < lastBracketIndex; i++)
    {
        // If task found
        if (f_text[i] == '{')
        {
            size_t nextBrace = f_text.find('}', i);
            string taskObj = f_text.substr(i, nextBrace - i); // Substract the task object

            Task t;
            t.id = stoi(getValuePropertyFromTask(taskObj, "id"));
            t.description = getValuePropertyFromTask(taskObj, "description");
            t.status = getValuePropertyFromTask(taskObj, "status");
            t.createdAt = getValuePropertyFromTask(taskObj, "createdAt");
            t.updatedAt = getValuePropertyFromTask(taskObj, "updatedAt");

            if (statusFilter.empty()) tasks.push_back(t);
            else if (t.status == statusFilter) tasks.push_back(t);
        }
    }

    jsonFile.close();
    return tasks;
}

/**
 * Write or overwrite the current task into tasks.json
 *
 * @param t Task object
 */
void JSON::writeToJsonFile(vector<Task> tasksArr)
{
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

/**
 * Generate increment ID for a new task
 *
 * @returns The new generated ID
 */
int Task::generateId()
{
    JSON json;
    // size_t tasks_length = json.parseJsonData().size();
    // if (tasks_length == 0)
    //     return 1;
    // else
    //     return tasks_length + 1;
    vector<Task> tasks = json.parseJsonData();
    int idMax = 0;
    if (tasks.empty()) return 1;
    for (Task t : tasks) {
        if (idMax < t.id) idMax = t.id;
    }
    return idMax+1;
}