#ifndef _TASKS_H_
#define _TASKS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sqlite3.h>

typedef struct {
    int id;  // Unique ID (matches SQLite ID)
    char title[256]; // Task title string
    int completed;  // 0 = pending, 1 = complete
} Task;

void add_task(sqlite3 *db, const char *title);
void list_tasks(sqlite3 *db);
void mark_task_complete(sqlite3 *db, int id);
void delete_task(sqlite3 *db, int id);

#endif