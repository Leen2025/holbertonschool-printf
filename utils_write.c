#include "main.h"

/**
 * write_char - Writes a character with formatting
 * @fmt: Pointer to format information structure
 * @c: Character to print
 * @buffer: Buffer array to handle print
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of chars printed
 */
int write_char(fmt_info_t *fmt, char c, char buffer[], int *buf_idx)
{
        int i = 0;
        char padd = ' ';

        (void)buf_idx; /* Unused parameter */

        if (fmt->flags & F_ZERO)
                padd = '0';

        buffer[i++] = c;
        buffer[i] = '\0';

        if (fmt->width > 1)
        {
                buffer[BUFFER_SIZE - 1] = '\0';
                for (i = 0; i < fmt->width - 1; i++)
                        buffer[BUFFER_SIZE - i - 2] = padd;

                if (fmt->flags & F_MINUS)
                        return (write(1, &buffer[0], 1) +
                                        write(1, &buffer[BUFFER_SIZE - i - 1], fmt->width - 1));
                else
                        return (write(1, &buffer[BUFFER_SIZE - i - 1], fmt->width - 1) +
                                        write(1, &buffer[0], 1));
        }

        return (write(1, &buffer[0], 1));
}

/**
 * write_number - Writes a number with formatting
 * @fmt: Pointer to format information structure
 * @is_negative: Indicates if the number is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of chars printed
 */
int write_number(fmt_info_t *fmt, int is_negative, int ind, char buffer[], int *buf_idx)
{
        int length = BUFFER_SIZE - ind - 1;
        char padd = ' ', extra_ch = 0;

        (void)buf_idx;

        if ((fmt->flags & F_ZERO) && !(fmt->flags & F_MINUS))
                padd = '0';
        if (is_negative)
                extra_ch = '-';
        else if (fmt->flags & F_PLUS)
                extra_ch = '+';
        else if (fmt->flags & F_SPACE)
                extra_ch = ' ';

        return (write_num(fmt, ind, buffer, length, padd, extra_ch));
}

/**
 * write_num - Write a number using a buffer
 * @fmt: Pointer to format information structure
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array
 * @length: Number length
 * @padd: Padding char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars
 */
int write_num(fmt_info_t *fmt, int ind, char buffer[], int length, char padd, char extra_c)
{
        int i, padd_start = 1;

        if (fmt->precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && fmt->width == 0)
                return (0); /* printf(".0d", 0) no char is printed */
        if (fmt->precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
                buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
        if (fmt->precision > 0 && fmt->precision < length)
                padd = ' ';
        while (fmt->precision > length)
                buffer[--ind] = '0', length++;
        if (extra_c != 0)
                length++;
        if (fmt->width > length)
        {
                for (i = 1; i < fmt->width - length + 1; i++)
                        buffer[i] = padd;
                buffer[i] = '\0';
                if (fmt->flags & F_MINUS && padd == ' ')/* Assign extra char to left of buffer */
                {
                        if (extra_c)
                                buffer[--ind] = extra_c;
                        return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
                }
                else if (!(fmt->flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
                {
                        if (extra_c)
                                buffer[--ind] = extra_c;
                        return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
                }
                else if (!(fmt->flags & F_MINUS) && padd == '0')/* extra char to left of padd */
                {
                        if (extra_c)
                                buffer[--padd_start] = extra_c;
                        return (write(1, &buffer[padd_start], i - padd_start) +
                                write(1, &buffer[ind], length - (1 - padd_start)));
                }
        }
        if (extra_c)
                buffer[--ind] = extra_c;
        return (write(1, &buffer[ind], length));
}

/**
 * write_unsigned - Writes an unsigned number with formatting
 * @fmt: Pointer to format information structure
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of chars printed
 */
int write_unsigned(fmt_info_t *fmt, int ind, char buffer[], int *buf_idx)
{
        int length = BUFFER_SIZE - ind - 1, i = 0;
        char padd = ' ';

        (void)buf_idx;

        if (fmt->precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
                return (0); /* printf(".0d", 0) no char is printed */

        if (fmt->precision > 0 && fmt->precision < length)
                padd = ' ';

        while (fmt->precision > length)
        {
                buffer[--ind] = '0';
                length++;
        }

        if ((fmt->flags & F_ZERO) && !(fmt->flags & F_MINUS))
                padd = '0';

        if (fmt->width > length)
        {
                for (i = 0; i < fmt->width - length; i++)
                        buffer[i] = padd;

                buffer[i] = '\0';

                if (fmt->flags & F_MINUS) /* Assign extra char to left of buffer [buffer>padd]*/
                {
                        return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
                }
                else /* Assign extra char to left of padding [padd>buffer]*/
                {
                        return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
                }
        }

        return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @fmt: Pointer to format information structure
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of written chars
 */
int write_pointer(fmt_info_t *fmt, char buffer[], int ind, int length, int *buf_idx)
{
        int i;
        char padd = ' ';
        char extra_c = 0;
        int padd_start = 1;

        (void)buf_idx;

        if (fmt->width > length)
        {
                for (i = 3; i < fmt->width - length + 3; i++)
                        buffer[i] = padd;
                buffer[i] = '\0';
                if (fmt->flags & F_MINUS && padd == ' ')/* Assign extra char to left of buffer */
                {
                        buffer[--ind] = 'x';
                        buffer[--ind] = '0';
                        if (extra_c)
                                buffer[--ind] = extra_c;
                        return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
                }
                else if (!(fmt->flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
                {
                        buffer[--ind] = 'x';
                        buffer[--ind] = '0';
                        if (extra_c)
                                buffer[--ind] = extra_c;
                        return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
                }
                else if (!(fmt->flags & F_MINUS) && padd == '0')/* extra char to left of padd */
                {
                        if (extra_c)
                                buffer[--padd_start] = extra_c;
                        buffer[1] = '0';
                        buffer[2] = 'x';
                        return (write(1, &buffer[padd_start], i - padd_start) +
                                write(1, &buffer[ind], length - (1 - padd_start) - 2));
                }
        }
        buffer[--ind] = 'x';
        buffer[--ind] = '0';
        if (extra_c)
                buffer[--ind] = extra_c;
        return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}

