#include "main.h"
/**
 * print_str - function that outputs a string
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_str(va_list list)
{
	int i;
	char *str = va_arg(list, char*);

	for (i = 0 ; str[i] != '\0' ; i++)
		_putchar(str[i]);
	return (1);
}
