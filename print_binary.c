#include "main.h"
#include <stdlib.h>

/**
 * print_binary - function that converts a number into binary
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_binary(va_list list)
{
	int num = va_arg(list, int);
	int i = 0;
	unsigned int mask;
	int binary_digits = sizeof(num) * 8;
	int leading_zero = 1;

	if (num < 0)
		return (-1);
	if (num < 2)
	{
		_putchar('0' + num);
		_putchar('\n');
		return (1);
	}

	for (i = binary_digits - 1; i >= 0; i--)
	{
		mask = 1 << i;

		if (num & mask)
		{
			leading_zero = 0;
			_putchar('1');
		}
		else if (!leading_zero)
			_putchar('0');
	}
	return (1);
}

