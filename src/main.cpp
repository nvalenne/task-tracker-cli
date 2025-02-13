#include <iostream>
#include <vector>

#include "../include/commands.h"

using namespace std;

struct Arguments
{
    string command;
    vector<string> args;

    static vector<string> parseArgs(int argc, char *argsCli[])
    {
        vector<string> args;
        for (int i = 2; i < argc; i++)
        {
            args.push_back(argsCli[i]);
        }
        return args;
    };
};

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        cerr << "No command defined." << endl;
        return 1;
    }
    else
    {
        Arguments arguments{argv[1], arguments.parseArgs(argc, argv)};
        Commands commands;
        if (arguments.command == "add")
            commands.addTask(arguments.args[0]);
        else if (arguments.command == "update")
            commands.updateTask(stoi(arguments.args[0]), arguments.args[1]);
        else if (arguments.command == "delete")
            commands.deleteTask(stoi(arguments.args[0]));
        else if (arguments.command == "mark-in-progress")
            commands.updateTaskStatus(stoi(arguments.args[0]), "in-progress");
        else if (arguments.command == "mark-done")
            commands.updateTaskStatus(stoi(arguments.args[0]), "done");
        else if (arguments.command == "list")
        {
            if (arguments.args.empty()) commands.listTasks();
            else commands.listTasks(arguments.args[0]);
        }
        else
        {
            cerr << "Unknown command." << endl;
            return 1;
        }
        // for (int i = 0; i < arguments.args.size(); i++) cout << i << arguments.args[i] << endl;
    }
    return 0;
}