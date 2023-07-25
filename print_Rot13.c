#include "main.h"
/**
*str_length - calculate the length of string
*@str: string
*Return: int
*/
int str_length(const char *str)
{
if (*str == '\0')
return (0);
return (1 + str_length(str + 1));
}

/**
* rot13 - convert string to Rot13 encryption
* @str: string to encrypt
* Return: pointer to str
*/

char *rot13(const char *str)
{
int i = 0, j = 0, len = 0;
char *res;
char bases[] = {'a', 'z', 'A', 'Z'};
/*when is the len of str */
len = str_length(str);
/*reserve the memory for  conveted string*/
res = (char *) malloc(len + 1);
if (res == NULL)
{
return (NULL);
}
while (str[i] != '\0')
{
char c = str[i];
while (j < 4)
{
if (c >= bases[j]  && c <= bases[j + 1])
{
c = bases[j] + ((c - bases[j] + 13) % 26);
break;
}
j = j + 2;
}
res[i] = c;
i++;
j = 0;
}
res[i] = '\0';
return (res);
}
/**
* print_Rot13 - print string with format encryption Rot13
* @list: list of arguments
* Return: length of printed characters
*/
int print_Rot13(va_list list)
{
const char *str;
char *res;
int len = 0, i = 0;
str = va_arg(list, char *);
res = rot13(str);
if (res == NULL)
{
return (-1);
}
while (res[i] != '\0')
{
_putchar(res[i]);
len++;
i++;
}
free(res);
return (len);
}
