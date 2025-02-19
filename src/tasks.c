#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sqlite3.h>
#include "db.h"
#include "tasks.h"

void add_task(sqlite3 *db, const char *title) {
    const char *sql = "INSERT INTO TASKS (TITLE, COMPLETED) VALUES (?, 0);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, title, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        printf("Task added successfully.\n");
    } else {
        printf("Error adding task: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void list_tasks(sqlite3 *db) {
    const char *sql = "SELECT * FROM TASKS;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("ID | Title                     | Status\n");
    printf("----------------------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Task task; // Struct to store retrieved data
        task.id = sqlite3_column_int(stmt, 0);
        strncpy(task.title, (const char *)sqlite3_column_text(stmt, 1), 255);
        task.completed = sqlite3_column_int(stmt, 2);

        printf("%d  | %-25s | %s\n", task.id, task.title, task.completed ? "Done" : "Pending");
    }

    sqlite3_finalize(stmt);

}

void mark_task_complete(sqlite3 *db, int id) {
    printf("In the function, id is: %d\n", id);
}

// void delete_task(sqlite3 *db, int id) {

// }
