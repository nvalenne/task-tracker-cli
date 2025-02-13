#include <vector>
#include <fstream>
#include <iostream>
#include "../include/task.h"

#ifndef PATH_FILE
#define PATH_FILE "data/tasks.json"
#endif

using namespace std;

class JSON
{

public:
    vector<Task> parseJsonData(const string& statusFilter = "");
    void writeToJsonFile(std::vector<Task> tasksArr);
};