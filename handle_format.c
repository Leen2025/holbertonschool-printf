#include "main.h"

/**
 * handle_format - Selects the appropriate handler for a format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed, or -1 on error
 */
int handle_format(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
	fmt_handler_t handlers[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'%', handle_percent},
		{'i', handle_int},
		{'d', handle_int},
		{'b', handle_binary},
		{'u', handle_unsigned},
		{'o', handle_octal},
		{'x', handle_hex_lower},
		{'X', handle_hex_upper},
		{'p', handle_pointer},
		{'S', handle_nonprint},
		{'r', handle_reverse},
		{'R', handle_rot13},
		{0, NULL}
	};
	int i;

	for (i = 0; handlers[i].specifier != 0; i++)
	{
		if (fmt->specifier == handlers[i].specifier)
			return (handlers[i].handler(fmt, args, buffer, buf_idx));
	}

	return (handle_unknown(fmt, buffer, buf_idx));
}
/**
 * handle_unknown - Handle unknown format specifier
 * @fmt: Pointer to format information structure
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed
 */
int handle_unknown(fmt_info_t *fmt, char buffer[], int *buf_idx)
{
	int chars_printed = 0;

	(void)buffer;/* Unused parameter */
	(void)buf_idx;/* Unused parameter */

	if (fmt->specifier == '\0')
		return (-1);

	chars_printed += write(1, "%", 1);

	if (fmt->flags & F_SPACE)
		chars_printed += write(1, " ", 1);

	chars_printed += write(1, &fmt->specifier, 1);

	return (chars_printed);
}
