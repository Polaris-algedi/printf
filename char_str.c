#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: pointer to a string.
 *
 * Return: the length of a string.
 */

size_t _strlen(char *s)
{
	if (!s || !*s)
		return (0);
	return (1 + _strlen(++s));
}

/**
 * p_str - prints a string
 * @args: list of arguments passed to printf
 *
 * Return: number of characters printed
 */
ssize_t p_str(va_list args)
{
	size_t len = 0;
	char *s = NULL;

	s = va_arg(args, char *);
	len = _strlen(s);

	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, len));
}

/**
 * p_char - prints a character
 * @args: list of arguments passed to printf
 *
 * Return: number of characters printed
 */
ssize_t p_char(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * p_percent - prints the percent character
 * @args: list of arguments passed to printf
 *
 * Return: number of characters printed
 */
ssize_t p_percent(__attribute__((unused)) va_list args)
{
	int c = '%';

	return (write(1, &c, 1));
}
