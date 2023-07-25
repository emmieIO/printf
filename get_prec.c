#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

if (format[curr_i] != '.')
return precision;

precision = 0;
curr_i++;

while (format[curr_i] != '\0')
{
if (isdigit(format[curr_i]))
{
precision = precision * 10 + (format[curr_i] - '0');
curr_i++;
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
{
break;
}
}

*i = curr_i - 1;
return precision;
}
}
