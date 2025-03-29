/**
 * handlers_char.c - Character and string format handlers
 *
 * This file contains handler functions for character and string
 * format specifiers (c, s, %).
 */

#include "main.h"

/**
 * handle_char - Handle character format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_char(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
        char c = va_arg(args, int);

        /* Flush buffer before handling char with width formatting */
        if (fmt->width > 1)
                flush_buffer(buffer, buf_idx);

        return (write_char(fmt, c, buffer, buf_idx));
}

/**
 * handle_string - Handle string format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_string(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
        int length = 0, i;
        char *str = va_arg(args, char *);

        /* Flush buffer before handling string */
        flush_buffer(buffer, buf_idx);

        if (str == NULL)
        {
                str = "(null)";
                if (fmt->precision >= 6)
                        str = "      ";
        }

        while (str[length] != '\0')
                length++;

        if (fmt->precision >= 0 && fmt->precision < length)
                length = fmt->precision;

        if (fmt->width > length)
        {
                if (fmt->flags & F_MINUS)
                {
                        write(1, &str[0], length);
                        for (i = fmt->width - length; i > 0; i--)
                                write(1, " ", 1);
                        return (fmt->width);
                }
                else
                {
                        for (i = fmt->width - length; i > 0; i--)
                                write(1, " ", 1);
                        write(1, &str[0], length);
                        return (fmt->width);
                }
        }

        return (write(1, str, length));
}

/**
 * handle_percent - Handle percent format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_percent(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
        /* Flush buffer before handling percent sign */
        flush_buffer(buffer, buf_idx);

        (void)fmt;
        (void)args;

        /* Handle width formatting if specified */
        if (fmt->width > 1)
        {
                int i;
                char padd = (fmt->flags & F_ZERO) ? '0' : ' ';

                if (fmt->flags & F_MINUS)
                {
                        write(1, "%", 1);
                        for (i = fmt->width - 1; i > 0; i--)
                                write(1, &padd, 1);
                        return (fmt->width);
                }
                else
                {
                        for (i = fmt->width - 1; i > 0; i--)
                                write(1, &padd, 1);
                        write(1, "%", 1);
                        return (fmt->width);
                }
        }

        return (write(1, "%", 1));
}

