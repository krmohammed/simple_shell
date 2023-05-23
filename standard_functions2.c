#include "main.h"

/**
 * _strcat - concatenating two strings
 * @dest: first string
 * @src: second string
 *
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int len, i;

	if (dest == NULL || src == NULL)
		return (NULL);
	for (len = 0; dest[len] != '\0'; len++)
		;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @n: number of elements
 *
 * Return: difference in integer value of the two strings
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (n > 0 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (s1[i] - s2[i]);
}
