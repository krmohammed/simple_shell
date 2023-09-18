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

extern char **environ;

/**
 * struct built - built in command struct
 * @command: built in command
 * @function: right function
 */

typedef struct built
{
	char *command;
	int (*function)(char **);
} built_t;

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

char **tokens(char *commands, char *delim);
void execute_command(char **full_command, char **argv, char **envp, int num);
int environ_printer(char **args);
int printer(const char *format, format_s format_lst[], va_list *args);
int printstring(va_list *args);
int _printf(const char *format, ...);
int _putchar(char c);
char *locate_path(char *user_cmd, char **envp);
char *_getEnv(char *path, char **envp);
int built(char **command);
void freeing(char **line);
void print_error(char *cmd, int num, char *error, char *error_msg);
int all_spaces(char *inp);

#endif
