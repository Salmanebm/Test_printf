#include "main.h"

/**
 *
 */
void _exit_man(char **token_arr, char *buff)
{
	if (strcmp(token_arr[0], "exit") == 0)
	{
		free(buff);
		free(token_arr);
		exit(1);
	}
}
