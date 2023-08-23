#include "main.h"


void _execve(char **token_arr, char *cmd)
{	
	if(execve(cmd, token_arr, NULL) == -1)
	{ 
	   	perror("Error: ");
		exit(0);
	}
}


