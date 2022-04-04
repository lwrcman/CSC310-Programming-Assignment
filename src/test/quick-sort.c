#include "test/quick-sort.h"

/**
 * @brief Gets the pivot value, given the criteria listed
 * for selecting the pivot.
 *
 * @param data The data which we will find the pivot in
 * @param length The length of the data we are searching
 * @return int The pivot value that should be used
 */
int select_pivot(int *data, int length)
{
    if (length < 101)
        return 0;

    int index_b = floor(length / 2.0);

    int a = data[0];
    int b = data[index_b];
    int c = data[length - 1];

    // Kinda shit code, but it does the job.
    if (a > b && c < b)
        return index_b;
    if (a < b && c > b)
        return index_b;
    if (b > a && c < a)
        return 0;
    if (b < a && c > a)
        return 0;
    if (a < c && b > c)
        return length - 1;
    if (a > c && b < c)
        return length - 1;
}

/**
 * @brief An implementation of the dutch flag partition. I referenced
 * pseudo-code on the provided page (Since I had no experience with this
 * algorithm before this point). I noticed some minor issues when
 * converting it to C code, but was able to fix them up. I renamed the
 * variables in order to show my understanding of the partitioning algorithm. 
 *
 * @param data The data we want to partition.
 * @param length The length of the data we are partitioning.
 * @param pivot The point we wish to pivot on.
 * @return int 
 */
int dutch_flag_partition(int *data, int length, int pivot)
{
    int pivot_data = data[pivot];

    int low = 0;             // Represents points less than
    int mid = 0;             // Represents the middle point
    int higher = length - 1; // Represents the greater than point

    // Loop goes until mid crosses into the greater than section
    while (mid <= higher)
    {
        // If data at mid is lower than the pivot, move it back towards the 
        // front of the array.
        if (data[mid] < pivot_data)
        {
            swap(data, low, mid);
            low++;
            mid++;
        }
        // If the data at mid is greater than the pivot, move towards the end.
        else if (data[mid] > pivot_data)
        {
            swap(data, mid, higher);
            higher--;
        }
        // Otherwise we can leave it in the current position and move up an element (eventually
        // the value will be pulled to the new middle)
        else
        {
            mid++;
        }
    }

    return higher;
}

/**
 * @brief Preforms the quick sort algorithm on a set of data. This algorithm gave me 
 * a major hassle. For the longest time I was recursively calling quick sort with 
 * `quick_sort(data, before_pivot_length + 1)`, which worked unless a duplicate was 
 * present. It took me about 1 hour to realize that the `+ 1` re-entered the pivot
 * back into the table. Therefore, when duplicates were present, it would get stuck in
 * and infinite loop.
 * 
 * @param data The data we want to sort
 * @param length The length of the data we are sorting
 */
void quick_sort(int *data, int length)
{
    int last_index = length - 1;
    if (last_index < 1)
        return;

    int pivot_index = select_pivot(data, length);
    int before_pivot_length = dutch_flag_partition(data, length, pivot_index);

    quick_sort(data, before_pivot_length);
    quick_sort(data + (before_pivot_length + 1), last_index - (before_pivot_length + 1) + 1);
}
