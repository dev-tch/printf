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
	unsigned int num = va_arg(list, unsigned int);
	unsigned int *buffer_int;
	int i = 0, index = 0;
	unsigned int temp_num = num;

	if (num < 2)
	{
		_putchar('0' + num);
		_putchar('\n');
		return (1);
	}
	while (temp_num > 0)
	{
		i++;
		temp_num = temp_num / 2;
	}

	buffer_int = (unsigned int *)malloc(sizeof(unsigned int) * i);

	if (!buffer_int)
		return (-1);

	while (num > 0)
	{
		buffer_int[index++] = num % 2;
		num = num / 2;
	}

	for (i = index - 1; i >= 0; i--)
		_putchar('0' + buffer_int[i]);

	_putchar('\n');
	free(buffer_int);
	return (1);
}

