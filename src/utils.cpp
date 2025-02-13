#include "../include/utils.h"

std::string getNewDateToString() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::string time = ctime(&now_c);
    time = time.erase(time.find("\n"));

    return time;
}