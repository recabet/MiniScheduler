#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

workload_item __parse_line(const char* line)
{
    workload_item item;

    sscanf(line, "%d %d  %zu %zu %zu %s %d",
           &item.pid,
           &item.ppid,
           &item.ts,
           &item.tf,
           &item.idle,
           item.cmd,
           &item.prio);

    item.cmd[sizeof(item.cmd) - 1] = '\0';

    return item;
}


workload_item* _get_items(const char* filepath)
{
    FILE* file = fopen(filepath, "r");
    if (!file)
    {
        perror("fopen");
        return NULL;
    }

    workload_item* items = malloc(MAX_LINES * sizeof(workload_item));
    if (!items)
    {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t count = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        if (count >= MAX_LINES)
        {
            fprintf(stderr, "Exceeded maximum storage\n");
            break;
        }
        items[count] = __parse_line(line);
        ++count;
    }

    free(line);
    fclose(file);
    return items;
}

int _get_priority_sum(workload_item* tasks, const size_t count)
{
    if (!tasks)
    {
        return -1;
    }

    int sum = 0;

    for (size_t idx = 0; idx < count; ++idx)
    {
        sum += tasks[idx].prio;
    }

    return sum;
}
