#include "main.h"

/**
 * _printf - produce output according to a format
 * @format: the format
 *
 * Return: 1 if successful
 */
int _printf(const char *format, ...)
{
	va_list arg;

	va_start(arg, format);

	char a = 'a', A = 'A', len = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(arg, int));
					break;
				case 's':
					print_string(va_arg(arg, char *));
					break;
				case 'i':
					print_number(va_arg(arg, int));
					break;
				case 'd':
					print_number(va_arg(arg, int));
					break;
				case '%':
					_putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*format);
					break;
				}
		}
		else
			_putchar(*format);
		format++, len += 1;
	}
	va_end(arg);
	return (len);
}
