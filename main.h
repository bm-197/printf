#ifndef _PRINTF_
#define _PRINTF_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int _strlen(char *str);
int print_number(int n);
void str_reverse(char *c);
void print_hexadecimal(unsigned int n, char flag);
int print_string(char *str);
int print_unsigned_int(unsigned int n);
void print_octal(unsigned int num);
char *convert_base(unsigned long nb, unsigned int base, int upper);
int convert_alpha_numeric(int nb, int upper);

#endif
