#include "main.h"
/**
 * print_decimal - function that outputs a number in decimal format
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/

int print_decimal(va_list list)
{
	int num = va_arg(list, int), buffer_int[10];
	int index = 0, i = 0;
	char sign;

	if (num < 0)
	{
		sign = '-';
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (1);
	}
	while (num > 0)
	{
		buffer_int[index++] = num % 10;
		num /= 10;
	}
	if (sign == '-')
		_putchar('-');
	for (i = index - 1; i >= 0; i--)
		_putchar('0' + buffer_int[i]);
	_putchar('\n');
	return (1);
}


