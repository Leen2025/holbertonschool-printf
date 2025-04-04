#include "main.h"
/**
 * handle_nonprint - Handle non-printable character format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed
 */
int handle_nonprint(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	(void)fmt;
	flush_buffer(buffer, buf_idx);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/**
 * handle_reverse - Handle reverse string format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed
 */
int handle_reverse(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
	char *str;
	int i, count = 0;
	int j, k;

	flush_buffer(buffer, buf_idx);
	str = va_arg(args, char *);
	if (str == NULL)
		str = ")Null(";
	for (i = 0; str[i]; i++)
	if (fmt->width > i && !(fmt->flags & F_MINUS))
	{
		char padd = (fmt->flags & F_ZERO) ? '0' : ' ';
		int padding = fmt->width - i;

		for (j = 0; j < padding; j++)
			write(1, &padd, 1);
	}
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	if (fmt->width > count && (fmt->flags & F_MINUS))
	{
		char padd = ' ';
		int padding = fmt->width - count;

		for (k = 0; k < padding; k++)
			write(1, &padd, 1);
		return (fmt->width);
	}
	return (count);
}
