#include "main.h"

char **tokenizer(char *buff, char *delimiter, int n_line)
{       
	char *token = NULL, **token_arr = NULL;
	char *buff_cp = NULL;
	int token_count = 0, j = 0;

	buff_cp = malloc(sizeof(char) * (n_line + 1)); 
	if (buff_cp == NULL)
	{	
		free(buff_cp);
		perror("Error");
	}
	strcpy(buff_cp, buff);
	
	token = strtok(buff, delimiter);
	while(token)
	{	
		token_count++;
		token = strtok(NULL, delimiter);				
	}
	token_count++;
	token_arr = malloc(sizeof(char *) * token_count);
	if (token_arr == NULL)
	{
		free_tokens(token_arr);
		perror("Error");
	}
	token = strtok(buff_cp, delimiter);
	while (token)
	{	
		token_arr[j] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(token_arr[j], token);
		token = strtok(NULL, delimiter);
		j++;
	}
	token_arr[j] = NULL;
	free(buff_cp);
	free(token);
	return (token_arr);
}
