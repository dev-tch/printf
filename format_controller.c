#include "main.h"
/**
* format_controller - process the string to format
* @fmt: string
* @args: list of arguments
* Return: size of print characters
*/
int format_controller(const char *fmt, va_list args)
{
int len_printed_chars = 0, len_handled_spec = 0;
const char *current, *next;
/*check if pointer to fmt is valid*/
if (fmt == NULL)
return (-1);
/*iterate throught fmt*/
while (*(current = fmt) != '\0')/*loop1 :start while*/
{
fmt++;
next = fmt;
if (*current != '%')/* cd1: start if*/
{
/*print the current character and maj len_printed_chars*/
_putchar(*current);
len_printed_chars++;
continue;
} /*cd1: end if*/
/* here we have currrent equals %*/
/*we check if next is % : specifier %%*/
if (*next == '%') /*cd2: start if*/
{
_putchar(*current);
fmt++;
len_printed_chars++;
continue;
} /*cd2: end if */
/*if next not equals % we have to  process the specifier*/
if (*next != '\0')
{
fmt++;
len_handled_spec = handle_specifier(next, args);
}
if (len_handled_spec == -1)
return (-1);
else
len_printed_chars += len_handled_spec;
} /*loop1 :end while*/
return (len_printed_chars);
}

/**
* handle_specifier - print argument variable if we meet the character %
* @str: the current pointer to str
* @args: list of arguments
*Return: number of printed characters
*/

int handle_specifier(const char *str, va_list args)
{
int j = 0;
int len_printed_chars = 0;
int nb_specs = 0;
/*declare array of struct format*/
format print_specs[] = {
	{'c', print_char},
	{'s', print_str},
	{'d', parse_form_speci},
	{'i', parse_form_speci},
	{'r', print_rev_str},
	{'b', print_binary},
	{'R', print_Rot13},
	{'u', print_unsigned},
	{'o', print_octal},
	{'x', print_hexadecimal_min}
};
/*loop throught array print_specs*/
nb_specs = sizeof(print_specs) / sizeof(print_specs[0]);
for (j = 0; j < nb_specs; j++)
{
if (*str == print_specs[j].spec)
{/*call the pointer function*/
len_printed_chars = print_specs[j].format_spec(args);
return (len_printed_chars);
}
} /*end for*/
_putchar('%');
_putchar(*str);
return (2);
}


