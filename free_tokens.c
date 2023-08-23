#include "main.h"
/*
 *
 */
void free_tokens(char **token_arr)
{
	int i = 0;
	
	if (token_arr == NULL)
	            return;
	
	
	while (token_arr[i] != NULL)
	{
		free(token_arr[i]); 
	        i++;
	}
	free(token_arr); 
}
