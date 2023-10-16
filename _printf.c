#include "main.h"



/**
 * printstr - Prints a string to the standard output
 * @args: A va_list containing the string to be printed
 *
 * Description: This function takes a va_list as an argument,
 * interprets it as a string, and prints the string to the standard output.
 *
 * Return: The number of characters printed (excluding the null byte).
 *         Returns 0 if the va_list does not contain a valid string.
 */



int printstr(va_list args)
{
	int count = 0;

	char *str = va_arg(args, char *);

	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(STDOUT_FILENO, str, len);
	count += len;
	return (count);
}

/**
 * print - Prints formatted data to the standard output using a va_list
 * @format: A pointer to a format string containing format specifiers
 * @args: A va_list containing the arguments to be formatted and printed
 *
 * Description: This function takes a format string with format specifiers
 * and a va_list of arguments. It interprets the format specifiers and prints
 * the formatted output to the standard output.
 *
 * Return: The number of characters printed (excluding the null byte).
 *  Returns -1 if format is NULL or an invalid format specifier is found.
 */


int print(const char *format, va_list args)
{
	int count = 0;

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
			else if (*format == 's')
				count += printstr(args);

			else if (*format == '%')
			{
				write(STDOUT_FILENO, "%", 1);
				count++;
			}
			else
				return (-1);
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		format++;
	}

	return (count);
}

/**
 * _printf - Prints formatted data to the standard output
 * @format: A pointer to a format string containing format specifiers
 * @...: Additional arguments corresponding to the format specifiers
 *
 * Description: This function takes a format string with format specifiers
 * and a variable number of arguments. It interprets the format specifiers and
 * prints the formatted output to the standard output.
 *
 * Return: The number of characters printed (excluding the null byte).
 *   Returns -1 if format is NULL or an invalid format specifier is found.
 */


int _printf(const char *format, ...)
{
	int count;

	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	count = print(format, args);

	va_end(args);

	return (count);
}
