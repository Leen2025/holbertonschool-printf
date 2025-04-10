# printf

### Description

------------


The printf function sends formatted output to stdout.
A custom _printf() for learning purposes was developed by cohort  #26 students Leen and Bader.
_printf() function format string is a character string, beginning and ending in its initial shift state, if any. 
These arguments are placed using the percentage '%' operator

```` c
int printf ( const char * format, ... );
````
This is the first group project that we have at Holberton School, which consists of replicating the **[printf (3)](http://man7.org/linux/man-pages/man3/printf.3.html)** function of language c, calling it this way **_printf.**

This function is part of the standard library **<cstdio>** and to use it we must specify the header file **<stdio.h>**.

Writes the C string pointed by format to the standard output **(stdout)**. If format includes format specifiers (subsequences beginning with **%**), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.

------------
### Parameters
 > **format** -> C string that contains the text to be written to stdout.
 
Where the specifier character at the end is the most significant component, since it defines the type and the interpretation of its corresponding argument:
 Specifier | Output | Example
------------ | ------------- |-----------
 c | Character | A
 s | String of characters | Holberton
 % | A % followed by another % character will write a single % to the stream| %
  i and d | Signed decimal integer | 98 
 b | Unsigned binary | 10101
 u | Unsigned decimal integer | 98
 o | Unsigned octal | 5523
 x | Unsigned hexadecimal integer (lowercase) | 36264eb
 X | Unsigned hexadecimal integer (uppercase) | 36264EB
 r | Reversed string | gnirts |
 R | Rot13 string | cevags
##### Return Value.
On **success**, the **total number** of characters written is returned.
If a writing error occurs, the error indicator (ferror) is set and a negative number is returned.
###### Flags (In development...)

|Flag                |Description                        |
|----------------|-------------------------------|
| `-` |Left-justify the output within the field width that was given; Right justification is the default (see _width_ sub-specifier). |
| `+` |Preceeds the result with a plus or minus sign (`+` or `-`) even for positive numbers. By default, only negative numbers are preceded with a `-` sign. |
| `(space)` |If no sign is going to be written, a blank space is inserted before the value. |
| `#` |Used with `o`, `x` or `X` specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. |
| `0` |Left-pads the number with zeroes (`0`) instead of spaces when padding is specified (see _width_ sub-specifier). |

###### Width (In development...)

|Width                |Description                        |
|----------------|-------------------------------|
| `(number)` |Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
| `*` | The _width_ is not specified in the _format_ string, but as an additional integer value argument preceding the argument that has to be formatted.|

### Precision (In development...)

|.Precision               |Description                        |
|----------------|-------------------------------|
| `.(number)` |**For integer specifiers (`d`, `i`, `o`, `u`, `x`, `X`):** _precision_ specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A _precision_ of 0 means that no character is written for the value 0. **For `s`**: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for _precision_, 0 is assumed. |

### Lenght modifiers (In development...)

|Modifier/Specifier  |`d` & `i`  |`u`, `o`, `x`, `X` |`c` |`s` |`p` |
|----------------|---------|------------|-------------|-----|-------|
| `none` | int |unsigned int | int| char pointer| void pointer |
| `h` |short int|unsigned short int |     |     |              |
| `l` |long int |unsigned long int  |     |     |              |

------------

#### Files contained in this repository


------------

|Name                |Information                        |Relevant Files                         |
|----------------|-------------------------------|-----------------------------|
|`man_3_printf`|Man page of the _printf() function.| `None` |
|`holberton.h`	| Header file with the data type struct, standard libraries and custom prototypes.| `*.c compilation` |
|`_printf.c`|Main printf function file. Calls other functions.|`printf_(name of var).c file` |
|`printf_37.c`|Contains percentage print function.|`None` |
|`printf_int.c` | Contains decimal and integer functions. | `None` | 
`printf_char.c` | Custom function for char data type. | `None`
|`printf_sting.c` | Function that calls string type variable. | `None` |
|`printf_bin.c` | Function that gets the binary | `None` |
`printf_oct.c` | Functions that returns octal number. | `None` |
`printf_hex.c` | Calls hexadecimal numbers (lowercase). | `None` | 
`printf_HEX.c` | Calls hexadecimal numbers (Uppercase). | `None` |
`printf_unsigned.c` | Returns an unisgined data type. | `None` |
`printf_hex_aux.c` | Auxiliar function for hexadecimal specific functions (lowercase). | `printf_exclusive_string.c` | 
`printf_HEX_aux.c` | Auxiliar function hexadecimal specific functions (Uppercase). | `printf_p.c` |
`printf_exclusive_string.c` | Returns a string and non readable characters are printed in hexadecimal numbers (Lowercase). | `printf_hex_aux.c` |
`printf_srev.c` | Returns a string in reverse. | `None` |
`printf_rot13.c` | Returns a string in Rot13. | `None` |
`printf_str.c` | Auxiliar functions such as strlen and strcpy. | `None` |
`_putchar.c` | Custom putchar function. | `None` |


------------
 
