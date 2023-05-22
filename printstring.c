#include "main.h"

/**
 * printstring - prints a string to stdout
 * @args: string to printed
 * Return: number of characters printed
 */

int printstring(va_list *args)
{
	char *str = va_arg(*args, char *);
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}
