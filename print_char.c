#include "main.h"
/**
 * print_char - function that outputs a character
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_char (va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
