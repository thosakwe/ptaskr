#include <string.h>
#include <stdbool.h>

#include "defs.h"

struct task init_task(char* d, unsigned short g) {
  struct task t = { .goal = g, .reached = 0 };
  strcpy(t.desc, d);
  return t;
}

struct tasklist init_tasklist(char* n) {
  struct tasklist tl = { .task_count = 0 };
  strcpy(tl.name, n);
  return tl;
}

bool task_complete(struct task t) {
  return t.reached == t.goal;
}

bool tasklist_full(struct tasklist tl) {
  return tl.task_count == TASK_LIST_MAX;
}

int add_task_to_list(struct tasklist* tl, struct task t) {
  tl->tasks[tl->task_count] = t;
  tl->task_count++;
  return 0;
}

struct task remove_task_from_list(struct tasklist* tl, int index) {
  struct task removed = tl->tasks[index];
  for(int i = index; i < tl->task_count; i++) {
    tl->tasks[i] = tl->tasks[i + 1];
  }
  tl->task_count--;
  return removed;
}