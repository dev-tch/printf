#include "main.h"
/**
 * print_octal - function that outputs a number in octal format
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/

int print_octal(va_list list)
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
	if (num < 8)
	{
		_putchar('0' + num);
		return (1);
	}
	while (num > 0)
	{
		buffer_int[index++] = num % 8;
		num /= 8;
	}
	for (i = index - 1; i >= 0; i--)
		_putchar('0' + buffer_int[i]);
	free(buffer_int);
	return (1);
}
