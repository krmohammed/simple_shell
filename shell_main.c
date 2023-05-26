#include "main.h"

/**
 * main - entry to run commands entered by user
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variable
 *
 * Return: 0 (Always)
 */

int main(int argc, char **argv, char **envp)
{
	char *prompt, *user_command = NULL;
	ssize_t get_command;
	size_t n = 0, line_num = 0;
	char **full_command;
	(void)argc;

	prompt = "$ ";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf("%s", prompt);
		/*write(STDOUT_FILENO, prompt, 2);*/
		get_command = getline(&user_command, &n, stdin);
		line_num++;
		if (get_command == -1)
		{
			free(user_command);
			return (-1);
		}
		if (*user_command == '\n')
		{
			continue;
		}
		full_command = tokenization(user_command);
		if (built(full_command, envp))
		{
			free(user_command);
			continue;
		}
		execute_command(full_command, argv[0], envp, line_num);
	}

	free(user_command);
	return (0);
}
