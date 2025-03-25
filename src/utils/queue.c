#include "queue.h"

#include <stdio.h>

queue init_queue(void)
{
    return (queue){0, 0, {0}, {0}};
}

bool is_empty(const queue* q)
{
    return q->front == q->rear;
}

bool is_full(const queue* q)
{
    return (q->rear + 1) % QUEUE_MAX_LENGTH == q->front;
}

void enqueue(queue* q, const int pid, const int prio)
{
    if (!q)
    {
        fprintf(stderr, "Queue is NULL!\n");
        return;
    }
    if (is_full(q))
    {
        fprintf(stderr, "Queue is full!\n");
        return;
    }
    q->queue_pid[q->rear] = pid;
    q->queue_prio[q->rear] = prio;
    q->rear = (q->rear + 1) % QUEUE_MAX_LENGTH;
}

void dequeue(queue* q)
{
    q->front = (q->front + 1) % QUEUE_MAX_LENGTH;
}

bool pop(const queue* q, int* pid, int* prio)
{
    if (is_empty(q))
    {
        fprintf(stderr, "Queue is empty! Cannot dequeue.\n");
        return false;
    }
    *pid = q->queue_pid[q->front];
    *prio = q->queue_prio[q->front];
        return true;
}


void print_queue(const queue* q)
{
    if (!q)
    {
        fprintf(stderr, "Queue is NULL!\n");
        return;
    }
    if (is_empty(q))
    {
        fprintf(stderr, "Queue is empty!\n");
        return;
    }

    printf("Queue contents (PID, Priority):\n");

    int i = q->front;
    while (i != q->rear)
    {
        printf("(%d, %d) ", q->queue_pid[i], q->queue_prio[i]);
        i = (i + 1) % QUEUE_MAX_LENGTH;
    }

    printf("\n");
}

