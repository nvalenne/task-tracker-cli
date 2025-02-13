#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Commands {
    public:
        void addTask(string task);
        void updateTask(int i, string newTask);
        void deleteTask(int id);
        void updateTaskStatus(int id, string status);
        void listTasks(string status = "all");
};

#endif