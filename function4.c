#include "main.h"

/**
 * print_hex_lower - Prints an unsigned integer in lowercase hexadecimal
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_hex_lower(unsigned int n)
{
	int count = 0;
	char hex_digits[] = "0123456789abcdef";

	if (n == 0)
		return (_putchar('0'));
	if (n / 16)
		count += print_hex_lower(n / 16);
	count += _putchar(hex_digits[n % 16]);
	return (count);
}

/**
 * print_hex_upper - Prints an unsigned integer in uppercase hexadecimal
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_hex_upper(unsigned int n)
{
	int count = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if (n == 0)
		return (_putchar('0'));
	if (n / 16)
		count += print_hex_upper(n / 16);
	count += _putchar(hex_digits[n % 16]);
	return (count);
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_octal(unsigned int n)
{
	int count = 0;

	if (n == 0)
		return (_putchar('0'));
	if (n / 8)
		count += print_octal(n / 8);
	count += _putchar((n % 8) + '0');
	return (count);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);
	count += _putchar((n % 10) + '0');
	return (count);
}
