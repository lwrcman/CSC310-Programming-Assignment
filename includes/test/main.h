#ifndef MAIN_TEST_H
#define MAIN_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#include "common/helpers.h"

#include "test/quick-sort.h"
#include "test/heap-sort.h"
#include "test/merge-sort.h"

#define MAX_ARRAY_SIZE 1000000

void RunTests();

#endif