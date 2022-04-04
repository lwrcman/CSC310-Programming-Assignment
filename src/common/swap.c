#include "common/swap.h"

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