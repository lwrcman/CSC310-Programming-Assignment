#include <string.h>

#include "generator/main.h"
#include "test/main.h"

/**
 * @brief Runs the main method of the program.
 * 
 * @param argc the number of arguments
 * @param argv the individual arguments that have been passed
 * @return int the exit status of the program
 */
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
        RunTests();
    }
}