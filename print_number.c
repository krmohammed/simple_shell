#include "main.h"

/**
 * printnumber - prints any integer
 * @list: number to be printed
 * Return: number of characters printed
 */

int printnumber(va_list *list)
{
	int n = va_arg(*list, int), count = 0, divider = 1;
	unsigned int i = n;

	if (n < 0)
	{
		_putchar('-');
		count++;
		i = -i;
	}

	for (; i / divider > 9;)
		divider *= 10;

	for (; divider != 0;)
	{
		count += _putchar('0' + i / divider);
		i %= divider;
		divider /= 10;
	}

	return (count);
}
