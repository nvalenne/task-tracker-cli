#include <iostream>
#include <chrono>

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
        "to-do",
        getNewDateToString(),
        getNewDateToString()};
    tasks.push_back(t);
    jsonFile.writeToJsonFile(tasks);
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
        }
    }
    if (taskToUpdate == nullptr)
    {
        cerr << "Unable to find task" << endl;
    }
};

void Commands::deleteTask(int id)
{
    vector<Task> tasks = jsonFile.parseJsonData();
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].id == id) tasks.erase(tasks.begin() + i);
    }
    jsonFile.writeToJsonFile(tasks);
};

void Commands::marksAsInProgress(int id){};
void Commands::marksAsDone(int id){};
void Commands::listTasks(string status)
{
    vector<Task> tasks = jsonFile.parseJsonData();
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