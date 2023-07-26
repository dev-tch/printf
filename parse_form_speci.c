#include "main.h"
/****************************************************************
*  helper functions for our principal function parse_form_speci
*
***************************************************************/
/**
* get_nb_digits - calculate number of digites of number
* @n: number
* Return: int
*/
int get_nb_digits(int n)
{
n = n / 10;
if (n == 0)
return (1);
return (1 + get_nb_digits(n));
}

/**
* conv_nb_to_str - save number in pointer
* @n: number
* @sign : positive or negative
* Return: pointer to char
*/
/*function to full number in pointer  of chars*/
char *conv_nb_to_str(int n, char sign)
{
int size, rem;
int idx = 0;
char *ptr;
size = get_nb_digits(n);
/*one fo sign , one for '\0' and rest for number*/
ptr = (char *) malloc(1 +  1  +  size);
if (ptr == NULL)
{
return (NULL);
}
if (sign == 1)
ptr[0]  = '+';
else
ptr[0] = '-';
ptr[size + 1] = '\0';
idx = size;
while (idx  > 0)
{
rem = n % 10;
n = n / 10;
ptr[idx] = (rem *sign) + '0';
idx--;
}
return (ptr);
}
/**
* print_str_nb - print the digits of number
* @str: number with type string
* Return: number of chars printed
*/
int print_str_nb(char *str)
{
int len  = 0, j = 0;
while (str[j] != '\0')
{
if (j == 0 && str[j] == '-')
{
_putchar('-');
len++;
}
if (j > 0)
{
_putchar(str[j]);
len++;
}
j++;
} /*while loop*/
return (len);
}

/**
* parse_form_speci - print differents bases of int to decimal base
* @list: list of arguments
* Return: number of chars printed
*/
int parse_form_speci(va_list list)
{
int  nb  = 0;
int  sign = 1;
int  len  = 0;
char *ptr_nb =  NULL;
/*read the number from the list of arguments*/
nb =  va_arg(list, int);
/*save the sign of the number */
if (nb < 0)
{
sign = -1;
}
/*if number just one digit we print it */
if (nb  >= 0 && nb <= 9)
{
_putchar (nb + '0');
return (1);
}
if (nb < 0 && nb >= -9)
{
_putchar('-');
nb = nb *sign;
_putchar (nb + '0');
return (2);
}
ptr_nb = conv_nb_to_str(nb, sign);
if (ptr_nb == NULL)
{
/*return a value non zero for failed allocated memory*/
return (-1);
}
len = print_str_nb(ptr_nb);
free(ptr_nb);
return (len);
}
