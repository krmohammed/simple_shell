#include "main.h"

/**
 * tokens - breaks commands entered into tokens
 * @commands: string containing command entered
 * @delim: delimeter for tokenization
 *
 * Return: array of pointers to the tokens
 */

char **tokens(char *commands, char *delim)
{
	char *token;
	char **full_command;
	int i = 0;

	if (commands == NULL)
		return (NULL);

	full_command = malloc(sizeof(char *) * 11);
	if (full_command == NULL)
		return (NULL);

	token = strtok(commands, delim);
	while (token != NULL && i < 9)
	{
		full_command[i++] = strdup(token);
		token = strtok(NULL, delim);
	}
	full_command[i] = NULL;

	return (full_command);
}

/**
 * freeing - frees a pointer to arg strings
 * @line: pointer to arg strings
 *
 */

void freeing(char **line)
{
	int i = 0;

	while (line[i])
		free(line[i++]);

	free(line);
}
