#include "main.h"
#include <ctype.h>

/**
 * get_precision - Calculates the precision for printing.
 * @format: Formatted string in which to print the arguments.
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
{
return (precision);
}

precision = 0;
curr_i++;

if (isdigit(format[curr_i]))
{
while (isdigit(format[curr_i]))
{
precision = precision * 10 + (format[curr_i] - '0');
curr_i++;
}
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
}

*i = curr_i - 1;
 
if (precision == -1)
{
switch (format[curr_i])
{
case 'd':
case 'i':
case 'o':
case 'u':
case 'x':
case 'X':
case 'f':
case 'e':
case 'E':
case 'g':
case 'G':
case 'a':
case 'A':
case 'c':
case 's':
case 'p':
precision = 0;
break;
default:
break;
}
}

return (precision);
}
