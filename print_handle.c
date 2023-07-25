#include "main.h"
#include "main.h"
#include <stdbool.h>
#include <ctype.h>

typedef struct fmt_s {
char fmt;
int (*fn)(va_list, char*, int, int, int, int);
} fmt_t;

bool is_valid_format_specifier(const char *format);

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int i, unknow_len = 0, printed_chars = -1;

fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};

for (i = 0; fmt_types[i].fmt != '\0'; i++)
{
if (fmt[*ind] == fmt_types[i].fmt)
{
// Check if the format specifier is valid before processing.
if (!is_valid_format_specifier(&fmt[*ind]))
{
// Treat invalid format specifier as a regular character.
unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}

// If the format specifier requires precision and none is provided, get it from the format string.
if (fmt[*ind] != '%' && precision == -1)
precision = get_precision(fmt, ind, list);

return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
}
}

// If the format specifier is not recognized, treat it as an unknown specifier.
if (fmt_types[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);

unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}

return (printed_chars);
}




/**
 * is_valid_format_specifier - Checks the validity of a format specifier.
 * @format: Formatted string containing the format specifier.
 *
 * Return: true if the format specifier is valid, false otherwise.
 */
bool is_valid_format_specifier(const char *format)
{

if (format == NULL || format[0] != '%')
return (false);

int i = 1;

while (format[i] == '-' || format[i] == '+' || format[i] == '0' ||
format[i] == ' ' || format[i] == '#')
{
i++;
}

if (isdigit(format[i]))
{
while (isdigit(format[i]))
{
i++;
}
}


if (format[i] == '.')
{
i++; 

if (format[i] == '*')
{
i++;
}
else if (isdigit(format[i]))
{
while (isdigit(format[i]))
{
i++;
}
}
}

if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
{
i++;
}


if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' ||
format[i] == 'd' || format[i] == 'i' || format[i] == 'o' ||
format[i] == 'u' || format[i] == 'x' || format[i] == 'X' ||
format[i] == 'f' || format[i] == 'e' || format[i] == 'E' ||
format[i] == 'g' || format[i] == 'G' || format[i] == 'n')
{
if (format[i + 1] == '\0')
return (true);
}

return (false);
}

