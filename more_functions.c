#include "main.h"
/**
 * print_binary - Prints an unsigned integer in binary format
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;
    /* Handle the case of 0 separately */
    if (n == 0)
        return (_putchar('0'));
    /* Recursive call to print the binary representation */
    if (n / 2)
        count += print_binary(n / 2);
    /* Print the current bit (0 or 1) */
    count += _putchar((n % 2) + '0');
    return (count);
}

