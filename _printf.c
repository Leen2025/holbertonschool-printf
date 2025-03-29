#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string to stdout
 * @str: The string to print
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * _printf - Produces output according to a format string
 * @format: The format string containing directives
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	if (!format)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
