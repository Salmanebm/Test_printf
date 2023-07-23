#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints a single char
 * @c: the char to be printed
 */
int _putchar(char c)
{
	return (write(1, &c, 2));
}
