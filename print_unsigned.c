#include "main.h"
#include <stdlib.h>

/**
 * nb_digits - calculate number of digites of number
 * @n: number
 * Return: int
 **/
int nb_digits(unsigned int n)
{
	if (n == 0)
		return (0);
	return (1 + nb_digits(n / 10));
}
/**
 *  nb_to_str - Convert an unsigned integer to a string representation.
 *  @n: unsigned number
 *  Return: pointer to char
 **/
char *nb_to_str(unsigned int n)
{
	int size, rem;
	int idx = 0;
	char *ptr;

	size = nb_digits(n);
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[size] = '\0';
	idx = size - 1;
	while (idx >= 0)
	{
		rem = n % 10;
		n = n / 10;
		ptr[idx] = rem + '0';
		idx--;
	}
	return (ptr);
}

/**
 * print_unsigned - function that prints only unsigned numbers
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_unsigned(va_list list)
{
	unsigned int nb = va_arg(list, unsigned int);
	char *ptr_nb;
	int len = 0;

	if (nb <= 9)
	{
		_putchar(nb + '0');
		return (1);
	}
	ptr_nb = nb_to_str(nb);
	if (ptr_nb == NULL)
		return (0);
	while (ptr_nb[len] != '\0')
	{
		_putchar(ptr_nb[len]);
		len++;
	}
	free(ptr_nb);
	return (len);
}
