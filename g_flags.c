
#include "main.h"

/**
 * get_flags - Calculates
 * @format: Formatted string
 * @i: parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cr_i;
	int flags = 0;
	const char flags_char[] = {'-', '+', '0', '#', ' ', '\0'};
	const int arr_flags[] = {1, 2, 4, 8, 16, 0};

	for (cr_i = *i + 1; format[cr_i] != '\0'; cr_i++)
	{
		for (j = 0; flags_char[j] != '\0'; j++)
			if (format[cr_i] == flags_char[j])
			{
				flags |= arr_flags[j];
				break;
			}

		if (flags_char[j] == 0)
			break;
	}

	*i = cr_i - 1;

	return (flags);
}
