#ifndef GENERATOR_MAIN_H
#define GENERATOR_MAIN_H

// Includes
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "test/quick-sort.h"

// * Constants Are Listed Below! * //

/**
 * @brief Number of files per type
 */
#define SAMPLES 30

/**
 * @brief Smallest possible number to be generated
 */
#define MIN_INT 0

/**
 * @brief Largest possible number to be generated
 */
#define MAX_INT 10000

/**
 * @brief Describes the value that will seperate
 * our different values in the files
 */
#define DELIMITER " "


// * Prototypes Are Listed Below! * //

/**
 * @brief Generates the given data and stores it in files
 */
void GenerateData();

#endif