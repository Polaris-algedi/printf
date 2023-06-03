#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_p_func - Selects the correct function to perform
 * the operation asked by the user
 * @c: The format specifier
 *
 * Return: A pointer to the function that corresponds to the
 * format specifier given as a parameter
 */
ssize_t (*get_p_func(char c))(va_list)
{
	mymap_t funcs[] = {
		{'c', p_char},
		{'s', p_str},
		{'%', p_percent},
		{'d', p_digit},
		{'i', p_digit},
		{'b', p_binary},
		{'\0', NULL},
	};

	int i = 0;

	if (c == '\0')
		return (NULL);

	while (funcs[i].c != c && funcs[i].f != NULL)
		i++;

	return (funcs[i].f);
}
