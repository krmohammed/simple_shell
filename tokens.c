#include "main.h"

/**
 * tokens - breaks commands entered into tokens
 * @command: string containing command entered
 * @command_len: length of command
 *
 * Return: array of pointers to the tokens
 */

char **tokens(char *commands, ssize_t command_len)
{
        char *token, *commands_cpy = NULL;
        char **full_command;
        int n_token, i;
        char *delim = " \n";

        commands_cpy = malloc(sizeof(char) * command_len);
        if (commands_cpy == NULL)
        {
                return (NULL);
        }

        _strcpy(commands_cpy, commands);
        token = strtok(commands, delim);

        n_token = 0;
        while (token != NULL)
        {
                n_token++;
                token = strtok(NULL, delim);
        }

        full_command = malloc(sizeof(char *) * n_token);
        token = strtok(commands_cpy, delim);
        for (i = 0; token != NULL; i++)
        {
                full_command[i] = malloc(sizeof(char) * _strlen(token));
                _strcpy(full_command[i], token);
                token = strtok(NULL, delim);
        }
        full_command[i] = NULL;

        /*execute_command(full_command, argv);*/

        free(commands_cpy);
        return (full_command);
}
