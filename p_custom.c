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

#include "main.h"

/**
 * print_addres_s_p - prints address hexa format
 * @l: va_list arguments
 * @f: pointer to struct
 * Return: number
 */

int print_address_s_p(va_list l, flags_x *f)
{
	char *strn;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));

	strn = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(strn);

	return (count);
}

/**
 * print_percent - prints a percent
 * @l: va_list args
 * @f: pointer to flags
 * Return: number
 */
int print_percent(va_list l, flags_x *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}