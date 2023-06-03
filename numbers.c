#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * p_int - prints an integer using write function
 * @Dividend: integer to print
 * Return: number of characters printed
 */
ssize_t p_int(ssize_t Dividend)
{
	ssize_t Divisor = 10, chars_printed = 0;
	ssize_t Remainder;
	char nbr, sign = '-';

	if (Dividend < 0)
	{
		chars_printed = write(1, &sign, 1);
		Dividend *= -1;
	}

	if (Dividend >= Divisor)
		chars_printed += p_int(Dividend / Divisor);

	Remainder = Dividend % Divisor;
	nbr = Remainder + '0';
	return (chars_printed + write(1, &nbr, 1));
}

/**
 * p_digit - gets the integer and call p_int
 * @args: list of args passed to printf
 * Return: number of characters printed
 */
ssize_t p_digit(va_list args)
{
	ssize_t Dividend = va_arg(args, int);

	return (p_int(Dividend));
}


/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned integer
 * Return: number of characters printed
 */
ssize_t print_binary(unsigned int n)
{
	unsigned int i, chars_printed = 0;
	char bit;

	if (n > 1)
		chars_printed += print_binary(n >> 1);

	i = n & 1;
	bit = '0' + i;
	return (chars_printed + write(1, &bit, 1));
}
/**
 * p_binary - gets the integer and call print_binary
 * @args: list of args passed to printf
 * Return: number of characters printed
 */
ssize_t p_binary(va_list args)
{
	ssize_t integer = va_arg(args, int);

	return (print_binary(integer));
}
