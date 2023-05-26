#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>


/**
 * struct format - the string format for my printf
 * @c: the character format
 * @f: the function to use
 */
typedef struct format
{
	char *c;
	int (*f)(va_list *);
} format_s;

char **tokenization(char *usr_com);
int execute_command(char **full_command, char *args,
		char **envp, size_t line);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int printer(const char *format, format_s format_lst[], va_list *args);
int printstring(va_list *args);
int printnumber(va_list *list);
int _printf(const char *format, ...);
int _putchar(char c);
char *locate_path(char *user_cmd, char **envp);
char *_getEnv(char *path, char **envp);
int built(char **command, char **envp);
void free_str(char **d_ptr);

#endif
