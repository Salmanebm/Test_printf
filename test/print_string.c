#include "main.h"
/**
 * print_string - Prints a string to the standard output (stdout).
 * @list: The string to be printed.
 *
 * Return: The number of characters printed.
 */

int print_string(va_list list)
{
	int i, len;
	char *s;

	s = va_arg(list, char *);

	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}

}
