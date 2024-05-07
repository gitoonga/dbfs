#include "dbfs.h"

/**
 * Show a DB prompt to the user.
 */
void show_db_prompt()
{
    printf("dbfs: > ");
}

/**
 * Create a new input buffer struct.
 *
 * @return A pointer to a new InputBuff struct.
 */
InputBuff *new_input_buff()
{
    InputBuff *user_input = malloc(sizeof(InputBuff));
    user_input->buffer = NULL;
    user_input->buffer_len = 0;
    user_input->input_len = 0;

    return user_input;
}

/**
 * Get user input from stdin and store it in the input buffer.
 *
 * @param user_input The input buffer to store the user input in.
 */
void get_user_input(InputBuff *user_input)
{
    ssize_t bytes_read = getline(&(user_input->buffer), &(user_input->buffer_len), stdin);
    if (bytes_read <= 0)
    {
        printf("Error reading user input!");
        exit(EXIT_FAILURE);
    }

    user_input->input_len = bytes_read - 1;
    user_input->buffer[bytes_read - 1] = 0;
}

/**
 * Free the memory allocated for the input buffer.
 *
 * @param user_input The input buffer to free.
 */
void free_user_input(InputBuff *user_input)
{
    free(user_input->buffer);
    free(user_input);
}

/**
 * The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return The exit status of the program.
 */
int main(int argc, char *argv[])
{
    InputBuff *user_input = new_input_buff();
    while (true)
    {
        show_db_prompt();
        get_user_input(user_input);

        if (strcmp(user_input->buffer, ".exit") == 0)
        {
            free_user_input(user_input);
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Unrecognized command '%s'.\n", user_input->buffer);
        }
    }
}