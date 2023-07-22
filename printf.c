#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
    va_start(args, format);

	int count = 0;

	
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			
		}

		
		format++;

	}
}
