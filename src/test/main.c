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
float time_execution(void (*function)(int *, int), int *data, int length)
{
    time_t begin_time = clock();
    function(data, length);
    time_t end_time = clock();
    return (end_time - begin_time) / (CLOCKS_PER_SEC / 1000.0);
}

/**
 * @brief Set the up output file object
 * 
 * @param filename The name of the file we are writing to
 * @param mode The mode of the file we are writing to
 * @return FILE* A pointer to the file
 */
FILE *setup_output_file(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    return file;
}

/**
 * @brief Tests all of the test files and records the run
 * time of each test.
 */
void RunTests()
{
    void (*algorithms[3])(int *, int) = {quick_sort, heap_sort, merge_sort};
    char *algorithm_names[3] = {"Quick Sort", "Heap Sort", "Merge Sort"};

    SECTIONS
    SIZES

    FILE *file_pointer = setup_output_file("../output.csv", "w+");

    for (int algorithm = 0; algorithm < 3; algorithm++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Write the algorithm name, section name, and size name
                fprintf(file_pointer, "%s,", algorithm_names[algorithm]);
                fprintf(file_pointer, "%s,", sections[i]);
                fprintf(file_pointer, "%s,", sizes[j]);

                // For all 30 data files, we want to read them in and time them
                for (int k = 1; k <= 30; k++)
                {
                    char *file_name = malloc(sizeof(char) * 256);
                    sprintf(file_name, "../data/%s/%s/%d.txt", sections[i], sizes[j], k);

                    // Read the data in
                    int length;
                    int *data = read_integers_from_file(file_name, &length);

                    // Test the data
                    float time = time_execution(algorithms[algorithm], data, length);
                    fprintf(file_pointer, "%f,", time);

                    // Free the data and the file name
                    free(file_name);
                    free(data);
                }

                // Add a new line since we finished the tests under that name.
                fprintf(file_pointer, "\n");
            }
        }
    }

    fclose(file_pointer);
}