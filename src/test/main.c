#include "test/main.h"

/**
 * @brief Reads in an array of integers from a file
 * 
 * @param file_name The name of the file
 * @param length the length of the array
 * @return int* the data that was read in from the file
 */
int *read_integers_from_file(char *file_name, int *length)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", file_name);
        return NULL;
    }

    int *data = malloc(sizeof(int) * MAX_ARRAY_SIZE);
    int i = 0;
    while (fscanf(file, "%d ", &data[i]) != EOF)
    {
        i++;
    }

    *length = i;
    fclose(file);

    return data;
}

/**
 * @brief Times the use of a sorting algorithm
 * 
 * @param function The pointer to the sorting algorithm that we are testing
 * @param data The pointer to the data that we are testing
 * @param length The length of the data
 * @return int the total execution time of the sorting algorithm
 */
int time_execution(void (*function)(int *, int), int *data, int length)
{
    time_t begin_time = clock();
    function(data, length);
    time_t end_time = clock();
    return (int)(end_time - begin_time) / (CLOCKS_PER_SEC / 1000);
}

/**
 * @brief Tests all of the test files and records the run
 * time of each test.
 */
void RunTests()
{
    void (*algorithms[3])(int *, int) = {quick_sort, heap_sort, merge_sort};

    SECTIONS
    SIZES

    for (int algorithm = 0; algorithm < 3; algorithm++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char base2[256] = "../data/";
                generate_directory(strcat(strcat(strcat(base2, sections[i]), "/"), sizes[j]));

                for (int k = 1; k <= 30; k++)
                {
                    char *file_name = malloc(sizeof(char) * 256);
                    sprintf(file_name, "../data/%s/%s/%d.txt", sections[i], sizes[j], k);
                    printf("%s: ", file_name);

                    int length;
                    int *data = read_integers_from_file(file_name, &length);

                    int time = time_execution(algorithms[algorithm], data, length);
                    printf("%d\n", time);
                }
            }
        }
    }
}