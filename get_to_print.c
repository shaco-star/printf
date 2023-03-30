#include "main.h"

/**
 * get_print - function to selects right printing
 *
 * @s: character
 *
 * Description: structs array
 *
 * Return: pointer
 */

int (*get_print(char s))(va_list, flags_x *)
{
	printh func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'S', print_big_char},
		};

	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);

	return (NULL);
}

