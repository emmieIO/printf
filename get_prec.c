#include "main.h"
#include <ctype.h>

/**
 * get_precision - Extracts the precision value from the format string.
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 * @list: List of arguments.
 *
 * Return: (Precision value).
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

if (format[curr_i] != '.')
return (precision);

precision = 0;
curr_i++; /* Move to the character after '.'. */

/* Extract the precision value using a while loop. */
while (isdigit(format[curr_i]))
{
precision = precision * 10 + (format[curr_i] - '0');
curr_i++;
}

*i = curr_i - 1;
return (precision);
}

