#include "main.h"

/**
 * print_char - prints a character
 * @list: the variable arg list
 * Return: 0 Alwys
 */
int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);

	_putchar(c);
	return (0);
}
