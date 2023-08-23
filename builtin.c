#include "main.h"

/**
 * _echo - prints  echo special cases
 * @token_arr: tokenised string array
 * @st: int
 * Return: Always 0
 */
int _echo(char **token_arr, int st)
{
	char *path;
	unsigned int  ppid = getppid();

	if (_strncmp(token_arr[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINT("\n");
	}
	else if (_strncmp(token_arr[1], "$$", 2) == 0)
	{
		print_number(ppid);
		PRINT("\n");

	}
	else if (_strncmp(token_arr[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (0);
}

/**
 * print_echo - Excute Normal Echo
 * @token_arr: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int print_echo(char **token_arr)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", token_arr, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do 
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}

/**
 * ch_dir - Change Dirctory
 * @token_arr: tokenized string array
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int ch_dir(char **token_arr, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (token_arr[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(token_arr[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(token_arr[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * _env - Display Enviroment Variable
 * @token_arr:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */
int _env(__attribute__((unused)) char **token_arr, __attribute__((unused)) int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
