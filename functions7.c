#include "main.h"
/**
* print_string - Prints a string
* @str: String to print
* Return: Number of characters printed
*/
int print_S(char *str)
{
	int count = 0;
	if (!str)
	return (print_string("(null)"));
	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			if (*str < 16)
				count += _putchar('0');
			count += print_hex_upper((unsigned char)*str);
		}
		else
		{
			count += _putchar(*str);
		}
		str++;
	}
	return (count);
}
