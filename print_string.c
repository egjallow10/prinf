#include "main.h"
/**
  * print_string - prints the input string
  * @string: string pointer
  * Return: number of printed strings(excluding null byte)
  */

int print_string(char *string){
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        count += _putchar(string[i]);
    }
    return(count);
}
