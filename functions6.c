#include "main.h"
/**
 * print_pointer - Prints a pointer address
 * @ptr: Pointer to print
 * Return: Number of characters printed
 */
int print_pointer(void *ptr)
{
    int count = 0;
    unsigned long int address;

    if (ptr == NULL)
        return (print_string("(nil)"));

    /* Cast the pointer to an unsigned long int to get its address */
    address = (unsigned long int)ptr;

    /* Print the "0x" prefix */
    count += _putchar('0');
    count += _putchar('x');

    /* Print the address in lowercase hexadecimal */
    count += print_hex_long(address);

    return (count);
}

int print_hex_long(unsigned long int n)
{
    int count = 0;
    int started = 0;
    int i;
    unsigned long int temp;
    char hex_digits[] = "0123456789abcdef";

    /* For a value of 0, just print '0' */
    if (n == 0)
        return (_putchar('0'));

    /* Calculate how many hex digits we need (up to 16 for 64-bit) */
    for (i = 15; i >= 0; i--)
    {
        temp = (n >> (i * 4)) & 0xF;

        /* Skip leading zeros */
        if (temp == 0 && !started)
            continue;

        started = 1;
        count += _putchar(hex_digits[temp]);
    }

    return (count);
}
