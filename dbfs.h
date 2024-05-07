#ifndef DBFS_H
#define DBFS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <strings.h>

/**
 * @defgroup dbfs Database File System
 * @{
 */

/**
 * @struct InputBuff
 * Input buffer structure to store user input.
 */
typedef struct
{
    char *buffer;      /**< Input buffer */
    size_t buffer_len; /**< Length of the input buffer */
    ssize_t input_len; /**< Length of the input string */
} InputBuff;

/**
 * @addtogroup dbfs_functions
 * @{
 */

/**
 * Create a new input buffer.
 *
 * @return A pointer to a new InputBuff struct.
 */
InputBuff *new_input_buff();

/**
 * Show a DB prompt to the user.
 */
void show_db_prompt();

/**
 * Get user input from stdin and store it in the input buffer.
 *
 * @param user_input The input buffer to store the user input in.
 */
void get_user_input(InputBuff *user_input);

/**
 * Free the memory allocated for the input buffer.
 *
 * @param user_input The input buffer to free.
 */
void free_user_input(InputBuff *user_input);

/** @} @} */

#endif