#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _putchar - writes character to stdout
 * @c: The character
 *
 * Return: number of printed char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - write all char from string to stdout
 * @str: string to print
 * @ascii: enable ascii restriction
 * Return: number of printed char
 */

int _puts(char *str, int ascii)
{
	char *s;
	int i = 0, sum = 0;

	while (str[i])
	{
		if (((str[i] >= 0 && str[i] < 32) || str[i] >= 127) && ascii)
		{
			s = convert_base(str[i], 16, 1);
			sum += write(1, "\\x", 2);
			if (str[i] >= 0 && str[i] < 16)
				sum += _putchar('0');
			sum += _puts(s, 0);
			free(s);
			i++;
		}
		else
		{
			sum += _putchar(str[i]);
			i++;
		}
	}
	return (sum);
}

/**
 * _strlen_recursion - return the length of a string
 *
 * @str: char pointer
 *
 * Return: the length of a string
 */
int _strlen_recursion(char *str)
{
	if (*str != '\0')
	{
		return (_strlen_recursion(str + 1) + 1);
	}
	else
	{
		return (0);
	}
}

/**
 * _strdup - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @string: char pointer to copy
 *
 * Return: a new char pointer
 */
char *_strdup(char *string)
{
	char *str;
	int cLp;

	if (string == NULL)
	{
		return (NULL);
	}

	str = malloc(sizeof(char) * (_strlen_recursion(string) + 1));

	if (str == NULL)
	{
		return (NULL);
	}

	for (cLp = 0; cLp < _strlen_recursion(string) + 1; cLp++)
	{
		str[cLp] = string[cLp];
	}

	return (str);
}
