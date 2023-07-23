#include <stdio.h>
#include <stdlib.h>

int _putint(int n)
{
    int is_negative = 0;
    char digits[20];
    int i = 0;
    int printed = 0;

    if (n < 0) {
        is_negative = 1;
        n = -n;
    }

    while (n != 0) {
        digits[i++] = '0' + (n % 10);
        n /= 10;
    }

    if (i == 0) 
    {
        putchar('0');
	printed++;
    } 
    else 
    {
        if (is_negative) 
	{
            putchar('-');
	    printed++;
        }
        while (i > 0) 
	{
            putchar(digits[--i]);
	    printed++;
        }
    }
    return (printed);
}
