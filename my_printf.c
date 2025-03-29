#include "main.h"
/**
* _printf - Produces output according to a format string
* @format: Character string containing format directives
* Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
int i, printed_chars = 0;
int buf_idx = 0;
int printed;
va_list args;
char buffer[1024];
fmt_info_t fmt = {0};
if (format == NULL)
return (-1);
va_start(args, format);
init_buffer(buffer);
/* Initialize format info structure */
fmt.flags = 0;
fmt.width = 0;
fmt.precision = -1;
fmt.size = 0;
fmt.specifier = 0;
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buf_idx++] = format[i];
if (buf_idx == 1024)
flush_buffer(buffer, &buf_idx);
printed_chars++;
}
else
{
flush_buffer(buffer, &buf_idx);
i = parse_format(format, i + 1, &fmt, args);
if (i == -1)
return (-1);
printed = handle_format(&fmt, args, buffer, &buf_idx);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
flush_buffer(buffer, &buf_idx);
va_end(args);
return (printed_chars);
}
