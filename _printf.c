#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>  // For LONG_MIN, LONG_MAX, etc.

/**
 * _putchar - Writes a character to the output buffer.
 * @c: Character to be printed.
 * Return: 1 on success.
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

    return 1;
}

/**
 * flash_buffer - Flushes the buffer to the output.
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
 * _printf - Custom printf function with format specifiers.
 * @format: Format string containing the specifiers.
 * Return: Total number of characters printed.
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                return -1;

            if (*format == 'l')  // Handling 'l' (long) modifier
            {
                if (*(format + 1) == 'd' || *(format + 1) == 'i')  // %ld or %li
                {
                    count += print_long_int(va_arg(args, long int));  // Implement print_long_int
                    format++;
                }
                else if (*(format + 1) == 'u')  // %lu
                {
                    count += print_unsigned_long(va_arg(args, unsigned long int));  // Implement print_unsigned_long
                    format++;
                }
                else if (*(format + 1) == 'o')  // %lo
                {
                    count += print_octal_long(va_arg(args, unsigned long int));  // Implement print_octal_long
                    format++;
                }
                else if (*(format + 1) == 'x')  // %lx
                {
                    count += print_hex_lower_long(va_arg(args, unsigned long int));  // Implement print_hex_lower_long
                    format++;
                }
                else if (*(format + 1) == 'X')  // %lX
                {
                    count += print_hex_upper_long(va_arg(args, unsigned long int));  // Implement print_hex_upper_long
                    format++;
                }
                else  // Invalid format after %l
                {
                    _putchar('%');
                    _putchar('l');
                    count += 2;
                }
            }
            else if (*format == 'h')  // Handling 'h' (short) modifier
            {
                if (*(format + 1) == 'd' || *(format + 1) == 'i')  // %hd or %hi
                {
                    count += print_short_int(va_arg(args, int));  // Implement print_short_int
                    format++;
                }
                else if (*(format + 1) == 'u')  // %hu
                {
                    count += print_unsigned_short(va_arg(args, unsigned int));  // Implement print_unsigned_short
                    format++;
                }
                else if (*(format + 1) == 'o')  // %ho
                {
                    count += print_octal_short(va_arg(args, unsigned int));  // Implement print_octal_short
                    format++;
                }
                else if (*(format + 1) == 'x')  // %hx
                {
                    count += print_hex_lower_short(va_arg(args, unsigned int));  // Implement print_hex_lower_short
                    format++;
                }
                else if (*(format + 1) == 'X')  // %hX
                {
                    count += print_hex_upper_short(va_arg(args, unsigned int));  // Implement print_hex_upper_short
                    format++;
                }
                else  // Invalid format after %h
                {
                    _putchar('%');
                    _putchar('h');
                    count += 2;
                }
            }
            else if (*format == 'd' || *format == 'i')  // Regular int
            {
                count += print_number(va_arg(args, int));  // Implement print_number for normal ints
            }
            else
            {
                // Handle other cases like %u, %x, %X, etc.
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

    return count;
}
