#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(char *n, ...)
{
	va_list ap;
	va_start(ap, n);
	unsigned i = 0;
	char *start = n;

	while (*n != '\0')
	{
		i++;
		n++;
	}
	n = start;

	while (*n != '\0')
	{

		if (*n == '%' && *(n + 1) == 's')
		{
			int s = 0;

			char *str = va_arg(ap, char *);
			char *strstart = str;

			while (*str != '\0')
			{
				s++;
				str++;
			}
			str = strstart;
			write(STDOUT_FILENO, str, s);
			n += 2;
		}

		if (*n == '%' && *(n + 1) == 'c')
		{

			int cha = va_arg(ap, int);
			write(STDOUT_FILENO, &cha, 1);
			n += 2;
		}

		write(STDOUT_FILENO, n, 1);
		n++;
	}

	va_end(ap);

	return (i);
}
