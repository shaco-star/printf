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
	  static specifier_t specifiers[] = {
		   {"c", print_char},
		   {"s", print_string},
		   {"%", print_percent},
		   {NULL, NULL}
	   };
	va_list args;
	int count = 0, i;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; specifiers[i].spec; i++)
			{
				if (*format == *(specifiers[i].spec))
				{
					count += specifiers[i].f(args);
					break;
				}
			}
			if (!specifiers[i].spec)
			{
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;

	}
	va_end(args);
	return (count);
}
