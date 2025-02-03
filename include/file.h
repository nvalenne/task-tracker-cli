#include <vector>
#include <fstream>
#include <iostream>
#include "../include/task.h"

class JSON
{

public:
    std::vector<Task> parseJsonData();
    void writeToJsonData(Task t);
};