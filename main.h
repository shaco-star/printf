#ifndef _PRINTF
#define _PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct flags
 * @plus: flag '+'
 * @space: flag ' '
 * @hash: flag '#'
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_x;

/**
 * struct printHandler - struct to Handler function 
 * @c: format
 * @f: pointer to function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_x *f);
} printh;

int print_hex(va_list l, flags_x *f);

int print_hex_big(va_list l, flags_x *f);

int print_binary(va_list l, flags_x *f);

int print_octal(va_list l, flags_x *f);

int _printf(const char *format, ...);

int print_int(va_list l, flags_x *f);

void print_number(int n);

int print_unsigned(va_list l, flags_x *f);

int count_digit(int i);

int print_string(va_list l, flags_x *f);

int print_char(va_list l, flags_x *f);

#endif
