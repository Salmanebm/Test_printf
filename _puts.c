#include "main.h"
/**
 * _puts: print  character by character
 * @buffer: input string to print
 * @buff_ind: buffer inex to print
 * Description: print the buffer basing on the index
 * and the input string
 * Return: nothing
 */
void _puts(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		for (int i = 0; i < *buff_ind; i++)
		{
			_putchar(buffer[i]);
		}
	}

	*buff_ind = 0;
}
