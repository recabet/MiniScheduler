#ifndef WORKLOAD_ITEM_H
#define WORKLOAD_ITEM_H

#include <stdlib.h>

struct workload_item_t {
    int pid;
    int ppid;
    size_t ts;
    size_t tf;
    size_t idle;
    char cmd[32];
    int prio;
};

typedef struct workload_item_t workload_item;

#endif //WORKLOAD_ITEM_H
