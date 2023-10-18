#include "main.h"

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
 *         Returns -1 if format is NULL or an invalid format specifier is found.
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
