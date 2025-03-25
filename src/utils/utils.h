
#ifndef UTILS_H
#define UTILS_H

#include "workload_item.h"

workload_item* _get_items(const char* filepath);

workload_item __parse_line(const char* line);

#endif //UTILS_H
