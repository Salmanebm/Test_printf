#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#define BUFF_SIZE 1024
/*
 *_printf: custom printf function that print
 *@format: input format
 *Description:custom printf fuction to print
 * Return: number o character printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int sh = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
				{
					_puts(buffer, &buff_ind);
					count += buff_ind;
				}
			}
		else if (*format == 'c')
		{
			int ch = va_arg(args, int);

			buffer[buff_ind++] = ch;
			if (buff_ind == BUFF_SIZE)
			{
				_puts(buffer, &buff_ind);
				count += buff_ind;
			}
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char *);

			while (*str)
			{
				buffer[buff_ind++] = *str;
				str++;
				if (buff_ind == BUFF_SIZE)
				{
					_puts(buffer, &buff_ind);
					count += buff_ind;
				}
			}
		}
		else if (*format == 'd' || *format == 'i')
		{
			int value = va_arg(args, int);

			sh = print_int(value);
			count += sh;
		}
	}
	else
	{
		buffer[buff_ind++] = *format;
		if (buff_ind == BUFF_SIZE)
		{
			_puts(buffer, &buff_ind);
			count += buff_ind;
		}
	}

		format++;
	}
		_puts(buffer, &buff_ind);
		count += buff_ind;
		va_end(args);
	return (count);
}
