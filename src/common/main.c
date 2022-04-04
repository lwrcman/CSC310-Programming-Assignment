#include <string.h>

#include "generator/main.h"
#include "test/merge-sort.h"

int main(int argc, char **argv)
{
    if (argc > 1 && strcmp(argv[1], "generate") == 0)
    {
        // Run the generator
        GenerateData();
    }
    else
    {
        // Run the tests
        // RunTests();
    }
}