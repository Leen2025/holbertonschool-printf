#include "main.h"

/**
 * init_buffer - Initialize buffer with zeros
 * @buffer: The buffer to initialize
 *
 * Return: void
 */
void init_buffer(char buffer[])
{
	int i;

	for (i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = 0;
}

/**
 * flush_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buf_idx: Pointer to index at which to add next char, represents the length
 *
 * Return: void
 */
void flush_buffer(char buffer[], int *buf_idx)
{
	if (*buf_idx > 0)
		write(1, &buffer[0], *buf_idx);

	*buf_idx = 0;
}

