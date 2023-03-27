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
	int count = 0, n;
	char c, *s;

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
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
				break;
			case 's':
				s = va_arg(args, char *);
				for (; *s != '\0'; s++)
				{
					write(1, s, 1);
					count++;
				}
				break;
			case 'd':
			case 'i':
				n = va_arg(args,int);
				print_int(n);
				break;
		}
	}
	va_end(args);
	return (count);
}
