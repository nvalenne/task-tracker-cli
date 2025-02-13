#ifndef COMMANDS_H
#define COMMANDS_H
#endif

#include <string>
#include <vector>

using namespace std;

/**
 * @class Commands
 * @brief A class to manage tasks in the task tracker CLI.
 *
 * The Commands class provides methods to add, update, delete, and list tasks.
 * It allows for updating task descriptions and statuses, as well as listing tasks
 * based on their status.
 *
 */
class Commands
{
public:
    /**
     * @brief Create a new task
     * @param task Description of the task
     *
     */
    void addTask(string task);

    /**
     * @brief Update a task
     * @param id ID of the task to update
     * @param newTask New description to replace
     *
     */
    void updateTask(int i, string newTask);

    /**
     * @brief Delete a task
     * @param id ID of the task to delete
     *
     */
    void deleteTask(int id);

    /**
     * @brief Mark as "in-progress" or "done" the task identified by ID
     * @param id ID of the task to update
     *
     */
    void updateTaskStatus(int id, string status);

    /**
     * @brief Prints in the output stream by listing all the tasks or by status
     * @param statusFilter Status if filtering (default = "all")
     *
     */
    void listTasks(string statusFilter = "all");
};
