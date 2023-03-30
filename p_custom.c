#include "main.h"

/**
 * print_big_char - upper case characters
 * @l: va_list arguments
 * @f: pointer to struct
 * Return: number of char
 */

int print_big_char(va_list l, flags_x *f)
{
	int i, count = 0;
	char *resp;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");

			count += 2;
			resp = convert(s[i], 16, 0);
			if (!resp[1])
				count += _putchar('0');
			count += _puts(resp);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

