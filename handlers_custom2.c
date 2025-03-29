#include "main.h"
/**
 * handle_rot13 - Handle ROT13 string format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed
 */
int handle_rot13(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
	char x, *str, in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	unsigned int i, j, count = 0, str_len = 0;

	flush_buffer(buffer, buf_idx);
	str = va_arg(args, char *);
	if (!str)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
		str_len++;
	if (fmt->width > str_len && !(fmt->flags & F_MINUS))
		for (j = 0; j < fmt->width - str_len; j++)
			write(1, (fmt->flags & F_ZERO) ? "0" : " ", 1);
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1), count++;
				break;
			}
		if (!in[j])
			write(1, &str[i], 1), count++;
	}
	if (fmt->width > count && (fmt->flags & F_MINUS))
		for (j = 0; j < fmt->width - count; j++)
			write(1, " ", 1);
	return ((fmt->width > count) ? fmt->width : count);
}

