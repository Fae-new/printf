#include "main.h"
/**
 * int_to_string - Converts an integer to a dynamically allocated string.
 * @num: The integer to be converted.
 *
 * Return: A pointer to the newly allocated string containing the integer.
 *         NULL if memory allocation fails.
 */

char *int_to_string(int num)
{
    int i = 0;
    int originalNum = num;

    while (num > 0)
    {
        num /= 10;
        i++;
    }

    num = originalNum;

    char *revertedstr = malloc(i + 1);
    char *str = malloc(i + 1);

    if (revertedstr == NULL || str == NULL)
    {
        return NULL;
    }

    int length = i - 1;

    while (num > 0)
    {
        int a = num % 10;
        revertedstr[length--] = a + '0';
        num /= 10;
    }

    int rev = 0;

    while (length < i - 1)
    {
        str[rev++] = revertedstr[++length];
    }

    str[rev] = '\0';

    free(revertedstr);

    return str;
}
