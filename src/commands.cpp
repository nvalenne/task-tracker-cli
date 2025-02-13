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

void Commands::updateTask(int id, string newTask){};
void Commands::deleteTask(int id){};

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