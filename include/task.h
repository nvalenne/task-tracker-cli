#include <string>
#include <vector>

using namespace std;

/**
 * @struct Task
 * @brief Following properties which defines a task
 */
struct Task
{
    int id;
    string description;
    string status;
    string createdAt;
    string updatedAt;

    /**
     * @brief Generate increment ID for a new task
     *
     * @returns The new generated ID
     */
    int generateId();

    /**
     * @brief Extract value of a property given by attr
     *
     * @param taskObj stringified task object
     * @param attr property key
     *
     * @return Value of the property
     */
    string getValuePropertyFromTask(string taskObj, string attr);
};
