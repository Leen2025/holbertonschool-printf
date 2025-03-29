#include "main.h"
/**
 * handle_pointer - Handle pointer format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 * Return: Number of characters printed
 */
int handle_pointer(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
	int ind = BUFFER_SIZE - 2, length = 2;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	flush_buffer(buffer, buf_idx);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	ind++;
	return (write_pointer(fmt, buffer, ind, length, buf_idx));
}
