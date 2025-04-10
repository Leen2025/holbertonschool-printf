#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;
/**
 * description: C statements as a pre-processor directive.
 * LOWX - WIP
 * UPX - WIP
 * BUFFERSIZE - local buffer of 1024 chars in order to call write alap
 * TRUE - boolean flag for non-custom specifiers
 * FALSE - boolean flag for non-custom specifiers
 */

#define BUFFERSIZE 1024
#define TRUE (1 == 1)
#define FALSE !TRUE

/**
 * struct stackvar - struct for required custom conversion specifiers
 * @char1: type char for buffer allocation
 * @char2: type char for validate n after %
 * @char3: type char for validate n n after %
 * @char4: type char for non custom specifiers
 * @error: type int replaces stdbool.h
 * @flag: type int for conversion specifiers flags
 * @space: type int for space printing
 * @counter: type int for counter between index arrays
 * @counter_b: type int for counter between buffer and char
 * @buffer: type char pointer to buffer
 * @format: type char pointer to format str
 * @arguments: arguments stacked in va_list
 * @i: type int that goes over str
 */
typedef struct stackvar
{
	int i;
	char char1;
	char char2;
	char char3;
	char char4;
	int error;
	int flag;
	int space;
	int counter;
	int counter_b;
	char *buffer;
	const char *format;
	va_list *arguments;
} stackvar;

/**
 * struct convert_max_l_h - match the conversion specifiers for non custom
 * @s: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @func: type pointer to function for the conversion specifier
 *
 */

typedef struct convert_max_l_h
{
	char s;
	void (*func)(stackvar *stack);
} convert_max_l_h;
int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_bin(va_list val);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int printf_37(void);
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
