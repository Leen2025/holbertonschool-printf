#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int print_number(int num);
int print_binary(unsigned int n);
#endif
