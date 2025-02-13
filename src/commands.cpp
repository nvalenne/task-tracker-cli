#include <algorithm>

#include "../include/commands.h"
#include "../include/file.h"
#include "../include/utils.h"

JSON jsonFile;

void Commands::addTask(string task)
{
    vector<Task> tasks = jsonFile.parseJsonData();
    struct Task t = {
        t.generateId(), // To replace by increment ID
        task,
        "todo",
        getNewDateToString(),
        getNewDateToString()};
    tasks.push_back(t);
    jsonFile.writeToJsonFile(tasks);
    cout << "Task added successfully (ID: " << t.id << ")" << endl;
}

void Commands::updateTask(int id, string newTask)
{
    vector<Task> tasks = jsonFile.parseJsonData();
    Task *taskToUpdate = nullptr;
    for (Task &t : tasks)
    {
        if (t.id == id)
        {
            taskToUpdate = &t;
            taskToUpdate->description = newTask;
            taskToUpdate->updatedAt = getNewDateToString();
            jsonFile.writeToJsonFile(tasks);
            cout << "Task updated successfully (ID: " << t.id << ")" << endl;
        }
    }
    // No task found
    if (taskToUpdate == nullptr)
    {
        throw runtime_error("Unable to find task");
    }
};

void Commands::deleteTask(int id)
{
    vector<Task> tasks = jsonFile.parseJsonData();
    bool tFound = false;
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].id == id)
        {
            tFound = true;
            tasks.erase(tasks.begin() + i);
        }
    }
    // No task found
    if (!tFound)
    {
        throw runtime_error("Unable to find task");
    }
    jsonFile.writeToJsonFile(tasks);
    cout << "Task deleted successfully" << endl;

};

void Commands::updateTaskStatus(int id, string newStatus)
{
    vector<Task> tasks = jsonFile.parseJsonData();
    Task *taskToUpdate = nullptr;
    for (Task &t : tasks)
    {
        if (t.id == id)
        {
            taskToUpdate = &t;
            taskToUpdate->status = newStatus;
            taskToUpdate->updatedAt = getNewDateToString();
            jsonFile.writeToJsonFile(tasks);
            cout << "Task mark as "<< newStatus << " successfully (ID: " << t.id << ")" << endl;
        }
    }
    // No task found
    if (taskToUpdate == nullptr)
    {
        throw runtime_error("Unable to find task");
    }
};

void Commands::listTasks(string statusFilter)
{
    const string status[3]{"todo", "in-progress", "done"};
    vector<Task> tasks;

    if (statusFilter == "all")
    {
        tasks = jsonFile.parseJsonData();
    }
    else if (find(begin(status), end(status), statusFilter) == end(status))
    {
        throw runtime_error("\"" + statusFilter + "\" is not a status known.");
    }
    else
        tasks = jsonFile.parseJsonData(statusFilter);

    // Prints the tasks
    if (tasks.empty())
    {
        cout << "No tasks found." << endl;
    }
    else
    {
        for (Task t : tasks)
        {
            cout << "Tâche n° " << t.id << " :" << endl
                 << "\tDescription: " << t.description << endl
                 << "\tStatus: " << t.status << endl
                 << "\tCreated at: " << t.createdAt << endl
                 << "\tUpdated at: " << t.updatedAt << endl
                 << "----" << endl;
        }
    }
};