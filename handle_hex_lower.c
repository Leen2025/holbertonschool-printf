#include "main.h"
/**
 * handle_hex_lower - Handle lowercase hexadecimal format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_hex_lower(fmt_info_t *fmt, va_list args,
char buffer[], int *buf_idx)
{
/* Flush buffer before handling hex */
flush_buffer(buffer, buf_idx);
return (handle_hex(fmt, args, "0123456789abcdef", buffer, buf_idx));
}
