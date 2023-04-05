#include "main.h"

/**
 * print_hex - prints to number
 * 
 * @l: va_list arguments
 * @f: pointer to struct
 * 
 * Return: the number of char printed
 */
int print_hex(va_list l, flags_x *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *strhex = convert(num, 16, 1);
	int n = 0;

	if (f->hash == 1 && strhex[0] != '0')
		n += _puts("0x");
	n += _puts(strhex);
	return (n);
}

/**
 * print_hex_big - prints hexadecimal base,
 * @l: va_list arguments
 * @f: pointer to struct
 * Return: number
 */
int print_hex_big(va_list l, flags_x *f)
{
	unsigned int num = va_arg(l, unsigned int);

	char *strhex = convert(num, 16, 0);
	int n = 0;

	if (f->hash == 1 && strhex[0] != '0')
		n += _puts("0X");
	n += _puts(strhex);
	return (n);
}

/**
 * print_binary - prints number
 * 
 * @l: va_list arguments
 * @f: pointer struct
 * 
 * Return: number
 */
int print_binary(va_list l, flags_x *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *strhex = convert(num, 2, 0);

	(void)f;
	return (_puts(strhex));
}

/**
 * print_octal - prints number
 * @l: va_list arguments
 * @f: pointer struct
 * 
 * Return: number
 */
int print_octal(va_list l, flags_x *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *strhex = convert(num, 8, 0);

	int n = 0;

	if (f->hash == 1 && strhex[0] != '0')
		n += _putchar('0');

	n += _puts(strhex);

	return (n);
}