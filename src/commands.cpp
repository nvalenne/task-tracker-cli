#include <iostream>
#include <chrono>

#include "../include/commands.h"
#include "../include/file.h"

JSON jsonFile;

void Commands::addTask(string task)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::string time = ctime(&now_c);
    time.erase(time.find("\n"));
    struct Task t = {
        t.generateId(), // To replace by increment ID
        task,
        "to-do",
        time,
        time};
    jsonFile.writeToJsonData(t);
}


void Commands::updateTask(int id, string newTask)
{
    // vector<Task> tasks = jsonFile.parseJsonData();
    // Task *taskToUpdate = nullptr;
    // for (Task t : tasks)
    // {
    //     if (t.id == id)
    //         taskToUpdate = &t;
    // }
    // if (taskToUpdate != nullptr)
    // {
        
    // }
    // else
    // {
    //     cerr << "Unable to find task" << endl;
    // }
};
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