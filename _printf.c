#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* Global buffer for storing output */
int buffer_index = 0;
char output_buffer[1024];

/**
 * _putchar - Writes a character to the output buffer.
 * @c: Character to be printed.
 * Return: 1 on success.
 */
int _putchar(char c)
{
    output_buffer[buffer_index++] = c;

    if (buffer_index == 1024)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }

    return (1);
}

/**
 * flash_buffer - Flushes the buffer to the output.
 */
void flash_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }
}

/**
 * print_string - Prints a string to the output.
 * @str: String to be printed.
 * Return: Number of characters printed.
 */
int print_string(char *str)
{
    int count = 0;

    if (str == NULL)
    {
        str = "(null)";
    }

    while (*str)
    {
        _putchar(*str++);
        count++;
    }

    return (count);
}

/**
 * print_number - Prints an integer to the output.
 * @num: Integer to be printed.
 * Return: Number of characters printed.
 */
int print_number(int num)
{
    int count = 0;

    if (num < 0)
    {
        _putchar('-');
        num = -num;
        count++;
    }

    if (num >= 10)
    {
        count += print_number(num / 10);
    }

    _putchar(num % 10 + '0');
    count++;

    return (count);
}

/**
 * print_unsigned - Prints an unsigned integer to the output.
 * @num: Unsigned integer to be printed.
 * Return: Number of characters printed.
 */
int print_unsigned(unsigned int num)
{
    int count = 0;

    if (num >= 10)
    {
        count += print_unsigned(num / 10);
    }

    _putchar(num % 10 + '0');
    count++;

    return (count);
}

/**
 * print_hex_lower - Prints a hexadecimal number in lowercase.
 * @num: Unsigned integer to be printed in hexadecimal.
 * Return: Number of characters printed.
 */
int print_hex_lower(unsigned int num)
{
    int count = 0;

    if (num >= 16)
    {
        count += print_hex_lower(num / 16);
    }

    num = num % 16;
    if (num < 10)
    {
        _putchar(num + '0');
    }
    else
    {
        _putchar(num - 10 + 'a');
    }

    count++;

    return (count);
}

/**
 * print_hex_upper - Prints a hexadecimal number in uppercase.
 * @num: Unsigned integer to be printed in hexadecimal.
 * Return: Number of characters printed.
 */
int print_hex_upper(unsigned int num)
{
    int count = 0;

    if (num >= 16)
    {
        count += print_hex_upper(num / 16);
    }

    num = num % 16;
    if (num < 10)
    {
        _putchar(num + '0');
    }
    else
    {
        _putchar(num - 10 + 'A');
    }

    count++;

    return (count);
}

/**
 * print_pointer - Prints a pointer in hexadecimal format.
 * @ptr: Pointer to be printed.
 * Return: Number of characters printed.
 */
int print_pointer(void *ptr)
{
    unsigned long address = (unsigned long)ptr;
    int count = 0;

    count += _putchar('0');
    count += _putchar('x');
    count += print_hex_lower(address);

    return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing format specifiers.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    int plus_flag, space_flag, hash_flag;

    if (!format || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                return (-1);

            /* Flags Handling */
            plus_flag = 0;
            space_flag = 0;
            hash_flag = 0;
            while (*format == '+' || *format == ' ' || *format == '#')
            {
                if (*format == '+')
                    plus_flag = 1;
                else if (*format == ' ')
                    space_flag = 1;
                else if (*format == '#')
                    hash_flag = 1;
                format++;
            }

            /* Handle format specifiers */
            if (*format == 'c')
                count += _putchar(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
            else if (*format == '%')
                count += _putchar('%');
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                if (num >= 0)
                {
                    if (plus_flag)
                        count += _putchar('+');
                    else if (space_flag)
                        count += _putchar(' ');
                }
                count += print_number(num);
            }
            else if (*format == 'u')
                count += print_unsigned(va_arg(args, unsigned int));
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                if (hash_flag && num != 0)
                {
                    count += _putchar('0');
                    count += _putchar('o');
                }
                count += print_hex_lower(num);
            }
            else if (*format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                if (hash_flag && num != 0)
                {
                    count += _putchar('0');
                    count += _putchar('X');
                }
                count += print_hex_upper(num);
            }
            else if (*format == 'p')
                count += print_pointer(va_arg(args, void *));
            else
            {
                _putchar('%');
                _putchar(*format);
                count += 2;
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    flash_buffer();
    va_end(args);

    return (count);
}
