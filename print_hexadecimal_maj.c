#include "main.h"
/**
 * print_hexadecimal_maj - function that outputs a number in
 *			hexadecimal format(majuscule)
 * @list: argument list containing a character to be printed.
 *
 * Return: number of printed characters
 **/

int print_hexadecimal_maj(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char  *buffer_int;
	int index = 0, i = 0, len_nb = 0, len_printed = 0;
	unsigned int temp_num = num;
	const  char  items_of_bases[] = "0123456789ABCDEF";
	/*we verify if one digit passed*/
	if (num < 10)
	{
		_putchar('0' + num);
		return (1);
	}
	/*we calculate the length of number*/
	while (temp_num > 0)
	{
		temp_num /= 10;
		len_nb++;
	}
	buffer_int = (char *)malloc(len_nb);
	/*check if malloc failed*/
	if (buffer_int == NULL)
		return (-1);
	while (num > 0)
	{
		buffer_int[index++] = items_of_bases[num % 16];
		num /= 16;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(buffer_int[i]);
		len_printed++;
	}
	free(buffer_int);
	return (len_printed);
}
