#include "main.h"
#define PRINTF_STATE_NORMAL 0
#define PRINT_STATE_LENGTH 1
int _printf(const char *format, ...)
{
	int* argp = (int)&format;
	int state = PRINTF_STATE_NORMAL;

	argp++;
	while(*format)
	{
		format++;

	}
}
