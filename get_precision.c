#include "main.h"
#include <ctype.h>

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string.
 * @list: List of arguments to be printed.
 *
 * Return: Precision value or -1 if not specified or invalid.
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

if (format[curr_i] != '.')
return precision;

precision = 0;
curr_i++;

if (isdigit(format[curr_i])) {
while (isdigit(format[curr_i])) {
precision = precision * 10 + (format[curr_i] - '0');
curr_i++;
}
} else if (format[curr_i] == '*') {
curr_i++;
precision = va_arg(list, int);
} else {
// If there is a dot without a numeric value or wildcard, consider precision as 0.
precision = 0;
}

*i = curr_i - 1;
return precision;
}