#include "main.h"

int _putint(int n)
{
    int printed = 0;
    if (n < 0) {
        _putchar('-');
        printed++;
        n = -n;
    }
    if (n >= 10) {
        printed += _putint(n / 10);
    }
    _putchar('0' + n % 10);
    return printed + 1;
}
