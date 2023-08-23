#include <stdarg.h>
#include "main.h"

/**
 * print_arg - Choose which function to use
 * @format: Arguments list
 * @index: character index
 * @args: va_list
 *
 * Return: Number of characters to print
 */
int print_arg(const char *format, int index, va_list args)
{
	char next_c = *(format + index + 1);

	if (next_c == '\0')
	{
		return (_putchat(next_c));
	}
	else if (next_c == 'c')
	{
		return (print_char(args));
	}
	else if (next_c == 's')
	{
		return (print_string(args));
	}
}



/**
 * _printf - Print string passed and convert arguments if any
 * @format: Arguments list passed to the function
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int length;
	int index;

	length = 0;
	index = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	while (*(format + index))
	{
		char c = *(format + index);

		if (c != '%')
		{
			_putchar(c);
			length++;
		}
		else
		{
			length += print_arg(format, index, args);
			index++;
		}

		index++;
	}

	va_end(args);

	return (length);
}
