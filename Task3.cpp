#include <iostream>
#include <vector>
#include <string>

// Structure to represent a single task
struct Task {
    std::string description;
    bool isCompleted;
};

// Function prototypes
void displayMenu();
void addTask(std::vector<Task>& todoList);
void viewTasks(const std::vector<Task>& todoList);
void markTaskComplete(std::vector<Task>& todoList);
void deleteTask(std::vector<Task>& todoList);

int main() {
    std::vector<Task> todoList;
    int choice;

    std::cout << "=== Welcome to Your C++ To-Do List ===\n";

    do {
        displayMenu();
        std::cout << "Enter your choice (1-5): ";
        
        // Input validation for integer choices
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cin.ignore(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                addTask(todoList);
                break;
            case 2:
                viewTasks(todoList);
                break;
            case 3:
                markTaskComplete(todoList);
                break;
            case 4:
                deleteTask(todoList);
                break;
            case 5:
                std::cout << "\nGoodbye! Keep staying productive.\n";
                break;
            default:
                std::cout << "Invalid option. Please choose a valid menu item.\n";
        }
    } while (choice != 5);

    return 0;
}

// Displays the interactive menu options
void displayMenu() {
    std::cout << "\n-----------------------\n";
    std::cout << "1. Add a Task\n";
    std::cout << "2. View All Tasks\n";
    std::cout << "3. Mark Task as Complete\n";
    std::cout << "4. Delete a Task\n";
    std::cout << "5. Exit Application\n";
    std::cout << "-----------------------\n";
}

// Adds a new task to the vector
void addTask(std::vector<Task>& todoList) {
    std::string taskDesc;
    std::cout << "Enter the task description: ";
    std::getline(std::cin, taskDesc);
    
    if (!taskDesc.empty()) {
        todoList.push_back({taskDesc, false});
        std::cout << "Task successfully added!\n";
    } else {
        std::cout << "Task description cannot be empty.\n";
    }
}

// Displays all current tasks with their status
void viewTasks(const std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "\nYour to-do list is empty!\n";
        return;
    }

    std::cout << "\n--- Current Tasks ---\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        std::cout << i + 1 << ". [";
        if (todoList[i].isCompleted) {
            std::cout << "X"; // Marked complete
        } else {
            std::cout << " "; // Pending
        }
        std::cout << "] " << todoList[i].description << "\n";
    }
}

// Marks a specific task as complete based on its index
void markTaskComplete(std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "\nNo tasks available to mark complete.\n";
        return;
    }

    viewTasks(todoList);
    size_t taskNumber;
    std::cout << "Enter the number of the task you completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= todoList.size()) {
        todoList[taskNumber - 1].isCompleted = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

// Removes a task entirely from the list
void deleteTask(std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "\nNo tasks available to delete.\n";
        return;
    }

    viewTasks(todoList);
    size_t taskNumber;
    std::cout << "Enter the number of the task you want to delete: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= todoList.size()) {
        todoList.erase(todoList.begin() + (taskNumber - 1));
        std::cout << "Task successfully deleted.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}