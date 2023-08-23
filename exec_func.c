#include "main.h"

/**
 * check_built - checks if the input is a built-in function
 * @token_arr: a pointer to the user input
 * Return: 0 if correct match, -1 if no match
 */
int check_built(char **token_arr)
{
	built_t bul[] = {
		{"cd", ch_dir},
		{"echo", _echo},
		{"env", _env},
		{NULL, NULL},
	};
	int i;

	for (i = 0; bul[i].command; i++)
	{
		if (_strcmp((bul[i].command), token_arr[0]) == 0)
			return (0);
	}
	
	return (-1);
}

/**
 * exec_built - executes built in functions
 * @token_arr: a pointer to the user input
 * Return: 0 of success, -1 if failure
 */
int exec_built(char **token_arr)
{
	built_t bul[] = {
		{"cd", ch_dir},
		{"echo", _echo},
		{"env", _env},
		{NULL, NULL},
	};
	int i;

	for (i = 0; bul[i].command; i++)
	{
		if (_strcmp((bul[i].command), token_arr[0]) == 0)
			return (bul[i].func(token_arr, num));
	}

	return (-1);
}

/**
 * exec_cmd - executes commands
 * @token_arr: tokenized strings array
 * Return: 0 if successful, -1 otherwise
 */
int exec_cmd(char **token_arr)
{
	char *cmd1;
	pid_t pid;
	int status;

	if (!token_arr)
		return (-1);
	
	cmd1 = _getpath(token_arr);
	if (!cmd)
		return (-1);

	pid = fork();
	if (id == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		_execve(token_arr, cmd1);
	}
	wait(&status);
	return (0);
}
