#include "main.h"
/**
 * handle_hex_upper - Handle uppercase hexadecimal format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_hex_upper(fmt_info_t *fmt, va_list args,
char buffer[], int *buf_idx)
{
/* Flush buffer before handling hex */
flush_buffer(buffer, buf_idx);
return (handle_hex(fmt, args, "0123456789ABCDEF", buffer, buf_idx));
}
