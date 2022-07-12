#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * print_format - prints the input string
  * @format: format string
  * @input: input array from variable argument list
  * @type_element: pointer to an array of structures of type Convert type
  * Return: number of printed characters (excluding null byte)
  */
int print_format(const char *format, va_list input, Convert_Type *type_element)
{
	const char *copy_format;
	int type_index, num_printed = 0;

	if (format != NULL)
		copy_format = format;
	else
		return (-1);
	while (*copy_format != '\0')
	{
		type_index = 0;
		if (*copy_format == '%')
		{
			while (type_element[type_index].format != NULL)
			{
				if (*(type_element[type_index].format) == *(copy_format + 1))
				{
					num_printed += type_element[type_index].print_type(input);
					copy_format++;
					break;
				}
				type_index++;
			}
		}
		else
			num_printed += print_single_char(copy_format);
		if (type_element[type_index].format == NULL)
		{
			if (*(copy_format + 1) != '%' && *(copy_format + 1) != '\0')
				num_printed += print_single_char(copy_format);
			if (*(copy_format + 1) != '\0')
				num_printed += print_single_char(++copy_format);
		}
		if (*copy_format == '%' && *(copy_format + 1) == '\0'
				&& *(copy_format - 1) != '%')
			num_printed = -1;
		if (*(copy_format) != '\0')
			copy_format++;
	}
	va_end(input);
	return (num_printed);
}

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

/**
  * check_null_str - checks if any of the inputs for %s is NULL
  * @format: format string
  * @input: input from variable argument list
  * Return: 1 if there is a NULL input
  */
int check_null_str(const char *format, va_list input)
{
	va_list copy_input;

	va_copy(copy_input, input);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(++format) == 's')
			{
				if (va_arg(copy_input, char *) == NULL)
					return (1);
			}
		}
		format++;
	}
	va_end(copy_input);
	return (0);
}

