#include "main.h"
/**
 * print_hexadecimal_min - function that outputs a number in
 *			hexadecimal format(minuscule)
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/

int print_hexadecimal_min(va_list list)
{
	int num = va_arg(list, int);
	unsigned int *buffer_int;
	int index = 0, i = 0;
	int temp_num = num;

	while (temp_num > 0)
	{
		temp_num /= 10;
		i++;
	}
	buffer_int = (unsigned int *)malloc(sizeof(int) * i);

	if (num < 0)
		return (-1);
	if (num < 10)
	{
		_putchar('0' + num);
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
			_putchar('a' + buffer_int[i] - 10);
		else
			_putchar('0' + buffer_int[i]);
	}
	free(buffer_int);
	return (1);
}
