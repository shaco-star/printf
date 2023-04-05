#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - printf format
 *
 * @format: format
 *
 * Return: int
*/


int _printf(const char *format, ...)
{
	  specifier_t specifiers[] = {
		   {"c", print_char},
		   {"s", print_string},
		   {"%", print_percent},
		   {"d", print_digit},
		   {"i", print_},
		   {NULL, NULL}
	   };
	va_list args;
	int count = 0;

	va_start(args, format);


	count = func(format, specifiers, args);


	va_end(args);
	return (count);
}
