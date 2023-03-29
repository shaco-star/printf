#ifndef _PRINTF
#define _PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct specifier
{
	char *spec;
	int (*f)(va_list);
} specifier_t;

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);
int func(const char *format, specifier_t *specifiers, va_list args);
#endif
