#include "main.h"
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * handle_length_modifier - Handles length modifiers for format specifiers.
 * @format: The format string.
 * @args: The argument list.
 * @specifier: The format specifier (e.g., 'd', 'i', 'u').
 * Return: The number of characters printed.
 */
int handle_length_modifier(const char *format, va_list args, char specifier)
{
    int count = 0;

    if (*format == 'l')
    {
        format++;
        if (specifier == 'd' || specifier == 'i')
        {
            count += print_long_number(va_arg(args, long)); 
        }
        else if (specifier == 'u')
        {
            count += print_unsigned_long(va_arg(args, unsigned long));  
        }
        else if (specifier == 'o')
        {
            count += print_octal_long(va_arg(args, unsigned long));  
        }
        else if (specifier == 'x')
        {
            count += print_hex_lower_long(va_arg(args, unsigned long)); 
        }
        else if (specifier == 'X')
        {
            count += print_hex_upper_long(va_arg(args, unsigned long)); 
        }
    }
    else if (*format == 'h')  
    {
        format++;
        if (specifier == 'd' || specifier == 'i')
        {
            count += print_short_number((short)va_arg(args, int)); 
        }
        else if (specifier == 'u')
        {
            count += print_unsigned_short((short)va_arg(args, int));  
        }
        else if (specifier == 'o')
        {
            count += print_octal_short((short)va_arg(args, int)); 
        }
        else if (specifier == 'x')
        {
            count += print_hex_lower_short((short)va_arg(args, int)); 
        }
        else if (specifier == 'X')
        {
            count += print_hex_upper_short((short)va_arg(args, int));  
        }
    }
    else 
    {
        if (specifier == 'd' || specifier == 'i')
        {
            count += print_number(va_arg(args, int));  
        }
        else if (specifier == 'u')
        {
            count += print_unsigned(va_arg(args, unsigned int));  
        }
        else if (specifier == 'o')
        {
            count += print_octal(va_arg(args, unsigned int)); 
        }
        else if (specifier == 'x')
        {
            count += print_hex_lower(va_arg(args, unsigned int));  
        }
        else if (specifier == 'X')
        {
            count += print_hex_upper(va_arg(args, unsigned int));  
        }
    }

    return count;
}
