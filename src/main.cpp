#include <iostream>

#include "../include/commands.h"

using namespace std;

/**
 * @brief A structure to handle command-line arguments.
 *
 * This structure contains a command string and a vector of arguments.
 * It also provides a static method to parse command-line arguments.
 *
 */
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
    }
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
        try
        {
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
                if (arguments.args.empty())
                    // List all tasks (no status specified)
                    commands.listTasks();
                else
                    // List tasks filtered
                    commands.listTasks(arguments.args[0]);
            }
            else
            {
                throw runtime_error("Unknown command");
                return 1;
            }
        }
        catch (exception &e)
        {
            cerr << e.what() << endl;
            return 1;
        }
    }
    return 0;
}