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

	va_start(list, format);
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
			switch (format[i])
			{
				case 'c':
					va_arg1 = va_arg(list, int);
					_putchar(va_arg1);
					printed++;
					break;
				case 's':
					va_arg2 = va_arg(list, char *);
					if (va_arg2)
					{
						_puts(va_arg2);
						printed++;
					}
					else
					{
						perror("Error, string printing");
					
					}
					break;
				case '%':
					_putchar(format[i]);
					printed++;
			}
			i++;
		}
	}
	return (printed);
}
