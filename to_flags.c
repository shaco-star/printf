#include "main.h"

/**
 * get_flag - get flags
 * 
 * @s: character
 * @f: pointer to struct
 *
 * Return: 1 or 0 otherwise
 */

int get_flag(char s, flags_x *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}