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
#### Tasks required for this project


------------

0. ###### I am not going anywhere. You can print that wherever you want to. I'm here and I am a Spur for life1.  I am not going anywhere. You can print that wherever you want to. I'm here and I am a Spur for life. 
Write a function that produces output according to a format.
Handle the following conversion specifiers:
- c
- s
- %

1. ###### Education is when you read the fine print. Experience is what you get if you dont
Handle the following conversion specifiers:
- d
- i

2. ###### Just because its in print doesn't mean its the gospel
Create a man page for the function

3. ###### With a face like mine, I do better in print
Handle the following conversion specifiers:
- b

4. ###### What one has not experienced, one will never understand in print
Handle the following conversion specifiers:
- u
- x
- o
- x
- X

5. ###### Nothing in fine print is ever good news
Use a local buffer of 1024 chars in order to call write as little as possible.

6. ###### Handle the following custom conversion specifier
- S : prints the string.
- Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters).

7. ###### How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print
Handle the following conversion specifier: p

8. ###### The big print gives and the small print takes away
Handle the following flag characters for non-custom conversion specifiers:
- ´+´
- space
- ´#´ 

9. ###### Sarcasm is lost in print
Handle the following length modifiers for non-custom conversion specifiers:
- l
- h
Conversion specifiers to handle: d, i, u, o, x, X

10. ###### Print some money and give it to us for the rain forests
Handle the field width for non-custom conversion specifiers.

11. ###### The negative is the equivalent of the composer's score, and the print the performance
Handle the precision for non-custom conversion specifiers.

12. ###### It's depressing when you're still around and your albums are out of print
Handle the 0 flag character for non-custom conversion specifiers.

13. ###### Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection
Handle the - flag character for non-custom conversion specifiers.

14. ###### Print is the sharpest and the strongest weapon of our party
Handle the following custom conversion specifier:
 - r : prints the reversed string

15. ###### The flood of print has turned reading into a process of gulping rather than savoring 
Handle the following custom conversion specifier:
- R: prints the rot13'ed string

16. ###### *
All the above options work well together.
## Functions we use.

````c
int _putchar(char c); /*writes the character c to stdout */
int _printf(const char *format, ...);/* function that produces output according to a format.*/
int print_char(va_list c);/*writes the character c to stdout */
int print_string(va_list s);/*writes the character c to stdout */
int print_int(va_list i);/*function that prints an integer */
int print_dec(va_list d);/* function that prints an decimal*/
````
## Usage

- All the files are to be compiled on Ubuntu 22.04 Compile your code with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c` Include the "main.h" header file on the functions using the `_printf()`.


- If you have a test file (e.g., `main.c`), compile and run it as follows:



```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o _printf
./_printf

```

---

## Example (main.c)

```
#include "main.h"

int main(void)
{
    _printf("Character: %c\nString: %s\nPercent: %%\n", 'A', "Hello");
    _printf("Integer: %d\n", 123);
    _printf("Binary: %b\n", 98);
    _printf("Unsigned: %u\n", 300);
    _printf("Octal: %o\n", 100);
    _printf("Hexadecimal: %x\n", 255);
    _printf("Pointer: %p\n", (void *)main);
    _printf("Non-printable: %S\n", "Best\nSchool");
    _printf("Reversed: %r\n", "Hello");
    _printf("ROT13: %R\n", "Hello");
    return (0);
}
```

---
## Example:

```
_printf("Character: %c, String: %s, Number: %d\n", 'A', "Hello", 123);
```

---

## EXAMPLES

### Basic Output:

```
_printf("Hello, World!\n");
```

### Output:

```
Hello, World!
```

### Multiple Conversion Specifiers:

```
_printf("Name: %s, Age: %d, Grade: %c\n", "Alice", 20, 'A');
```

### Output:

```
Name: Alice, Age: 20, Grade: A
```

### Custom Specifiers:

```
_printf("Binary: %b\n", 98);             // Output: 1100010
_printf("Non-printable: %S\n", "Best\nSchool");  // Output: Best\x0ASchool
_printf("Reversed: %r\n", "Hello");        // Output: olleH
_printf("ROT13: %R\n", "Hello");           // Output: Uryyb
```

---

## FUNCTIONS AND PROTOTYPES

- Below is an overview of key functions and their purposes. (Adjust function names if your implementation differs.)

`_printf`

```
int _printf(const char *format, ...);
```

- Purpose: Main entry point; parses the format string and processes conversion specifiers.

- Return Value: Total number of characters printed, or a negative value on error.

---

## Helper Functions for Conversion Specifiers:

- `int print_char(va_list args); – Handles %c`.

- `int print_string(va_list args); – Handles %s`.

- `int print_int(va_list args); – Handles %d and %i`.

- `int print_unsigned(va_list args); – Handles %u`.

- `int print_octal(va_list args); – Handles %o`.

- `int print_hex(va_list args); – Handles %x`.

- `int print_HEX(va_list args); – Handles %X`.

- `int print_binary(va_list args); – Handles %b`.

- `int print_pointer(va_list args); – Handles %p`.

- `int print_S(va_list args); – Handles %S (non-printable characters)`.

- `int print_reverse(va_list args); – Handles %r (reversed string)`.

- `int print_ROT13(va_list args); – Handles %R (ROT13 encoding)`.


### Formatting Helpers:

- Functions such as handle_flags, handle_width, handle_precision, etc., manage flags, field width, precision, and length modifiers.

---

## MAN PAGE

- A manual page for the `_printf` function is provided in the file `man_3_printf`. To view it locally:

```
man ./man_3_printf
```

---

## BUGS
- No known bugs at the moment. Please report any bugs or issues using the project repository.

---

## SEE ALSO

`man_3_printf`

---

## AUTHORS

- Leen Al-saleh

- bader Al-Amri

