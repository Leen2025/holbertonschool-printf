#include "main.h"
/**
 * handle_octal - Handle octal format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_octal(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
int i = BUFFER_SIZE - 2;
unsigned long int num = va_arg(args, unsigned long int);
unsigned long int init_num = num;
/* Flush buffer before handling octal */
flush_buffer(buffer, buf_idx);
num = convert_size_unsigned(num, fmt->size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFFER_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if ((fmt->flags & F_HASH) && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsigned(fmt, i, buffer, buf_idx));
}
