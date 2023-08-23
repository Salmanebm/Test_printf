#ifndef MAIN_H
#define MAIN_H

/**
 * struct format - a structure that maps a specifier
 *
 * @c: the conversion specifier character
 * @f: a pointer to the function that handles the conversion specifier
 */
typedef struct format
{
	char c;
	int (*f)();
} main_struct;

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

int _strlenc(const char *s);
int _strlen(char *s);
void _flush_buffer(char *buffer, size_t size);
int _putchar(char);
int print_string(va_list);
int _printf(const char *format, ...);
int print_int(va_list);
int print_perc(void);
int print_char(va_list);

#endif
