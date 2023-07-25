#include "main.h"
/**
 * print_binary - function that converts a number into binary
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_binary(va_list list)
{
	int num = va_arg(list, int);
	int buffer_int[32];
	int i, index = 0;

	if (num < 0)
		return (-1);
	if (num < 2)
	{
		_putchar('0' + num);
		_putchar('\n');
		return (1);
	}

	while (num > 0)
	{
		buffer_int[index++] = num % 2;
		num = num / 2;
	}

	for (i = index - 1; i >= 0; i--)
		_putchar('0' + buffer_int[i]);

	_putchar('\n');
	return (1);
}

