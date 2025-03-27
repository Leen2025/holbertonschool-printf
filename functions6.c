#include "main.h"
int print_pointer(void *ptr)
{
	int count = 0;
	unsigned long int address;
	if ( ptr == NULL)
		return(print_string("(null)");
				address = (unsigned long int) ptr;
				count += _putchar('0');
				count += _putchar('x');
				count += print_hex_lower(address);
				return (count);
				}
