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

int printstr(char *str)
{

    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    write(STDOUT_FILENO, str, len);

    return (len);
}
