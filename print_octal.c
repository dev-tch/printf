#include "main.h"
/**
 * print_octal - function that outputs a number in octal format
 * @list: argument list containing a character to be printed.
 * Return: lenght of printed chararctes
 **/

int print_octal(va_list list)
{       /*the memory represent negative numbers as unsigned numbers*/
	unsigned int num = va_arg(list, unsigned int);
	char *buffer_int;
	int index = 0, i = 0, len_nb = 0, len_printed = 0;
	/*temp_num aux variable to get the lenght of number*/
	unsigned int temp_num = num;

	/*we verify if  one digit number  is passed*/
	if (num < 8)
	{
		_putchar('0' + num);
		return (1);
	}
	while (temp_num > 0)
	{
		temp_num /= 10;
		len_nb++;
	}
	buffer_int = (char *)malloc(len_nb);
	/*check if malloc failed*/
	if (buffer_int == NULL)
	{
		return (-1);
	}

	while (num > 0)
	{
		buffer_int[index++] = (num % 8 + '0');
		num /= 8;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(buffer_int[i]);
		len_printed++;
	}
	free(buffer_int);
	return (len_printed);
}
