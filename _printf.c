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
	va_list args;
	int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
			continue;
		}
		format++;
		switch (*format)
		{
			case 'c':
				count += print_char(args);
				break;
			case 's':
				count += print_string(args);
				break;
			case '%':
				count += print_percent();
				break;
			default:
				break;
		}
	}
	va_end(args);
	return (count);
}
