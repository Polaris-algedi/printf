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
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (get_p_func(*format) == NULL)
			{
				if (*format == '\0')
					return (-1);

				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
			else
				count += get_p_func(*format)(args);
		}
		else
			count += write(1, format, 1);

		format++;
	}
	va_end(args);
	return (count);
}
