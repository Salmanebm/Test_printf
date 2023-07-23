#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/*
 * print_int: print integer
 * @value: integer to convert
 *
 * Description: print integer with printf fuction
 * Return number of characters printed
 */
int print_int(int value)
{
	char buffer[32];
	int printed = 0;

	if (value < 0)
	{
		putchar('-');
		printed++;
		value = -value;
	}

	int i = 0;

	do {
		buffer[i++] = '0' + (value % 10);
		value /= 10;
		printed++;
	} while (value > 0);

	for (int j = i - 1; j >= 0; j--)
	{
		putchar(buffer[j]);
	}

	return (printed);
}
