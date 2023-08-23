#ifndef MAIN_H
#define MAIN_H

/****** STRUCTS ******/

typedef struct builtin
{
	char *command;
	int (*func)(char **av, int num);
} built_t;

/****** MACROs ******/

#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))

/****** Libraries ******/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/****** String Functions ******/

int _putchar(char c);
int _strlen(char *s);
int _atoi(char *s);
void _puts(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *d, char *s);
char *_strcat(char *d, char *source);
int _strncmp(const char *s1, const char *s2, size_t n)

/****** NUMBERS FUNCTIONS ******/

void print_number(unsigned int n);
void print_number_in(int n);

/****** EXECUTION FUNCTIONS ******/

int check_built(char **token_arr);
int exec_built(char **token_arr);
int exec_cmd(char **token_arr);

/****** BUILTIN FUNCTIONS ******/

int _echo(char **token_arr, int st);
int print_echo(char **token_arr);
int ch_dir(char **cmd, int er);
int _env(char **token_arr, int er);

char *_getpath(char **command);
char **tokenizer(char *command, char *del, int nb_char);
void _execve(char **token_arr, char *cmd);
void free_tokens(char **token_arr);
void _exit_man(char **token_arr, char *buff);

#endif
