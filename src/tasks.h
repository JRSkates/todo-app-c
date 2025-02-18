#ifndef _TASKS_H_
#define _TASKS_H_

typedef struct {
    int id;  // Unique ID (matches SQLite ID)
    char title[256]; // Task title string
    int completed;  // 0 = pending, 1 = complete
} Task;

void add_task(const char *title);
void list_tasks();
void mark_task_complete(int id);
void delete_task(int id);

#endif