#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
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
int write_num(fmt_info_t *fmt, int ind, char buffer[],
		int length, char padd, char extra_c);
int _printf(const char *format, ...);
void init_buffer(char buffer[]);
void flush_buffer(char buffer[], int *buf_idx);
int parse_format(const char *format, int i, fmt_info_t *fmt, va_list args);
int get_flags(const char *format, int i, fmt_info_t *fmt);
int get_width(const char *format, int i, fmt_info_t *fmt, va_list args);
int get_precision(const char *format, int i, fmt_info_t *fmt, va_list args);
int get_size(const char *format, int i, fmt_info_t *fmt);
int handle_format(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_unknown(fmt_info_t *fmt, char buffer[], int *buf_idx);
int handle_char(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_string(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_percent(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_int(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_binary(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_unsigned(fmt_info_t *fmt, va_list args,
		char buffer[], int *buf_idx);
int handle_octal(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_hex_lower(fmt_info_t *fmt, va_list args,
		char buffer[], int *buf_idx);
int handle_hex_upper(fmt_info_t *fmt,
		va_list args, char buffer[], int *buf_idx);
int handle_hex(fmt_info_t *fmt, va_list args,
		char map_to[], char buffer[], int *buf_idx);
int handle_pointer(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_nonprint(fmt_info_t *fmt, va_list args,
		char buffer[], int *buf_idx);
int handle_reverse(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int handle_rot13(fmt_info_t *fmt, va_list args, char buffer[], int *buf_idx);
int write_char(fmt_info_t *fmt, char c, char buffer[], int *buf_idx);
int write_number(fmt_info_t *fmt, int is_negative,
		int ind, char buffer[], int *buf_idx);
int write_unsigned(fmt_info_t *fmt, int ind, char buffer[], int *buf_idx);
int write_pointer(fmt_info_t *fmt, char buffer[],
		int ind, int length, int *buf_idx);
int is_printable(char c);
int append_hexa_code(char c, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);
int flush_buffer(char buffer[], int *buf_idx);
unsigned int convert_size_unsigned(unsigned int num, int size);
int write_unsigned(fmt_info_t *fmt, int index, char buffer[], int *buf_idx);

#endif /* MAIN_H */

