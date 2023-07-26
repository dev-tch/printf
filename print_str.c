#include "main.h"
/**
 * print_str - function that outputs a string
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_str(va_list list)
{
int i, len = 0, ret_val, j = 0;
const char *nil_str = "(null)";
char *str = va_arg(list, char*);
/*fix1 */
if (str == NULL)
{/*(null)*/
for (j = 0 ; j < 6; j++)
{
len++;
_putchar(nil_str[j]);
}
return (6);
}
/*fix2*/
for (i = 0 ; str[i] != '\0' ; i++)
{
ret_val = _putchar(str[i]);
if (ret_val == -1)
return (-1);
len++;
}
return (len);
}
