#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int count = 0, c;
	char *s;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;

				case 's':
					s = va_arg(args, char *);
					printString(s);
					break;

				case '%':
					write(1, "%", 1);
					count++;
					break;

			}
		} else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
