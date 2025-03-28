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

/**
 * handle_hex_lower - Handle lowercase hexadecimal format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_hex_lower(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
        /* Flush buffer before handling hex */
        flush_buffer(buffer, buf_idx);
        
        return (handle_hex(fmt, args, "0123456789abcdef", buffer, buf_idx));
}

/**
 * handle_hex_upper - Handle uppercase hexadecimal format specifier
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_hex_upper(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx)
{
        /* Flush buffer before handling hex */
        flush_buffer(buffer, buf_idx);
        
        return (handle_hex(fmt, args, "0123456789ABCDEF", buffer, buf_idx));
}

/**
 * handle_hex - Handle hexadecimal format specifier (helper function)
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 * @map_to: Character mapping for hex digits
 * @buffer: Output buffer
 * @buf_idx: Pointer to buffer index
 *
 * Return: Number of characters printed
 */
int handle_hex(fmt_info_t *fmt, va_list args, char map_to[], char buffer[], int *buf_idx)
{
        int i = BUFFER_SIZE - 2;
        unsigned long int num = va_arg(args, unsigned long int);
        unsigned long int init_num = num;
        char flag_ch = (fmt->specifier == 'x') ? 'x' : 'X';

        num = convert_size_unsigned(num, fmt->size);

        if (num == 0)
                buffer[i--] = '0';

        buffer[BUFFER_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[i--] = map_to[num % 16];
                num /= 16;
        }

        if ((fmt->flags & F_HASH) && init_num != 0)
        {
                buffer[i--] = flag_ch;
                buffer[i--] = '0';
        }

        i++;

        return (write_unsigned(fmt, i, buffer, buf_idx));
}

