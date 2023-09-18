#include "main.h"

/**
 * _printf - This function is a clone for the c printf function
 * @format: first constant string argument to be printed
 * Return: returns the number of successfully printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int count = 0;
	format_s format_lst[] = {
		{"s", printstring},
		{NULL, NULL}
	};
	va_start(args, format);

	count = printer(format, format_lst, &args);

	va_end(args);
	return (count);
}

