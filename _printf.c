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

extern specifier_t specifiers[];

int _printf(const char *format, ...)
{
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
