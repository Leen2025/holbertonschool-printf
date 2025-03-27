#include "main.h"
#include <stdarg.h>
#include <unistd.h>
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
			if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == '%')
				count += _putchar('%');
			else if (*format == 'd' || *format == 'i')
				count += print_number(va_arg(args, int));
			else if  (*format == 'b')
                                count += print_binary(va_arg(args, unsigned int ));
			else if (*format == 'u')
                                count += print_unsigned(va_arg(args, unsigned int));
                        else if (*format == 'o')
                                count += print_octal(va_arg(args, unsigned int));
                        else if (*format == 'x')
                                count += print_hex_lower(va_arg(args, unsigned int));
                        else if (*format == 'X')
                                count += print_hex_upper(va_arg(args, unsigned int));
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
