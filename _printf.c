#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int buffer_index = 0;
char output_buffer[1024];

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

void flash_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }
}

int _printf(const char *format, ...)
{
    int count = 0;
    buffer_index = 0;
    va_list args;

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

            if (*format == ' ')
            {
                format++;
                continue;
            }

            if (*format == '%')
            {
                count += _putchar('%');
                format++;
                continue;
            }

            if (*format == 'c')
                count += _putchar(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                count += print_number(num);
            }
            else if (*format == 'b')
                count += print_binary(va_arg(args, unsigned int));
            else if (*format == 'u')
                count += print_unsigned(va_arg(args, unsigned int));
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_octal(num);
            }
            else if (*format == 'x')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_hex_lower(num);
            }
            else if (*format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_hex_upper(num);
            }
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
