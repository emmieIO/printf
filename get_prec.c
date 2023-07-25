#include "main.h"
#include <stdbool.h>

/**
 * get_precision - Calculates the precision for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

if (format == NULL || format[curr_i] != '.')
return (precision);

curr_i++; // Move to the character after '.'.

if (format[curr_i] == '*')
{
curr_i++; // Mov
precision = va_arg(list, int);
}
else if (isdigit(format[curr_i]))
{
precision = 0;
while (isdigit(format[curr_i]))
{
precision = precision * 10 + (format[curr_i] - '0');
curr_i++;
}
}

*i = curr_i - 1;
return (precision);
}
