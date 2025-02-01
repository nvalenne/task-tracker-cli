#include <iostream>
#include "../include/commands.h"

void Commands::addTask(string task)
{
    std::cout << "Task added : " << task << std::endl;
};
void Commands::updateTask(int id, string new_task)
{
    std::cout << "Task " << id << " updated : " << new_task << std::endl;
};
void Commands::deleteTask(int id)
{
    std::cout << "Task " << id << " deleted" << std::endl;
};
void Commands::marksAsInProgress(int id)
{
    std::cout << "Task " << id << " set to \"In progress\" " << std::endl;
};
void Commands::marksAsDone(int id)
{
    std::cout << "Task " << id << " set to \"Done\" " << std::endl;
};
void Commands::listTasks(string status) {
    std::cout << "List of tasks" << std::endl;
};