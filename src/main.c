#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sqlite3.h>
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

    sqlite3 *db;
    //char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("todo.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

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
                char title[256];  // Allocate a fixed-size buffer
                printf("Enter the title of your task:\n");

                if (fgets(title, sizeof(title), stdin) == NULL) {
                    printf("Error reading input. Exiting.\n");
                } else {
                    title[strcspn(title, "\n")] = 0;  // Remove newline from input
                    add_task(db, title);
                }

                break;
            } 
            case(2): {
                printf("Your List: \n");
                list_tasks(db);
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
    sqlite3_close(db);
    return 0;
}

void display_menu() {
    printf("==============================\n");
    printf("TODO MENU\n");
    printf("---------------------\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Mark Task as Complete\n");
    printf("4. Delete Task\n");
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