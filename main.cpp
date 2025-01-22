#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void addTask(string descr)
{
    cout << "New task added !" << endl
         << "1 --> " << descr << endl;
}

void deleteTask() {};
void updateTask() {};
void listTasks() {};
void markAsInProgress() {};
void markAsDone() {};

int main(int argc, char const *argv[])
{
    try
    {
        if (!argv[1])
        {
            throw runtime_error("Please add a command");
        }
        else
        {
            string command = argv[1];
            if (command == "add")
            {
                if (!argv[2]) throw runtime_error("Please add a title for your task");
                else addTask(argv[2]);
            }
            else if (command == "update")
            {
            }
            else if (command == "delete")
            {
            }
            else if (command == "list")
            {
            }
            else if (command == "mark-in-progress")
            {
            }
            else if (command == "mark-in-done")
            {
            }
            else
            {
                throw runtime_error("Command unknown. Please retry");
            }
        }
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
