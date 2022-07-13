#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
  * _printf - declares the array for different types
  * @format: format of the string to be printed out
  * Return: number of values printed
  */

int _printf(const char *format, ...){
    int count, i = 0;
    va_list data;
    va_start(data, format);




	for(i = 0; format[i] != '\0'; ){
		if(format[i] != '%'){
		count = count + _putchar(format[i]);
		i++;
	}else if (format[i] == '%'&& format[i + 1] !=' ')
	{
		switch (format[i + 1])
		{
		case 'c':
			/*print a char form arg*/
			va_arg(data, int);
			count = count +_putchar(va_arg(data, int));
			break;

		case 's':
			count = count + print_string(va_arg(data, char *));
			break;
		case '%':
			count = count + _putchar('%');
			break;

		default:
			break;
		}
		i+= 2;
	}

	}
	return(count);
}
