#include <stdarg.h>
#include "main.h"

/**
 * print_char - Prints a character
 * @args: A list containing the character to print
 *
 * Return: 1
 */
int print_char(va_list args)
{
	int c = va_arg(args, int);

	_putchar(c);

	return (1);
}

/**
 * print_string - Prints a string
 * @args: A list containing the string to be printed
 *
 * Return: Length of printed string
 */
int print_string(va_list args)
{
	int length = 0;
	char *str = va_arg(args, char *);

	if (str == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[length] != '\0')
		length++;

	write(1, str, length);

	return (length);
}
