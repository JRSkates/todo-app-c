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

void list_tasks() {

}
void mark_task_complete(int id) {

}

void delete_task(int id) {

}
