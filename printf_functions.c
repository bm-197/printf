#include "main.h"

/**
 * print_number - print integer numbers
 * @n: the integer to be printed
 *
 * Return: nothing
 */

int print_number(int n)
{
	int i = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if ((n / 10) != 0)
	{
		print_number(n / 10);
		i++;
	}
	_putchar(n % 10 + '0');
	return (i);
}

/**
 * print_unsigned_int - print only positive numbers
 * @n: the positive number
 *
 * Return: nothing
 */

int print_unsigned_int(unsigned int n)
{
	int i = 0;

	if ((n / 10) != 0)
		print_unsigned_int(n / 10);

	_putchar(n % 10 + '0');
	return (i);
}

/**
 * print_string - print string without
 * the new line character
 * @s: the string
 *
 * Return: nothing
 */

int print_string(char *s)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * _strlen(s) + 1);

	if (str == NULL)
		return (0);

	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';

	_puts(str);

	free(str);
	return (i);
}
