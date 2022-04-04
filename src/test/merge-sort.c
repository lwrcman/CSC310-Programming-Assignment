#include "test/merge-sort.h"

/**
 * @brief Merges list B and C together into the array A
 * 
 * @param B The left array of data
 * @param C The right array of data
 * @param A The destination in which we want to store the data
 * @param size_B The size of the left array
 * @param size_C The size of the right array
 */
void merge(int *B, int *C, int *A, int size_B, int size_C)
{
    // Define the array iterators
    int B_Iterator = 0; // B_Iterator is "i" in the pseudocode
    int C_Iterator = 0; // C_Iterator is "j" in the pseudocode
    int A_Iterator = 0; // A_Iterator is "k" in the pseudocode

    while (B_Iterator < size_B && C_Iterator < size_C)
    {
        if (B[B_Iterator] <= C[C_Iterator])
        {
            A[A_Iterator] = B[B_Iterator];
            B_Iterator++;
        }
        else
        {
            A[A_Iterator] = C[C_Iterator];
            C_Iterator++;
        }
        A_Iterator++;
    }

    if (B_Iterator == size_B)
    {
        /**
         * A + A_Iterator is pointer math in order to append the remaining elements to the untouched parts of A
         * C + C_Iterator starts us at the beginning of the untouched part of C
         * size_B + size_C - A_Iterator determines the remaining elements that need to be copied
         */
        memcpy(A + A_Iterator, C + C_Iterator, (size_B + size_C - A_Iterator) * sizeof(int));
    }
    else
    {
        /**
         * A + A_Iterator is pointer math in order to append the remaining elements to the untouched parts of A
         * B + B_Iterator starts us at the beginning of the untouched part of B
         * size_B + size_C - A_Iterator determines the remaining elements that need to be copied
         */
        memcpy(A + A_Iterator, B + B_Iterator, (size_B + size_C - A_Iterator) * sizeof(int));
    }
}


/**
 * @brief Preforms the merge sort recursively on a particular set of data
 * 
 * @param data The data we wish to sort
 * @param length The length of the data we want to sort.
 */
void merge_sort(int *data, int length)
{
    if (length <= 1)
    {
        return;
    }

    // Calculate the partition sizes
    int size_B = floor(length / 2.0);
    int size_C = ceil(length / 2.0);

    // Allocate space for the partitions
    int *B = (int *)calloc(size_B, sizeof(int));
    int *C = (int *)calloc(size_C, sizeof(int));

    // Copy over the data
    memcpy(B, data, size_B * sizeof(int));
    memcpy(C, data + size_B, size_C * sizeof(int));

    // Recursively partition down, then merge your way back up
    merge_sort(B, size_B);
    merge_sort(C, size_C);

    // Brings B and C together in a sorted fashion and populates the data array
    merge(B, C, data, size_B, size_C);

    // Frees up memory space since we no longer need the allocated space
    // PREVENT MEMORY LEAKS
    free(B);
    free(C);
}