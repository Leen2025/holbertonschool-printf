
# C - Custom printf Implementation

## Project Overview
The `_printf` function is a custom-built implementation of the standard C `printf` function. It processes format strings combined with a variable number of arguments to generate formatted output. This project provides an opportunity to explore variadic functions, buffer management, and formatted output handling in C.

## Features & Supported Specifiers

### Basic Output
- Print a **character** using `%c`.
- Print a **string** using `%s`.
- Print a **percent symbol** using `%%`.

### Integer Formatting
- Print **signed integers** using `%d` and `%i`.

### Unsigned Integer Formatting
- Print **unsigned integers** using `%u`.
- Print **octal representation** using `%o`.
- Print **hexadecimal representation** using `%x` (lowercase) and `%X` (uppercase).

### Custom Conversion Specifiers
- Print **binary representation** using `%b`.
- Print **strings with special handling for non-printable characters** using `%S`.
- Print a **reversed string** using `%r`.
- Print a **ROT13-encoded string** using `%R`.

### Pointer Representation
- Print a **memory address** using `%p`.

## Advanced Formatting Options

### Flag Support
- `+` Forces explicit signs on signed numbers.
- Space (` `) Inserts a leading space for positive numbers when no sign is specified.
- `#`  Alternative formatting for octal and hexadecimal outputs.

### Field Width & Precision
- Controls the **minimum number of characters** printed for numbers and strings.
- Allows **precise control** over numerical and string formatting.

### Length Modifiers
- `l`  Used for `long` integers.
- `h`  Used for `short` integers.

### Buffer Optimization
- Uses a **1024-character buffer** to optimize write calls and reduce overhead.

## Return Value
- On **success**, `_printf` returns the **total number of characters printed** (excluding the null terminator).
- On **failure**, it returns a **negative value**.

## Usage & Compilation

### Compilation Instructions
The project is compiled on **Ubuntu 22.04** using `gcc` with the following flags:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o _printf
```

- main.h header file is included in all function implementations

##Running a Test File

test file main.c compile and execute it as follows:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o _printf
./_printf

```


## Example Usage (main.c)
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


## Function Prototype
```
int _printf(const char *format, ...);
```

## Example Usage
```
_printf("Character: %c, String: %s, Number: %d\n", 'A', "Hello", 123);
```
## Output Examples
- Basic Example:
```
_printf("Hello, World!\n");

the output :
Hello, World!
```

- Multiple Specifiers:

```
_printf("Name: %s, Age: %d, Grade: %c\n", "Alice", 20, 'A');

the output:
Name: Alice, Age: 20, Grade: A
```


## Custom Specifiers:

```
_printf("Binary: %b\n", 98);  
Output: 1100010
_printf("Non-printable: %S\n", "Best\nSchool"); 
 Output: Best\x0ASchool
_printf("Reversed: %r\n", "Hello");  
 Output: olleH
_printf("ROT13: %R\n", "Hello");  
Output: Uryyb
```


## Core Functions & Helpers

```
int _printf(const char *format, ...);
```

- Purpose: Parses the format string and processes each conversion specifier.

- Return Value: Number of characters printed, or -1 on error.

## Helper Functions for Conversion Specifiers

```
int print_char(va_list args); -> Handles %c.

int print_string(va_list args); -> Handles %s.

int print_int(va_list args);  -> Handles %d and %i.

int print_unsigned(va_list args); -> Handles %u.

int print_octal(va_list args); -> Handles %o.

int print_hex(va_list args); -> Handles %x.

int print_HEX(va_list args); -> Handles %X.

int print_binary(va_list args); -> Handles %b.

int print_pointer(va_list args); -> Handles %p.

int print_S(va_list args); -> Handles %S (non-printable characters).

int print_reverse(va_list args); -> Handles %r (reversed string).

int print_ROT13(va_list args); -> Handles %R (ROT13 encoding).
```

## Man Page
-A manual page for _printf is available in man_3_printf. To view it locally:

```
man ./man_3_printf
```

## Known Issues

-No known bugs at the moment.

-Report issues via the project reposit

## References & Related Commands
```
man 3 printf
```

## Authors
- Bader Al-Amri
```
10670@holbertonstudents.com
```

- Leen Al-Saleh
```
10691@holbertonstudents.com
```
