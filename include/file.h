#include <vector>
#include <fstream>
#include <iostream>
#include "../include/task.h"

#ifndef PATH_FILE
#define PATH_FILE "data/tasks.json"
#endif

class JSON
{

public:
    std::vector<Task> parseJsonData();
    void writeToJsonFile(std::vector<Task> tasksArr);
};