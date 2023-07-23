#include "main.h"

/**
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int i = specifier_count = printed =  0;
	va_list list;
	char va_arg1;
	char *va_arg2;

	while (format[i])
	{
		if (format[i] != '%') // no format specifier
		{
			_putchar(format[i]);
			printed++;
		}
		else if (format[i] == '%')
		{
			i++; // skip the % sign and parse what is next to it
			specifier_count++; //counting the printed variable arguments

			va_start(list, foramt)
			switch (format[i])
			{
				case 'c':
					va_arg1 = va_arg(list, int)
					_putchar(va_arg1);
					printed++;
					break;
				case 's':
					va_arg2 = va_arg(list, char *)
					_puts(va_arg2);
					printed++;
					break;
			}
		}
	}
	return (printed);
}
