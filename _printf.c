#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - Custom printf function for formatted output.
 * @format: Format string with supported specifiers.
 *
 * Description:
 * This function prints formatted output to the standard output.
 * Supported specifiers: %c, %s, %d/%i, %u, %x, %X, %%.
 *
 * Return: Number of characters printed (success), -1 on error.
 *
 * Note: Simplified version for educational purposes.
 */
int _printf(const char *format, ...)
{	va_list args;
	int count = 0, sh = 0;
	int ind = 0;

	va_start(args, format);
	while (format[ind])
	{
		if (format[ind] == '%')
		{	ind++;
			if (format[ind] == '%')
			{	_putchar(format[ind]);
				count++;
				ind++;
			}
			else if (format[ind] == 'c')
			{	char c = va_arg(args, int);
				_putchar(c);
				ind++;
				count++; }
			else if (format[ind] == 's')
			{	char *str = va_arg(args, char *);
				_puts(str);
				ind++;
				while (*str)
				{	count++;
					str++;
				}}
			else if (format[ind] == 'd' || format[ind] == 'i')
			{	int value = va_arg(args, int);

				sh = print_int(value);
				ind++;
				count += sh; }}
		else
		{	_putchar(format[ind]);
			ind++;
			count++;
		}}
		va_end(args);
	return (count);
}
