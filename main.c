#include "main.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv: Argument Value
 * Return: Exit Value By Status
 */
int main(__attribute__((unused))int ac, char **argv)
{
	char *buff = NULL;
	size_t buff_size = 0;
	char *cmd;
	char **token_arr;
	int n_line, main_loop_counter = 0;

	while (1)
	{
		main_loop_counter++;
		if (isatty(STDIN_FILENO))
			PRINT("$ ");
			
		n_line = getline(&buff, &buff_size, stdin);

		if (buff[0] == '\n' || buff[0] == '\0')
			continue;	

		if (n_line == -1)
		{	
			PRINT('\n');
			exit(0);
		}

		token_arr = tokenizer(buff," \t\n", n_line);

		_exit_man(token_arr, buff);

		if (check_built(token_arr) == 0)
		{
			exec_built(token_arr);
			free(buff);
			free(token_arr);
			continue;
		}
		else
			exec_cmd(token_arr);
			
		free(buff);
		free_tokens(token_arr);
	}

	return (0);
}
