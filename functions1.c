#include <stdio.h>
#include <unistd.h>

/**
 * _strlen - counts the length of a string
 * @str: string to be measured
 *
 * Return: length of the string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return length;
}

/**
 * printString - prints a string
 * @str: string to print
 *
 * Return: number of characters printed
 */
int printString(char *str)
{
    int len = 0;
    
    if (str == NULL)
        str = "(null)";

    len = _strlen(str);
	return (write(1, str, len));
}
