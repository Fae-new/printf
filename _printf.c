#include "main.h"

int _printf(const char *format, ...)
{

	int count = 0;

	va_list args;
	va_start(args, format);



if (format == NULL)
return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format != 'c' && *format != 's' && *format != 'd' && *format != 'i' && *format != '%')
			{
				return (-1);
			}

			if (*format == 'c')
			{
				char ch = va_arg(args, int);
				write(STDOUT_FILENO, &ch, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;
				while (str[len] != '\0')
				{
					len++;
				}
				write(STDOUT_FILENO, str, len);
				count += len;
			}

			else if (*format == '%')
			{
				write(STDOUT_FILENO, "%", 1);
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

