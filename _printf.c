#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
* _putchar - Writes a character to stdout
* @c: Character to print
* Return: 1 on success
*/
int _putchar(char c)
{
    static int buffer_index = 0;
    static char output_buffer[1024];

    output_buffer[buffer_index++] = c;
    if (buffer_index == 1024)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }
    return (1);
}

/**
* flash_buffer - Flushes the buffer content to stdout
*/
void flash_buffer(void)
{
    static int buffer_index = 0;
    static char output_buffer[1024];

    if (buffer_index > 0)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }
}

/**
* print_string - Prints a string
* @str: String to print
* Return: Number of characters printed
*/
int print_string(char *str)
{
    int count = 0;
    if (!str)
        str = "(null)";
    while (*str)
        count += _putchar(*str++);
    return (count);
}

/**
* print_number - Prints an integer
* @n: Integer to print
* Return: Number of characters printed
*/
int print_number(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
        num = n;
    if (num / 10)
        count += print_number(num / 10);
    count += _putchar(num % 10 + '0');
    return (count);
}

/**
* handle_flags - Handles flag processing for the specifiers
* @format: Format string to process flags
* @args: Argument list
* Return: Number of characters printed
*/
int handle_flags(const char **format, va_list args)
{
    int count = 0;
    int has_plus = 0, has_space = 0, has_hash = 0;

    
    while (**format == '+' || **format == ' ' || **format == '#')
    {
        if (**format == '+')
            has_plus = 1;
        if (**format == ' ')
            has_space = 1;
        if (**format == '#')
            has_hash = 1;
        (*format)++;
    }

    
    if (**format == 'd' || **format == 'i')
    {
        int num = va_arg(args, int);
        if (has_plus)
            count += _putchar(num >= 0 ? '+' : '-');
        else if (has_space && num >= 0)
            count += _putchar(' ');
        count += print_number(num);
    }
    else if (**format == 'x')
    {
        unsigned int num = va_arg(args, unsigned int);
        if (has_hash)
            count += _putchar('0') + _putchar('x');
        count += print_hex_lower(num);
    }
    else if (**format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        if (has_hash)
            count += _putchar('0') + _putchar('X');
        count += print_hex_upper(num);
    }
    else if (**format == 'o')
    {
        unsigned int num = va_arg(args, unsigned int);
        if (has_hash)
            count += _putchar('0');
        count += print_octal(num);
    }

    return count;
}

/**
* _printf - Produces output according to a format
* @format: Format string containing format specifiers
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    buffer_index = 0;

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

            
            count += handle_flags(&format, args);

            
            if (*format == 'c')
                count += _putchar(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
            else if (*format == '%')
                count += _putchar('%');
            else if (*format == 'b')
                count += print_binary(va_arg(args, unsigned int));
            else if (*format == 'u')
                count += print_unsigned(va_arg(args, unsigned int));
            else if (*format == 'S')
                count += print_S(va_arg(args, char *));
            else if (*format == 'p')
                count += print_pointer(va_arg(args, void *));
            else
            {
                count += _putchar('%');
                count += _putchar(*format);
            }
        }
        else
            count += _putchar(*format);
        format++;
    }

    flash_buffer();
    va_end(args);
    return (count);
}
