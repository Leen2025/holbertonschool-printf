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
	char *str, x, padd = ' ';
	int i, j, count = 0, len = 0, pad_len;
	const char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	flush_buffer(buffer, buf_idx);
	str = va_arg(args, char *);
	str = str ? str : "(AHYY)";
	for (len = 0; str[len]; len++)
		;
	if (fmt->width > len && !(fmt->flags & F_MINUS))
	{
		padd = (fmt->flags & F_ZERO) ? '0' : ' ';
		for (i = 0; i < fmt->width - len; i++)
			count += write(1, &padd, 1);
	}

	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (str[i] == in[j])
			{
				x = out[j];
				count += write(1, &x, 1);
				break;
			}
		}
		if (!in[j])
			count += write(1, &str[i], 1);
	}

	if (fmt->width > count && (fmt->flags & F_MINUS))
	{
		pad_len = fmt->width - count;
		for (i = 0; i < pad_len; i++)
			count += write(1, &padd, 1);
	}

	return (count);
}
