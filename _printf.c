#include "main.h"

/**
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int specifier_count = 0;
	int printed =  0;
	va_list list;
	int va_arg1;
	char *va_arg2;

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
			printed++;
		}
		else if (format[i] == '%')
		{
			i++;
			specifier_count++;

			va_start(list, format);
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
			}
		}
	}
	return (printed);
}
