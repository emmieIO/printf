#include "main.h"

/**
 * get_precision - Extracts the precision value from the format string.
 * @format: The format string.
 * @i: Pointer to the current position in the format string.
 * @list: The va_list containing the variable arguments.
 *
 * Return: (precision) for valid conversion specifiers, (-1) for unsupported specifiers.
 */
int get_precision(const char *format, int *i, va_list list)
{
int precision = -1; /* Default precision value (unset) */

/* Check if the precision is specified in the format string */
if (format[*i] == '.')
{
*i += 1; /* Move to the next character after '.' */

/* Parse the precision value from the format string */
precision = 0;
while (format[*i] >= '0' && format[*i] <= '9')
{
precision = precision * 10 + (format[*i] - '0');
*i += 1;
}
}

/* Check the conversion specifier to determine if it's a numeric value or a string */
char conversion = format[*i];
if (conversion == 'd' || conversion == 'i' || conversion == 'o' ||
conversion == 'u' || conversion == 'x' || conversion == 'X' ||
conversion == 'f' || conversion == 'F' || conversion == 'e' ||
conversion == 'E' || conversion == 'g' || conversion == 'G' ||
conversion == 'a' || conversion == 'A' || conversion == 'c' ||
conversion == 's' || conversion == 'p' || conversion == 'n')
{
/* If the conversion specifier is valid for precision, return the precision value */
return (precision);
}

/* For unsupported conversion specifiers, precision is ignored */
return (-1);
}