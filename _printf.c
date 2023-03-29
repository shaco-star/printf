#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - printf format
 *
 * @format: format
 *
 * Return: int
*/

int _printf(const char *format, ...)
{
	int (*printfunc)(va_list, flags_x *);
	const char *p;
	va_list args;
	flags_x f = {0, 0, 0};

	register int count = 0;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &f))
				p++;
			printfunc = get_print(*p);
			count += (printfunc)
				? printfunc(args, &f)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);

	va_end(args);
	return (count);

}

