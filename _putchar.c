#include <unistd.h>

/**
 * _putchar - Custom function to print a character to stdout
 * @c: The character to be printed
 *
 * Return: On success, returns the character
 * written as an unsigned char cast to an int.
 * On error, returns -1.
 */
int _putchar(char c)
{
return (write(STDOUT_FILENO, &c, 1));
}
