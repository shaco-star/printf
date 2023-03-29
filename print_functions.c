#include "main.h"
#include <unistd.h>

specifier_t specifiers[] = {
	{"c", print_char},
	{"s", print_string},
	{"%", print_percent},
	{NULL, NULL}
};

/**
 * _strlen - return length of string
 *
 * @s: string
 *
 * Return: length
*/

int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * print_char - print char
 *
 * @args: arguments
 *
 * Return: int
*/

int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * print_string - print char
 *
 * @args: arguments
 *
 * Return: int
*/

int print_string(va_list args)
{
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(NULL)";

	return (write(1, s, _strlen(s)));
}


/**
 * print_percent - print char
 *
 * @args: argument
 *
 * Return: int
*/

int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
