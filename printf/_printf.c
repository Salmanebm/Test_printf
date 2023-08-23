#include "main.h"

/**
 * _printf - prints anything
 * @format: the string to be formatted
 * Return: (printed) the numeber of printed characters
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int specifier_count = 0;
	int printed =  0;
	va_list list;
	int va_arg1;
	char *va_arg2;
	int va_arg3;

	va_start(list, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed++;
		
		}
		else if (format[i] == '%')
		{
			i++;
			specifier_count++;
			switch (format[i])
			{
				case 'c':
					va_arg1 = va_arg(list, int);
					_putchar(va_arg1);
					printed++;
					break;
				case 's':
					va_arg2 = va_arg(list, char *);
					_puts(va_arg2);
					printed++;
					break;
				case '%':
					_putchar(format[i]);
					printed++;
					break;
				case 'i':
				case 'd':
					va_arg3 = va_arg(list, int);
					_putint(va_arg3);
					printed++;
					break;
			}
		}
		i++;
	}
	va_end(list);

	return (printed);
}
