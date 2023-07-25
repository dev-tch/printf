#include "main.h"
/**
 * print_hexadecimal_maj - function that outputs a number in
 *			hexadecimal format(majuscule)
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/

int print_hexadecimal_maj(va_list list)
{
	int num = va_arg(list, int), buffer_int[10];
	int index = 0, i = 0;

	if (num < 0)
		return (-1);
	if (num < 10)
	{
		_putchar('0' + num);
		_putchar('\n');
		return (1);
	}
	while (num > 0)
	{
		buffer_int[index++] = num % 16;
		num /= 16;
	}
	for (i = index - 1; i >= 0; i--)
	{
		if (buffer_int[i] >= 10)
			_putchar('A' + buffer_int[i] - 10);
		else
			_putchar('0' + buffer_int[i]);
	}
	_putchar('\n');
	return (1);
}
