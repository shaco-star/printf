#include "main.h"

/**
 * print_int - prints integer
 * @l: va_list for int
 * @f: pointer for flags
 * Return: number
 */
int print_int(va_list l, flags_x *f)
{
	int num = va_arg(l, int);
	int res = count_digit(num);

	if (f->space == 1 && f->plus == 0 && num >= 0)
		res += _putchar(' ');

	if (f->plus == 1 && num >= 0)
		res += _putchar('+');

	if (num <= 0)
		res++;

	print_number(num);

	return (res);
}

/**
 * print_unsigned - prints unsigned integer
 * @l: va_list
 * @f: pointer for flags
 * Return: number
 */
int print_unsigned(va_list l, flags_x *f)
{
	unsigned int x = va_arg(l, unsigned int);
	char *strs = convert(x, 10, 0);

	(void)f;

	return (_puts(strs));
}

/**
 * print_number - helper function
 * 
 * @n: integer
 */

void print_number(int n)
{
	unsigned int nn;

	if (n < 0)
	{
		_putchar('-');

		nn = -n;
	}
	else
		nn = n;

	if (nn / 10)
		print_number(nn / 10);

	_putchar((nn % 10) + '0');
    
}

/**
 * count_digit - returns number
 * 
 * @i: integer
 * 
 * Return: number
 */

int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;

	while (u != 0)
	{
		u /= 10;
		d++;
	}

	return (d);
}