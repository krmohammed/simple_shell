#include "main.h"

/**
 * _strcpy - copies a string to another
 * @dest: string to receive copied text
 * @src: source of copied text
 *
 * Return: copied text in the form of dest
 */
char *_strcpy(char *dest, char *src)
{
        int j, len;

        if (dest == NULL || src == NULL)
                return (NULL);

        for (len = 0; src[len] != '\0'; len++)
                ;

        for (j = 0; j <= len; j++)
        {
                dest[j] = src[j];
        }

        dest[j] = '\0';

        return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string to get it's length
 *
 * Return: length of string
 */
int _strlen(char *s)
{
        int len = 0;

        while (s[len] != '\0')
        {
                len += 1;
        }

        return (len);
}
