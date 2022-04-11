#ifndef HELPERS_H
#define HELPERS_H

#include <sys/types.h>
#include <sys/stat.h>

#define SECTIONS char *sections[] = {"unsorted", "sorted", "reverse-sorted"};
#define SIZES char *sizes[] = {"small", "medium", "large"};

void swap(int *data, int a, int b);
void generate_directory(const char *directory);

#endif