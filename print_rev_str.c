#include "main.h"
/**
*long_str - calculate the length of string
*@str: string
*Return: int
*/
int long_str(const char *str)
{
if (*str == '\0')
return (0);
return (1 + long_str(str + 1));
}
/**
* print_rev_str - print string in reverse order
* @list: list of arguments
* Return: int
*/
int print_rev_str(va_list list)
{
int len_str = 0;
int len_printed_char = 0;
int i = 0;
const char *str;
str = va_arg(list, char *);
len_str = long_str(str);
for (i = (len_str - 1) ; i >= 0 ; i--)
{
_putchar(str[i]);
len_printed_char++;
}
return (len_printed_char);
}
