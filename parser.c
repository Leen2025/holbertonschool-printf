#include "main.h"

/**
 * parse_format - Parse format specifier and extract formatting information
 * @format: Format string
 * @i: Current position in format string
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 *
 * Return: Updated position in format string, or -1 on error
 */
int parse_format(const char *format, int i, fmt_info_t *fmt, va_list args)
{
	int j = i;

	/* Reset format information */
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->size = 0;
	fmt->specifier = 0;

	/* Parse flags */
	j = get_flags(format, j, fmt);
	if (format[j] == '\0')
		return (-1);

	/* Parse width */
	j = get_width(format, j, fmt, args);
	if (format[j] == '\0')
		return (-1);

	/* Parse precision */
	j = get_precision(format, j, fmt, args);
	if (format[j] == '\0')
		return (-1);

	/* Parse size */
	j = get_size(format, j, fmt);
	if (format[j] == '\0')
		return (-1);

	/* Get specifier */
	fmt->specifier = format[j];

	return (j);
}

/**
 * get_flags - Extract flags from format string
 * @format: Format string
 * @i: Current position in format string
 * @fmt: Pointer to format information structure
 *
 * Return: Updated position in format string
 */
int get_flags(const char *format, int i, fmt_info_t *fmt)
{
	int j, curr_i;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = i; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				fmt->flags |= FLAGS_ARR[j];
				break;
			}
		}

		if (FLAGS_CH[j] == 0)
			break;
	}

	return (curr_i);
}

/**
 * get_width - Extract width from format string
 * @format: Format string
 * @i: Current position in format string
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 *
 * Return: Updated position in format string
 */
int get_width(const char *format, int i, fmt_info_t *fmt, va_list args)
{
	int curr_i;

	for (curr_i = i; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			fmt->width *= 10;
			fmt->width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			fmt->width = va_arg(args, int);
			if (fmt->width < 0)
			{
				fmt->flags |= F_MINUS;
				fmt->width = -fmt->width;
			}
			break;
		}
		else
		{
			break;
		}
	}

	return (curr_i);
}

/**
 * get_precision - Extract precision from format string
 * @format: Format string
 * @i: Current position in format string
 * @fmt: Pointer to format information structure
 * @args: Variable arguments list
 *
 * Return: Updated position in format string
 */
int get_precision(const char *format, int i, fmt_info_t *fmt, va_list args)
{
	int curr_i = i;

	if (format[curr_i] != '.')
		return (curr_i);

	fmt->precision = 0;
	curr_i++;

	for (; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			fmt->precision *= 10;
			fmt->precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			fmt->precision = va_arg(args, int);
			if (fmt->precision < 0)
				fmt->precision = -1;
			break;
		}
		else
		{
			break;
		}
	}

	return (curr_i);
}

/**
 * get_size - Extract size modifier from format string
 * @format: Format string
 * @i: Current position in format string
 * @fmt: Pointer to format information structure
 *
 * Return: Updated position in format string
 */
int get_size(const char *format, int i, fmt_info_t *fmt)
{
	int curr_i = i;

	if (format[curr_i] == 'l')
		fmt->size = S_LONG;
	else if (format[curr_i] == 'h')
		fmt->size = S_SHORT;
	else
		return (curr_i);

	return (curr_i + 1);
}

