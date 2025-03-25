
#ifndef UTILS_H
#define UTILS_H

#include "workload_item.h"

workload_item* _get_items(const char* filepath);

workload_item __parse_line(const char* line);

int _get_priority_sum(workload_item* tasks);

#endif //UTILS_H
