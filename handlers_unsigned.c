#include "main.h"
/**
 * handle_unsigned - Handle unsigned integer format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_unsigned(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
int i = BUFFER_SIZE - 2;
unsigned long int num = va_arg(args, unsigned long int);
/* Flush buffer before handling unsigned integer */
flush_buffer(buffer, buf_idx);
num = convert_size_unsigned(num, fmt->size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFFER_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsigned(fmt, i, buffer, buf_idx));
}
