#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int buffer_index = 0;
char output_buffer[1024];

/**
 * _putchar - Writes a character to buffer
 * @c: The character to print
 * Return: 1 (success)
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
 * flush_buffer - Writes the contents of the buffer to stdout
 */
void flush_buffer(void)
{
	if (buffer_index > 0)
	{
		write(1, output_buffer, buffer_index);
		buffer_index = 0;
	}
}

/**
 * _printf - Produces output according to a format
 * @format: Format string containing format specifiers
 * Return: Number of characters printed
 */
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
			format++;
			if (*format == '\0')
				return (-1);
			plus_flag = space_flag = hash_flag = 0;
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
			if (*format == '%')
				count += _putchar('%');
			else if (*format == ' ' || *format == '\0')
				count += _putchar('%');
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
			count += _putchar(*format);
		format++;
	}
	flush_buffer();
	va_end(args);
	return (count);
}

