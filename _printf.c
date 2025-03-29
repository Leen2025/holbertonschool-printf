#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - Writes a character to the buffer
 * @c: The character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
	int buffer_index = 0;
	char output_buffer[1024];

	output_buffer[buffer_index++] = c;
	if (buffer_index == 1024)
	{
		write(1, output_buffer, buffer_index);
		buffer_index = 0;
	}
	return (1);
}

/**
 * flash_buffer - Flushes the buffer to stdout
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

			if (*format == 'l' || *format == 'h')
			{
				count += handle_length_modifier(format, args, *(format + 1));
			}
			else if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == '%')
				count += _putchar('%');
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
