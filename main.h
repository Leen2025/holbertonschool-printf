#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* Buffer size for output */
#define BUFFER_SIZE 1024

/* Flag macros */
#define F_MINUS 1  /* Left-align */
#define F_PLUS 2   /* Show sign */
#define F_ZERO 4   /* Zero padding */
#define F_HASH 8   /* Alternate form */
#define F_SPACE 16 /* Space if no sign */

/* Size macros */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt_info - Format information structure
 * @flags: Format flags (-+0# )
 * @width: Field width
 * @precision: Precision
 * @size: Size modifier (l, h)
 * @specifier: Format specifier character
 */
typedef struct fmt_info
{
	int flags;
	int width;
	int precision;
	int size;
	char specifier;
} fmt_info_t;

/**
 * struct fmt_handler - Format handler structure
 * @specifier: Format specifier character
 * @handler: Function to handle the specifier
 */
typedef struct fmt_handler
{
	char specifier;
	int (*handler)(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
} fmt_handler_t;

/* Forward declaration of write_num function */
int write_num(fmt_info_t *fmt, int ind, char buffer[], int length, char padd, char extra_c);

/* Main printf function */
int _printf(const char *format, ...);

/* Buffer handling functions */
void init_buffer(char buffer[]);
void flush_buffer(char buffer[], int *buf_idx);

/* Format parsing functions */
int parse_format(const char *format, int i, fmt_info_t *fmt, va_list args);
int get_flags(const char *format, int i, fmt_info_t *fmt);
int get_width(const char *format, int i, fmt_info_t *fmt, va_list args);
int get_precision(const char *format, int i, fmt_info_t *fmt, va_list args);
int get_size(const char *format, int i, fmt_info_t *fmt);

/* Format handler selector */
int handle_format(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_unknown(fmt_info_t *fmt, char buffer[], int *buf_idx);

/* Character and string handlers */
int handle_char(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_string(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_percent(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);

/* Numeric handlers */
int handle_int(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_binary(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);

/* Unsigned numeric handlers */
int handle_unsigned(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_octal(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_hex_lower(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_hex_upper(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_hex(fmt_info_t *fmt, va_list args, char map_to[], char buffer[], int *buf_idx);

/* Custom handlers */
int handle_pointer(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_non_printable(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_reverse(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_rot13(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);

/* Write utilities */
int write_char(fmt_info_t *fmt, char c, char buffer[], int *buf_idx);
int write_number(fmt_info_t *fmt, int is_negative, int ind, char buffer[], int *buf_idx);
int write_unsigned(fmt_info_t *fmt, int ind, char buffer[], int *buf_idx);
int write_pointer(fmt_info_t *fmt, char buffer[], int ind, int length, int *buf_idx);

/* Character utilities */
int is_printable(char c);
int append_hexa_code(char c, char buffer[], int i);
int is_digit(char c);

/* Numeric utilities */
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */

