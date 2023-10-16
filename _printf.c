#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0; 

	if( format == NULL)
	{
	return (-1);
	}
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; 
			if (*format == 'c')
			{
				char ch = va_arg(args, int); 
				write(STDOUT_FILENO, &ch, 1);
				count++;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);

	return count;
}
