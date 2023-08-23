#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 *
 * Description: _putchar uses a local buffer of 1024 to minimize write calls.
 */
int _putchar(char c)
{
    static char buf[1024];
    static int i;

    if (c == -1 || i >= 1024)
    {
        write(1, &buf, i);
        i = 0;
    }
    if (c != -1)
    {
        buf[i] = c;
        i++;
    }
    return (1);
}

/**
 * _puts - Writes a string to the standard output.
 * @str: Pointer to the string to be written.
 *
 * Return: The number of characters written.
 */
int _puts(char *str)
{
    register int i;

    for (i = 0; str[i] != '\0'; i++)
        _putchar(str[i]);
    return (i);
}

