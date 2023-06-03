#ifndef PRINTF_
#define PRINTF_

/**
 * struct mymap - A struct that represents a map.
 * @c: A format specifier.
 * @f: A function pointer.
 *
 * Description: The struct mymap consists of a character c and a function
 * pointer f that takes a va_list argument and returns a ssize_t value.
 */
struct mymap
{
	char c;
	ssize_t (*f)(va_list);
};

/**
 * mymap_t - typedef for struct mymap
 */
typedef struct mymap mymap_t;

int _printf(const char *format, ...);
size_t _strlen(char *s);
ssize_t p_str(va_list args);
ssize_t p_char(va_list args);
ssize_t p_percent(__attribute__((unused)) va_list args);
ssize_t p_int(ssize_t Dividend);
ssize_t p_digit(va_list args);
ssize_t print_binary(unsigned int n);
ssize_t p_binary(va_list args);
ssize_t (*get_p_func(char c))(va_list);


#endif
