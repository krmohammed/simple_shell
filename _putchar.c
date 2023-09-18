#include "main.h"

/**
 * _putchar - writes one character to stdout
 * @c: character to be written
 * Return: 1 if successful, -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
