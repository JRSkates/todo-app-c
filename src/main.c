#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "db.h"
#include "tasks.h"

void display_menu();
int validate_number(const char *input);

int main() {
    printf("Welcome to the To-Do App!\n");
    display_menu();
    char selection[5];
    int user_choice;
    int running = 1;
    while (running == 1) {

        // Read input using fgets
        if (fgets(selection, sizeof(selection), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Validate the input
        if (!validate_number(selection)) {
            printf("Invalid input. Please enter a number.\n");
            continue; // Prompt the menu again
        }

        // Convert the validated input to an integer
        user_choice = atoi(selection);

        switch (user_choice) {
            case(1): {
                printf("Add Task\n");
                //add_task(const char *title);
                break;
            } 
            case(2): {
                printf("List Tasks\n");
                //list_tasks();
                break;
            }
            case(3): {
                printf("Mark Task as Complete\n");
                //list_tasks();
                // mark_task_complete(int id);
                break;
            } 
            case(4): {
                printf("Delete Task\n");
                //list_tasks();
                // delete_task(int id);
                break;
            }
            case(5): {
                printf("Goodbye!\n");
                running = 0;
                break;
            } 
            default: {
                printf("Invalid Selection\n");
                break;
            }
        }
    }
    return 0;
}

void display_menu() {
    printf("==============================\n");
    printf("TODO MENU\n");
    printf("---------------------\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Mark Task as Complete\n");
    printf("2. Delete Task\n");
    printf("5. Exit\n");
    printf("==============================\n");
}

int validate_number(const char *input) {
    // Check if the input is a valid number
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i]) && input[i] != '\n') {
            return 0; // Not a valid number
        }
    }
    return 1; // Valid number
}