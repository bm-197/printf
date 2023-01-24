#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_unsigned_number - print unsigned number
 * @num: unsigned int to print
 * Return: number of printed chars
 */

int print_unsigned_number(unsigned int num)
{
	int count = 0;
	unsigned int number = num;

	if (number <= 9)
	{
		_putchar(number + '0');
		return (1);
	}
	if (number > 9)
	{
		count = print_unsigned_number(number / 10) + 1;
		_putchar(number % 10 + '0');
		return (count);
	}
	return (0);
}

/**
 * print_number - display the number contained in an int
 * @num: int to print
 * Return: number of char
 */
int print_number(int num)
{
	unsigned int number;
	int count = 0;

	number = num;
	if (number < 0)
	{
		_putchar('-');
		count++;
		number = -number;
	}
	if (number <= 9)
	{
		count += _putchar(number + '0');
		return (count);
	}
	if (number > 9)
	{
		count += print_number(number / 10) + 1;
		_putchar(number % 10 + '0');
		return (count);
	}
	return (0);
}
/**
 * _nbr_len - length of a number
 * @primeNumber: number
 * Return: length of the number
 */

int _nbr_len(int primeNumber)
{
	int cLoop = 0, number;

	if (primeNumber == 0)
		return (1);

	number = primeNumber;

	if (number < 0)
	{
		number *= -1;
		cLoop++;	/* for the sign char */
	}

	while (number)
	{
		number /= 10;
		cLoop++;
	}

	return (cLoop);
}

/**
 * _itoa - Convert an int to a string
 * @prmNumber: int to convert
 * Return: converted string
 */

char *_itoa(int primeNumber)
{
	char *s;
	int cLoop;
	long number;

	number = primeNumber;
	cLoop = _nbr_len(number);
	s = malloc(sizeof(char) * cLoop + 1);

	if (s == NULL)
	{
		return (NULL);
	}

	s[cLoop] = '\0';

	if (number == 0)
	{
		s = "0";
	}
	else if (number < 0)
	{
		s[0] = '-';
		number *= -1;
	}

	while (number)
	{
		s[--cLoop] = number % 10 + 48;
		number /= 10;
	}

	return (s);
}
