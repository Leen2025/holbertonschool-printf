#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_number - prints an integer number
 * @num: the number to print
 * Return: the number of characters printed
 */
int print_number(int num)
{
    int count = 0;
    if (num < 0)
    {
        count += _putchar('-');
        num = -num;
    }

    if (num >= 10)
        count += print_number(num / 10);
    count += _putchar(num % 10 + '0');
    return count;
}

/**
 * _printf - custom printf function
 * @format: format string containing format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    const char *ptr = format;

    va_start(args, format);

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == '\0')
                return (-1);
            if (*ptr == '%')
                count += _putchar('%');
            else if (*ptr == 'd' || *ptr == 'i')
                count += print_number(va_arg(args, int));
            else if (*ptr == 'u')
                count += print_number(va_arg(args, unsigned int));
            else if (*ptr == 'o')
                count += print_number(va_arg(args, unsigned int));
            else if (*ptr == 'x')
                count += print_number(va_arg(args, unsigned int));
            else if (*ptr == 'X')
                count += print_number(va_arg(args, unsigned int));
            else if (*ptr == 'c')
                count += _putchar(va_arg(args, int));
            else if (*ptr == 's')
                count += _putchar(va_arg(args, char *));
            else if (*ptr == 'p')
            {
                unsigned long addr = (unsigned long)va_arg(args, void *);
                count += _putchar('0');
                count += _putchar('x');
                count += print_number(addr);  // You may need to convert the address correctly
            }
            else if (*ptr == 'r')
                count += _putchar('%');
            else
            {
                _putchar('%');
                _putchar(*ptr);
                count += 2;
            }
        }
        else
        {
            _putchar(*ptr);
            count++;
        }
        ptr++;
    }

    va_end(args);
    return count;
}
