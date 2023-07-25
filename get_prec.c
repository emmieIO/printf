#include <stdbool.h>

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: (Precision).
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;
char curr_char = format[curr_i];

if (curr_char != '.')
return (precision);

precision = 0;
curr_i++; /* Move past the '.' character. */

/* Check for '*' or numeric value: Get precision from the format string. */
curr_char = format[curr_i];
if (curr_char == '*')
{
curr_i++; /* Move past the '*' character. */
precision = va_arg(list, int);
}
else if (isdigit(curr_char))
{
while (isdigit(curr_char))
{
precision = precision * 10 + (curr_char - '0');
curr_i++;
curr_char = format[curr_i];
}
}

*i = curr_i - 1;

return (precision);
}

