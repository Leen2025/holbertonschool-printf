#include "main.h"
/**
 * handle_int - Handle integer format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed
 */
int handle_int(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	flush_buffer(buffer, buf_idx);

	n = convert_size_number(n, fmt->size);

	if (n == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(fmt, is_negative, i, buffer, buf_idx));
}

/**
 * handle_binary - Handle binary format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed
 */
int handle_binary(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
	unsigned int n, i, sum = 0, a[32];
	int count = 0, binary_len = 0, padding;
	char padd;

	flush_buffer(buffer, buf_idx);
	n = va_arg(args, unsigned int);
	for (i = 0; i < 32; i++)
		a[i] = (n >> (31 - i)) & 1;
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
			binary_len++;
	}
	padding = fmt->width - binary_len;
	padd = (fmt->flags & F_ZERO) ? '0' : ' ';

	if (padding > 0 && !(fmt->flags & F_MINUS))
		for (i = 0; i < (unsigned int)padding; i++)
			write(1, &padd, 1);
	for (i = 0, sum = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char c = '0' + a[i];

			write(1, &c, 1);
			count++;
		}
	}
	if (fmt->width > count && (fmt->flags & F_MINUS))
		for (i = 0; i < (unsigned int)(fmt->width - count); i++)
			write(1, " ", 1);
	return ((fmt->width > count) ? fmt->width : count);
}
