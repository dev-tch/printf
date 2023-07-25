#include "main.h"
/**
 * print_str - function that outputs a string
 * @list: argument list containing a character to be printed.
 *
 * Return: 1 (Successful)
 **/
int print_str(va_list list)
{
int i, len = 0, ret_val;
char *str = va_arg(list, char*);
/*fix1 */
if (str == NULL)
return (-1);
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
