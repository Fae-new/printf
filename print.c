#include "main.h"

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
 *         Returns -1 if format is NULL or an invalid format specifier is found.
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
            {
                char *string = va_arg(args, char *);
                count += printstr(string);
            }

            else if (*format == '%')
            {
                write(STDOUT_FILENO, "%", 1);
                count++;
            }

            else if (*format == 'd' || *format == 'i')
            {

                int num = va_arg(args, int);
                char *str = int_to_string(num);
                if (str != NULL)
                {
                    count += printstr(str);
                    free(str);
                }
                else
                {
                    return (-1);
                }
            }
            else if (*format == 'b') 
                {
        unsigned int num = va_arg(args, unsigned int);
        print_binary(num);
        count += sizeof(unsigned int) * 8; // Count the number of binary digits
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
