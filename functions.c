#include "main.h"

/**
* _putchar - Writes a character to stdout
* @c: Character to print
* Return: 1 on success
*/

/**
* print_string - Prints a string
* @str: String to print
* Return: Number of characters printed
*/
int print_string(char *str)
{
	int count = 0;
	if (!str)
		str = "(null)";
	while (*str)
		count += _putchar(*str++);
	return (count);
}
/**
* print_number - Prints an integer
* @n: Integer to print
* Return: Number of characters printed
*/
int print_number(int n)
{
	int count = 0;
	unsigned int num;
	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		count += print_number(num / 10);
	count += _putchar(num % 10 + '0');
	return (count);
}
int print_long_int(long int num)
{
    int count = 0;
    char buffer[20];  
    int i = 0;
    int is_negative = 0;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0'; 
        num = num / 10;
    }

    if (is_negative)
    {
        _putchar('-');
        count++;
    }

   
    while (i-- > 0)
    {
        _putchar(buffer[i]);
        count++;
    }

    return (count);
}
