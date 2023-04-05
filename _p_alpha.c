#include "main.h"

/**
 * print_string - loops for string and prints
 *
 * @l: va_list args
 * @f: pointer to struct
 *
 * Return: number of char
 */
int print_string(va_list l, flags_x *f)
{
	char *str = va_arg(l, char *);

	(void)f;

	if (!str)
		str = "(null)";
	return (_puts(str));
}

/**
 * print_char - prints a character
 *
 * @l: va_list arguments
 * @f: pointer tostruct
 *
 * Return: number char
 */

int print_char(va_list l, flags_x *f)
{
	(void)f;

	_putchar(va_arg(l, int));

	return (1);

}

