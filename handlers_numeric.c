/**
 * handlers_numeric.c - Numeric format handlers
 *
 * This file contains handler functions for basic numeric
 * format specifiers (d, i, b).
 */

#include "main.h"

/**
 * handle_int - Handle integer format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_int(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
        int i = BUFFER_SIZE - 2;
        int is_negative = 0;
        long int n = va_arg(args, long int);
        unsigned long int num;

        /* Flush buffer before handling integer */
        flush_buffer(buffer, buf_idx);

        n = convert_size_number(n, fmt->size);

        if (n == 0)
                buffer[i--] = '0';

        buffer[BUFFER_SIZE - 1] = '\0';
        num = (unsigned long int)n;

        if (n < 0)
        {
                num = (unsigned long int)((-1) * n);
                is_negative = 1;
        }

        while (num > 0)
        {
                buffer[i--] = (num % 10) + '0';
                num /= 10;
        }

        i++;

        return (write_number(fmt, is_negative, i, buffer, buf_idx));
}

/**
 * handle_binary - Handle binary format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_binary(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
        unsigned int n, m, i, sum;
        unsigned int a[32];
        int count;

        /* Flush buffer before handling binary */
        flush_buffer(buffer, buf_idx);

        n = va_arg(args, unsigned int);
        m = 2147483648; /* (2 ^ 31) */
        a[0] = n / m;
        for (i = 1; i < 32; i++)
        {
                m /= 2;
                a[i] = (n / m) % 2;
        }

        /* Handle width formatting if specified */
        if (fmt->width > 0)
        {
                int binary_len = 0;

                /* Calculate binary length */
                for (i = 0, sum = 0; i < 32; i++)
                {
                        sum += a[i];
                        if (sum || i == 31)
                                binary_len++;
                }

                /* Apply padding if width is greater than binary length */
                if (fmt->width > binary_len)
                {
                        char padd = (fmt->flags & F_ZERO) ? '0' : ' ';
                        int padding = fmt->width - binary_len;
                        unsigned int j;

                        if (!(fmt->flags & F_MINUS))
                        {
                                /* Right-aligned: padding first */
                                for (j = 0; j < (unsigned int)padding; j++)
                                        write(1, &padd, 1);
                        }

                        /* Print binary number */
                        for (i = 0, sum = 0, count = 0; i < 32; i++)
                        {
                                sum += a[i];
                                if (sum || i == 31)
                                {
                                        char z = '0' + a[i];
                                        write(1, &z, 1);
                                        count++;
                                }
                        }

                        if (fmt->flags & F_MINUS)
                        {
                                /* Left-aligned: padding after */
                                for (j = 0; j < (unsigned int)padding; j++)
                                        write(1, &padd, 1);
                        }

                        return (fmt->width);
                }
        }

        /* No width formatting or width <= binary length */
        for (i = 0, sum = 0, count = 0; i < 32; i++)
        {
                sum += a[i];
                if (sum || i == 31)
                {
                        char z = '0' + a[i];
                        write(1, &z, 1);
                        count++;
                }
        }

        return (count);
}

