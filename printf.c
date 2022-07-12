#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _printf - declares the array for different types
  * @format: format of the string to be printed out
  * Return: number of values printed
  */

int _printf(const char *format, ...)
{
	Convert_Type type_element[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_decimal},
		{"i", print_decimal},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_low},
		{"X", print_hex_cap},
		{"r", print_rev_str},
		{"R", print_rot13},
		{"p", print_address},
		{"S", print_unprint},
		{NULL, NULL}
	};
	va_list input;

	va_start(input, format);
	return (print_format(format, input, type_element));
}

