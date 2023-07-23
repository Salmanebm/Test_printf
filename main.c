#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = strlen("Let's try to printf a simple sentence.\n");
   	_printf("Let's try to printf a simple sentence.\n");
    	printf("Let's try to printf a simple sentence.\n");
    	_printf("Character:[%c]\n", 'H');
    	printf("Character:[%c]\n", 'H');
    	_printf("String:[%s]\n", "I am a string !");
    	printf("String:[%s]\n", "I am a string !");
    	_printf("Percent:[%%]\n");
    	 printf("Percent:[%%]\n");
    	_printf("Length:[%d, %i]\n", len, len);
   	printf("Length:[%d, %i]\n", len, len);
	return (0);
}
