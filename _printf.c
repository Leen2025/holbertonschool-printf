#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h> 

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

            if (*format == 'l')  
            {
                if (*(format + 1) == 'd' || *(format + 1) == 'i') 
                {
                    count += print_long_int(va_arg(args, long int)); 
                    format++;
                }
                else if (*(format + 1) == 'u')  
                {
                    count += print_unsigned_long(va_arg(args, unsigned long int)); 
                    format++;
                }
                else if (*(format + 1) == 'o')  
                {
                    count += print_octal_long(va_arg(args, unsigned long int)); 
                    format++;
                }
                else if (*(format + 1) == 'x') 
                {
                    count += print_hex_lower_long(va_arg(args, unsigned long int)); 
                    format++;
                }
                else if (*(format + 1) == 'X')
                {
                    count += print_hex_upper_long(va_arg(args, unsigned long int));  
                    format++;
                }
                else 
                {
                    _putchar('%');
                    _putchar('l');
                    count += 2;
                }
            }
            else if (*format == 'h') 
            {
                if (*(format + 1) == 'd' || *(format + 1) == 'i') 
                {
                    count += print_short_int(va_arg(args, int)); 
                    format++;
                }
                else if (*(format + 1) == 'u')  
                {
                    count += print_unsigned_short(va_arg(args, unsigned int));
                    format++;
                }
                else if (*(format + 1) == 'o')  
                {
                    count += print_octal_short(va_arg(args, unsigned int)); 
                    format++;
                }
                else if (*(format + 1) == 'x')  
                {
                    count += print_hex_lower_short(va_arg(args, unsigned int)); 
                    format++;
                }
                else if (*(format + 1) == 'X')  
                {
                    count += print_hex_upper_short(va_arg(args, unsigned int));  
                    format++;
                }
                else 
                {
                    _putchar('%');
                    _putchar('h');
                    count += 2;
                }
            }
            else if (*format == 'd' || *format == 'i')  
            {
                count += print_number(va_arg(args, int));  
            }
            else
            {
               
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
