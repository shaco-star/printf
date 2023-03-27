#include "main.h"
#include <unistd.h>

/** print_int - print number
 *
 * @n: take number
*/

void print_int(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10 != 0)
		print_int(n / 10);

	c = n % 10 + '0';
	write(1, &c, 1);
}
