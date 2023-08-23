#include "main.h"

char *_getpath(char **token_arr)
{
	char *path = getenv("PATH");
	char *full_cmd;
	struct stat st;
	int i;
	char **path_arr;

	path_arr = tokenizer(path, ":", strlen(path));
 
	for(i = 0; path_arr[i] != NULL; i++)
	{
		
		full_cmd = malloc(strlen(path_arr[i]) + strlen(token_arr[0]) + 2);
		if (full_cmd == NULL)
		{	
			free(full_cmd);
			perror("Error");
		}
		strcpy(full_cmd, path_arr[i]);
		strcat(full_cmd, "/");
		strcat(full_cmd, token_arr[0]);				
		strcat(full_cmd, "\0");

		if (stat(full_cmd, &st) == 0)
		{
			return (full_cmd);
		}
		free(full_cmd);
	}
	return (token_arr[0]);
}

