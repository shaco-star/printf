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
	char c, *s;

	va_start(args, format);
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
			case '%':
				write(1, "%", 1);
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
		}
	}
	va_end(args);
	return (count);
}
