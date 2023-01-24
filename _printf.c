#include <stdarg.h>
#include "holberton.h"
#include <stddef.h>

/**
 * pick_func - pick function based on char
 * @c: the char
 *
 * Return: pointer to function
 */

int (*pick_func(const char c))(va_list)
{
	int j = 0;

	flags_p fp[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_nbr},
		{"d", print_nbr},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"p", print_ptr},
		{"R", print_rot13},
		{"%", print_percent}
	};
	while (j < 14)
	{
		if (c == fp[j].c[0])
		{
			return (fp[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 * _printf - printf function based on format specifier
 * @format: format string
 *
 * Return: value of printed chars
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int sum = 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(arg, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = pick_func(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				sum++;
				i++;
			}
			else
			{
				sum += func(arg);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			sum++;
			i++;
		}
	}
	va_end(arg);
	return (sum);
}
