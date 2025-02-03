#include "../include/file.h"
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Generate increment ID for a new task
 *
 * @param tasks_length the number of tasks without the new task
 * @returns the new generated ID
 */
int Task::generateId(size_t tasks_length)
{
    if (tasks_length == 0)
        return 1;
    else
        return tasks_length + 1;
}

/**
 * Extract value of a property given by attr
 *
 * @param taskObj stringified task object
 * @param attr property key
 *
 * @returns value of the property
 */
string getValuePropertyFromTask(string taskObj, string attr)
{
    size_t firstIndex = taskObj.find(attr);
    size_t lastIndex = taskObj.find(",", firstIndex);

    int sizeKey = 2 + attr.size();
    string attrValue = taskObj.substr(firstIndex + sizeKey, lastIndex - firstIndex - sizeKey);

    return attrValue;
};

/**
 * Parsing tasks.json content to store into a container
 *
 * @returns tasks
 */
vector<Task> JSON::parseJsonData()
{
    ifstream jsonFile("data/tasks.json");
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

            tasks.push_back(t);
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
void JSON::writeToJsonData(Task task)
{
    string filename = "data/tasks.json";
    ifstream jsonFile(filename);
    ostringstream buffer;

    if (jsonFile.is_open()) {
        buffer << jsonFile.rdbuf();
        jsonFile.close();
    }

    string jsonData = buffer.str();

    if (jsonData.empty()) {
        jsonData = "[\n";
    } else {
        // Erase ] to insert the new task
        size_t pos = jsonData.rfind("]");
        if (pos != string::npos) {
            jsonData.erase(pos);
        }
        // Add comma if not first element
        if (jsonData.length() > 2) {
            jsonData += ",\n";
        }
    }

    string taskJson =
        "  {\n"
        "    \"id\": " + to_string(task.id) + ",\n"
        "    \"description\": \"" + task.description + "\",\n"
        "    \"status\": \"" + task.status + "\",\n"
        "    \"createdAt\": \"" + task.createdAt + "\",\n"
        "    \"updatedAt\": \"" + task.updatedAt + "\"\n"
        "  }";
    
    // Add the task and close array
    jsonData += taskJson + "\n]";

    // Overwrite the file with the updated data
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << jsonData;
        outFile.close();
        cout << "Task added successfully!\n";
    } else {
        cerr << "Error opening file for writing!\n";
    }
}