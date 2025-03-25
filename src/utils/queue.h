#ifndef QUEUE_H
#define QUEUE_H

#include "workload_item.h"

#include <stdbool.h>

#define QUEUE_MAX_LENGTH 20

struct queue {
    int rear;
    int front;
    int queue_prio[QUEUE_MAX_LENGTH];
    int queue_pid[QUEUE_MAX_LENGTH];
    size_t size;
};

typedef struct queue queue;

queue init_queue(void);

bool is_empty(const queue* q);

bool is_full(const queue* q);

void enqueue(queue* q, int pid, int prio);

void dequeue(queue* q);

bool pop(const queue* q, int* pid, int* prio);

void print_queue(const queue* q);

#endif //QUEUE_H
