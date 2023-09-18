#include "main.h"

/**
 * printer - prints characters by its formatter
 * @format: first string argument to be printed
 * @format_lst: array of functions to implement
 * @args: variable arguments
 *
 * Return: returns the number of successfully printed characters
 */
int printer(const char *format, format_s format_lst[], va_list *args)
{
	bool printed = false;
	unsigned int count = 0, i = 0, j = 0;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			printed = false;
			for (j = 0; format_lst[j].c != NULL; j++)
			{
				if (format[i] == format_lst[j].c[0])
				{
					printed = true;
					count += format_lst[j].f(args);
					break;
				}
			}
			if (!printed)
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	return (count);
}

