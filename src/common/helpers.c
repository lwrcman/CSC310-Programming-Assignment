#include "common/helpers.h"

/**
 * @brief Swaps elements a and b in the array
 *
 * @param data the data which the swap is occuring on
 * @param a the first element
 * @param b the second element
 */
void swap(int *data, int a, int b)
{
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

/**
 * @brief If the directory does not exist we will generate the directory
 *
 * @param directory the directory we plan on creating
 */
void generate_directory(const char *directory)
{
    struct stat st = {0};
    if (stat(directory, &st) == -1)
    {
        mkdir(directory, 0777);
    }
}