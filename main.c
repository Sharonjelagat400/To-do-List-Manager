#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 50

struct Task {
    char description[MAX_LENGTH];
    int completed;
};

struct Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(const char *description) {
    if (numTasks < MAX_TASKS) {
        strcpy(tasks[numTasks].description, description);
        tasks[numTasks].completed = 0;
        numTasks++;
        printf("Task added successfully!\n");
    } else {
        printf("Cannot add task. Task list is full.\n");
    }
}

void viewTasks() {
    printf("To-Do List:\n");
    if (numTasks == 0) {
        printf("No tasks.\n");
    } else {
        for (int i = 0; i < numTasks; i++) {
            printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
        }
    }
}

void completeTask(int index) {
    if (index >= 1 && index <= numTasks) {
        tasks[index - 1].completed = 1;
        printf("Task marked as complete!\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void deleteTask(int index) {
    if (index >= 1 && index <= numTasks) {
        for (int i = index - 1; i < numTasks - 1; i++) {
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }
        numTasks--;
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid task index.\n");
    }
}

int main() {
    int choice;
    char description[MAX_LENGTH];
    int index;

    do {
        printf("\nTo-Do List Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Complete\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                getchar(); // Consume newline character from previous input
                fgets(description, MAX_LENGTH, stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove trailing newline character
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter task index to mark as complete: ");
                scanf("%d", &index);
                completeTask(index);
                break;
            case 4:
                printf("Enter task index to delete: ");
                scanf("%d", &index);
                deleteTask(index);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
