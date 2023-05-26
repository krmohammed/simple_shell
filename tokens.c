#include "main.h"

/**
 * tokenization - breaks commands entered into tokens
 * @usr_com: string containing command entered
 *
 * Return: array of pointers to the tokens
 */

char **tokenization(char *usr_com)
{
	char **chunks;
	char *usr_com_copy = NULL;
	char *tok;
	int n_tok, i;

	usr_com_copy = malloc(sizeof(char) * (_strlen(usr_com) + 1));
	if (usr_com_copy == NULL)
		return (NULL);
	_strcpy(usr_com_copy, usr_com);

	tok = strtok(usr_com, " \n");
	n_tok = 0;
	while (tok)
	{
		n_tok++;
		tok = strtok(NULL, " \n");
	}

	chunks = malloc(sizeof(char *) * (n_tok + 1));
	if (chunks == NULL)
		return (NULL);

	tok = strtok(usr_com_copy, " \n");
	i = 0;
	while (tok)
	{
		chunks[i] = malloc(sizeof(char) * (_strlen(tok) + 1));
		if (chunks[i] == NULL)
			return (NULL);
		_strcpy(chunks[i], tok);
		i++;
		tok = strtok(NULL, " \n");
	}
	chunks[i] = NULL;

	free(usr_com_copy);
	return (chunks);
}
