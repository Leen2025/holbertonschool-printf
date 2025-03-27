#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int buffer_index = 0;
char output_buffer[1024];

/* دالة لكتابة الحرف إلى البافر */
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

/* دالة لتفريغ البافر عند نهاية _printf */
void flush_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }
}

/* تنفيذ printf */
int _printf(const char *format, ...)
{
    int plus_flag, space_flag, hash_flag;
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
            format++;  // تجاوز الـ %
            if (*format == '\0')
                return (-1);  // حالة خاصة عند نهاية النص

            plus_flag = space_flag = hash_flag = 0;

            // التحقق من العلامات الإضافية (+, ' ', #)
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

            // ✅ إصلاح حالة %% لتطبع % واحدة فقط
            if (*format == '%')
            {
                count += _putchar('%');
            }
            // ✅ إصلاح حالة % متبوعة بمسافة أو غير مكتملة
            else if (*format == ' ' || *format == '\0')
            {
                count += _putchar('%');
            }
            else if (*format == 'c')
                count += _putchar(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
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
                    count += _putchar('0');
                count += print_octal(num);
            }
            else if (*format == 'x')
            {
                unsigned int num = va_arg(args, unsigned int);
                if (hash_flag && num != 0)
                {
                    count += _putchar('0');
                    count += _putchar('x');
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
            else if (*format == 'S')
                count += print_S(va_arg(args, char *));
            else if (*format == 'p')
                count += print_pointer(va_arg(args, void *));
            else
            {
                count += _putchar('%');
                if (plus_flag)
                    count += _putchar('+');
                if (space_flag)
                    count += _putchar(' ');
                if (hash_flag)
                    count += _putchar('#');
                count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }
    flush_buffer();
    va_end(args);
    return (count);
}

