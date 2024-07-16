#include <stdio.h>
#include <string.h>

// Define Task and Project structures
typedef struct {
    char name[50];
    char assignedTo[50];
    int completed;
} Task;

typedef struct {
    char name[50];
    Task tasks[10];
    int taskCount;
} Project;

Project project;

char teamMembers[10][50];
int teamMemberCount = 0;

// Function to add a task to the project
void addTask() {
    if (project.taskCount >= 10) {
        printf("Task limit reached.\n");
        return;
    }

    // Get task details from the user
    printf("Enter task name: ");
    scanf(" %[^\n]s", project.tasks[project.taskCount].name);
    printf("Enter team member to assign task: ");
    scanf(" %[^\n]s", project.tasks[project.taskCount].assignedTo);
    project.tasks[project.taskCount].completed = 0;
    project.taskCount++;
    printf("Task added successfully.\n");
}

// Function to add a team member to the project
void addTeamMember() {
    if (teamMemberCount >= 10) {
        printf("Team member limit reached.\n");
        return;
    }

    // Get team member name from the user
    printf("Enter team member name: ");
    scanf(" %[^\n]s", teamMembers[teamMemberCount]);
    teamMemberCount++;
    printf("Team member added successfully.\n");
}

// Function to view details of the project
void viewDetails() {
    for (int i = 0; i < project.taskCount; i++) {
        printf("Task %d: %s\n", i + 1, project.tasks[i].name);
        printf("Assigned to: %s\n", project.tasks[i].assignedTo);
        printf("Status: %s\n", project.tasks[i].completed ? "Completed" : "Incomplete");
    }
    if (teamMemberCount != 0) {
        printf("Additional Team Members:\n");
        for (int i = 0; i < teamMemberCount; i++) {
            printf("%s\n", teamMembers[i]);
        }
    }
}

// Function to view only the task names
void viewTasks() {
    for (int i = 0; i < project.taskCount; i++) {
        printf("Task %d: %s\n", i + 1, project.tasks[i].name);
    }
}

// Function to mark a task as complete
void markTaskAsComplete() {
    viewTasks();
    int taskNumber;
    printf("Enter task number to mark as complete: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > project.taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    project.tasks[taskNumber - 1].completed = 1;
    printf("Task marked as complete.\n");
}


int main() {
    // Initialize the project
    printf("Enter project name: ");
    scanf(" %[^\n]s", project.name);
    project.taskCount = 0;

    int choice;
    do {
        // Print the menu options
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Add Team Member\n");
        printf("3. View Details\n");
        printf("4. Mark Task as Complete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Handle the user's menu choice
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                addTeamMember();
                break;
            case 3:
                viewDetails();
                break;
            case 4:
                markTaskAsComplete();
                break;
            case 5:
                printf("EXITING...\n");
                break;
            default:
                printf("invalid choice, please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
