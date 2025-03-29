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
	char *str, x, in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	unsigned int i, j, count = 0, str_len = 0;
	int width;

	flush_buffer(buffer, buf_idx);
	str = va_arg(args, char *);
	if (!str)
		str = "(AHYY)";

	while (str[str_len])
		str_len++;

	width = fmt->width;
	if (width > (int)str_len && !(fmt->flags & F_MINUS))
		for (j = 0; j < (unsigned int)(width - str_len); j++)
			write(1, (fmt->flags & F_ZERO) ? "0" : " ", 1);

	for (i = 0; str[i]; i++)
	{
		x = str[i];
		for (j = 0; in[j]; j++)
			if (in[j] == str[i])
			{
				x = out[j];
				break;
			}
		write(1, &x, 1);
		count++;
	}

	if (width > (int)count && (fmt->flags & F_MINUS))
		for (j = 0; j < (unsigned int)(width - count); j++)
			write(1, " ", 1);

	return (width > count ? width : (int)count);
}

