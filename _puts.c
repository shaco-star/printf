#include "main.h"
#include <unistd.h>

/**
 * _puts - prints string
 * @str: pointer to the string
 * Return: number
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}