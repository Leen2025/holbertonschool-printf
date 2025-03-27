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
    {
        return (print_string("(nil)"));
    }

    address = (unsigned long int)ptr;
    count += _putchar('0');
    count += _putchar('x');
    count += print_hex_lower(address);
    return (count);
}

/**
 * print_hex_lower - Helper function to print a number in hexadecimal format
 * @num: The number to print
 * Return: Number of characters printed
 */
int print_hex_lower(unsigned long int num)
{
    int count = 0;
    char hex_chars[] = "0123456789abcdef";

    if (num / 16)
        count += print_hex_lower(num / 16);  // Recursively break down the number
    count += _putchar(hex_chars[num % 16]);  // Print the current hex digit

    return (count);
}
