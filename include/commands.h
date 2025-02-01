#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Commands {
    public:
        void addTask(string task);
        void updateTask(int i, string new_task);
        void deleteTask(int id);
        void marksAsInProgress(int id);
        void marksAsDone(int id);
        void listTasks(string status = "all");
};

#endif