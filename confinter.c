#include "main.h"

/**
 * convert - converts number
 * @num: input number
 * @base: input base
 * @lowercase: flag  hexa
 *
 * Return: result
 */

char *convert(unsigned long int num, int base, int lowercase)
{
	static char *r;
	static char buffer[50];
	char *p;

	r = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = r[num % base];
		num /= base;

	} while (num != 0);

	return (p);
}

