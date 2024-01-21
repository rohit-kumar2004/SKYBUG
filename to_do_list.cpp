
#include <iostream>
#include <vector>
#include <iomanip> // For setw()

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "Task List:\n";
    cout << setw(5) << "ID" << setw(20) << "Description" << setw(12) << "Status" << endl;
    cout << string(37, '-') << endl;

    for (int i = 0; i < tasks.size(); ++i) {
        cout << setw(5) << i + 1 << setw(20) << tasks[i].description << setw(12)
             << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }

    cout << endl;
}

// Function to mark a task as completed
void markAsCompleted(vector<Task>& tasks, int taskId) {
    if (taskId >= 1 && taskId <= tasks.size()) {
        tasks[taskId - 1].completed = true;
        cout << "Task marked as completed: " << tasks[taskId - 1].description << endl;
    } else {
        cout << "Invalid task ID. Please enter a valid ID.\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks, int taskId) {
    if (taskId >= 1 && taskId <= tasks.size()) {
        cout << "Task removed: " << tasks[taskId - 1].description << endl;
        tasks.erase(tasks.begin() + taskId - 1);
    } else {
        cout << "Invalid task ID. Please enter a valid ID.\n";
    }
}

int main() {
    vector<Task> tasks;

    char choice;
    string taskDescription;
    int taskId;

    do {
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter task description: ";
                cin.ignore(); // Clear buffer
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                cout << "Enter task ID to mark as completed: ";
                cin >> taskId;
                markAsCompleted(tasks, taskId);
                break;
            case '4':
                cout << "Enter task ID to remove: ";
                cin >> taskId;
                removeTask(tasks, taskId);
                break;
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != '5');

    return 0;
}
