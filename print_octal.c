#include "main.h"
/**
 * print_octal - function that outputs a number in octal format
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/

int print_octal(va_list list)
{
	int num = va_arg(list, int), buffer_int[10];
	int index = 0, i = 0;

	if (num < 0)
		return (-1);
	if (num < 8)
	{
		_putchar('0' + num);
		_putchar('\n');
		return (1);
	}
	while (num > 0)
	{
		buffer_int[index++] = num % 8;
		num /= 8;
	}
	for (i = index - 1; i >= 0; i--)
		_putchar('0' + buffer_int[i]);
	_putchar('\n');
	return (1);
}
