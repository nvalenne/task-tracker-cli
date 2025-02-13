#include <fstream>
#include <iostream>
#include "../include/task.h"

#ifndef PATH_FILE
#define PATH_FILE "data/tasks.json"
#endif

using namespace std;

/**
 * @class JSON
 * @brief The class which allow to interact with the data file, by parsing and writing some data
 */
class JSON
{

public:
    /**
     * Parsing tasks.json content to store into a container
     *
     * @returns Container (std::vector) of all the tasks in JSON file
     */
    vector<Task> parseJsonData(const string &statusFilter = "");

    /**
     * Write or overwrite the current task into tasks.json
     *
     * @param t Task object
     */
    void writeToJsonFile(std::vector<Task> tasksArr);
};