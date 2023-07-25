#include "main.h"
/**
* conv_val_to_base - convert value to base N
* @number: format number in base decimal
* @base: destination format base
* Return: pointer to char
*/
char *conv_val_to_base(long int number, int  base)
{
const  char  items_of_bases[] = "0123456789abcdef";
/*A static local variable retains its value across multiple function calls*/
static char buffer[50];
char sign = '0';
char *ptr;
unsigned long nb = number;
if (number < 0)
{
nb = -number;
sign = '-';
}
ptr = &buffer[49];
*ptr =  '\0';
do {
*--ptr =  items_of_bases[nb % base];
nb  /= base;
} while (nb != 0);
if (sign)
*--ptr = sign;
return (ptr);
}
/**
* print_items_of_str  - print chars of strings
* @str: string to print
* Return: number of chars printed
*/
int print_items_of_str(char *str)
{
int len = 0;
while (*str != '\0')
{
_putchar(*str);
str++;
len++;
}
return (len);
}
/**
 * compareStrings - Compare two strings
 * @this_str: String 1
 * @other_str: String 2
 * Return: Integer
 **/
int compareStrings(char *this_str, char *other_str)
{
int i;
for (i = 0; this_str[i] != '\0'; i++)
{
if (this_str[i] != other_str[i])
return (this_str[i] - other_str[i]);
}
return (0);
}
/**
* print_memory_address - print to console the chars of adress
* @list: list of arguments
* Return: number of printed chars
*/
int print_memory_address(va_list list)
{
long  int address_value;
char *ptr;
int len = 0;
address_value =  va_arg(list, unsigned long  int);
/*case adress_value NULL*/
if (address_value == 0)
{
len = print_items_of_str("(nil)");
return (len);
}
ptr = conv_val_to_base(address_value, 16);
/*if ptr is NULL we must return (nil) like the standart lib printf*/
if (!compareStrings(ptr, "0"))
return (print_items_of_str("(nil)"));
/*print the prefix of hexa(0x)*/
len += print_items_of_str("0x");
/*if pointer contains only the value (-1) that's mean*/
/* we are in the maximum adress*/
/*0xFFFFFFFFFFFFFFFF*/
if (!compareStrings(ptr, "-1"))
len += print_items_of_str("ffffffffffffffff");
else
{
/*we have to increment the pointer if  we meet zero in the first index*/
if (ptr[0] != '-' && ptr[0] == '0')
ptr++;
len += print_items_of_str(ptr);
}
return (len);
}
