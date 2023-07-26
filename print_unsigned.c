#include "main.h"
#include <stdlib.h>

/**
 * print_unsigned - function that prints only unsigned numbers
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_unsigned(va_list list)
{
	int num = va_arg(list, unsigned int);
	unsigned int divisor = 1;
	int nb = num;
	int digit;

	if (num == 0)
		_putchar('0');
	if (num < 0)
		return (-1);
	while (num >= 10)
	{
		divisor *= 10;
		num /= 10;
	}

	while (divisor > 0)
	{
		digit = (nb / divisor) % 10;
		_putchar('0' + digit);
		divisor /= 10;
	}

	return (1);
}
