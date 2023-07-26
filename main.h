#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
/*prototypes here */
int _putchar(char ch);
int print_char(va_list list);
int print_str(va_list list);
int print_decimal(va_list list);
int parse_form_speci(va_list list);
int print_rev_str(va_list list);
int print_Rot13(va_list list);
int _printf(const char*, ...);
int format_controller(const char*, va_list args);
int handle_specifier(const char *, va_list);
int print_binary(va_list list);
int print_unsigned(va_list list);
int print_octal(va_list list);
int print_hexadecimal_min(va_list list);
int print_hexadecimal_maj(va_list list);
int print_memory_address(va_list list);
int print_custom__string(va_list list);
/**
* struct _format - associate specifier with pointer function
* @spec: specifier
* @format_spec: pointer to function that will format specifier
* Description: Longer description
*/
typedef struct _format
{
char spec;
int (*format_spec)(va_list);
} format;

int print_hexadecimal(int num);
#endif


